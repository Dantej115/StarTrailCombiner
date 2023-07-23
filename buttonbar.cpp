#include "buttonbar.h"
#include "ui_buttonbar.h"

ButtonBar::ButtonBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonBar)
{
    ui->setupUi(this);
}

ButtonBar::~ButtonBar()
{
    delete ui;
}

void ButtonBar::on_openButton_clicked()
{
    QFileInfoList fileList = loadFileList();

    if(fileList.empty()){
        emit Logged("Error: Folder has no images");
        return;
    }
    emit Logged("Load successfuly");
    globalContainer::getInstance()->fillFileList(fileList);

}
QFileInfoList ButtonBar::loadFileList()
{
    QStringList  filePathList  = QFileDialog::getOpenFileNames(
                nullptr,
                "Select JPG files",
                QDir::homePath(),
                "Images (*.jpeg *.jpg *.JPG)"
                );

    QFileInfoList fileList;
    for(auto fileName : filePathList){
        QFileInfo file(fileName);
        fileList.append(file);
    }
    return fileList;
}

bool ButtonBar::fileSave()
{
    QImage imageToSave = globalContainer::getInstance()->getImage();
    if(imageToSave.isNull()){
        emit Logged("Error: No image to save");
        return false;
    }
    QString filePath = QFileDialog::getSaveFileName(
                this,
                tr("Save Image"),
                QDir::homePath(),
                tr("Images (*.png *.xpm *.jpg)")
                );

    if (filePath.isNull() || filePath.isEmpty()) {
        emit Logged("Error: Invalid filepath");
        return false;
    }
        ;
    if (!filePath.toLower().endsWith(".jpg", Qt::CaseInsensitive)) {
        filePath += ".jpg";
    }

    return imageToSave.save(filePath);
}
//bool ButtonBar::fileSave()
//{
//    QImage imageToSave = globalContainer::getInstance()->getImage();
//    if(imageToSave.isNull()){
//        throw
//    }
//    QString filePath = QFileDialog::getSaveFileName(
//                this,
//                "Save Image",
//                QDir::homePath(),
//                "Images (*.jpg)"
//                );

//    if (filePath.isNull() || filePath.isEmpty()) {
//        emit Logged("Error: Invalid filepath");
//        return false;
//    }
//    return imageToSave.save(filePath);
//}

void ButtonBar::on_combineButton_clicked()
{
    emit combineClicked();
}

void ButtonBar::on_saveFileButton_clicked()
{
    bool fileSaved = fileSave();
    if (!fileSaved) {
        emit Logged("Error: Failed to save the image");
        return;
    }
    emit Logged("Image saved successfuly");

}
