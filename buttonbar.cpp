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

void ButtonBar::on_combineButton_clicked()
{
    emit combineClicked();
}

void ButtonBar::on_saveFileButton_clicked()
{

}
