#include "stacking.h"

Stacking::Stacking(QObject *parent) : QObject(parent)
{

}
void Stacking::processStarted()
{
    QFileInfoList fileList = *globalContainer::getInstance()->getFileList();
    if(fileList.empty()){
        return;
    }
    emit progressShow();
    auto it = fileList.begin();
    QImage tempImage(it->absoluteFilePath());
    std::advance(it, 1);

    for( ; it != fileList.end(); it++){
        // progress info start with second image so progress is calculated with one less img
        int totalProg = std::distance(fileList.begin(), it) - 1;
        emit totalProgressChanged(totalProg / (fileList.size() - 1));

        // load img
        QImage currentImg(it->absoluteFilePath());

        // check if image has the same sizes
        if(currentImg.size() == tempImage.size()){
            tempImage = compareImages(tempImage, currentImg);
        }
    }

    globalContainer::getInstance()->setImage(tempImage);
    emit imageCompleted();

}

QImage Stacking::compareImages(const QImage &prevImg, const QImage &currImg)
{
    int progressSize = prevImg.height() * prevImg.width();

    QImage tempImg(prevImg.size(), QImage::Format_RGB32);
    for(int y = 0; y < currImg.height(); ++y){
        for(int x = 0; x < currImg.width(); ++x){
            // emit progress value in precentage value of total value of image size
            emit currentProgressChanged(x * y / progressSize * 100);

            // asign pixels of img
            QRgb pixel1 = prevImg.pixel(x, y);
            QRgb pixel2 = currImg.pixel(x, y);

            // Calculate the maximum value for each color component
            int red = qMax(qRed(pixel1), qRed(pixel2));
            int green = qMax(qGreen(pixel1), qGreen(pixel2));
            int blue = qMax(qBlue(pixel1), qBlue(pixel2));

            // Set the result to tempImg
            tempImg.setPixel(x, y, qRgb(red, green, blue));

        }
    }
    return tempImg;
}

