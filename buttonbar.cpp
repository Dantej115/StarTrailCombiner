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
    QString selectedFolder  = QFileDialog::getExistingDirectory(nullptr, "Select Folder");

    if (selectedFolder.isEmpty()) {
        emit Logged("Error: folder is empty");
        return;
    }
    QFileInfoList tempfileList = loadFileList(selectedFolder);

    if(tempfileList.empty()){
        emit Logged("Error: Folder has no images");
        return;
    }
    emit Logged("Load successfuly");
    emit listLoaded(tempfileList);
}
QFileInfoList ButtonBar::loadFileList(const QString& selectedFolder)
{
    QDir folderDir(selectedFolder);

    folderDir.setFilter(QDir::Files | QDir::NoSymLinks);
    folderDir.setNameFilters(QStringList() << "*.jpg" << "*.JPG");

    QFileInfoList tempfileList = folderDir.entryInfoList();

    return tempfileList;
}

void ButtonBar::on_combineButton_clicked()
{
    emit combineClicked();
}
