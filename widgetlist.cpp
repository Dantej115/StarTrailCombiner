#include "widgetlist.h"

WidgetList::WidgetList(QWidget *parent) : QListWidget(parent)
{

}
void WidgetList::loadWidget()
{
    QFileInfoList* fileList = globalContainer::getInstance()->getFileList();
    this->clear();
    for(const auto& file : *fileList){
        QString filePath = file.absoluteFilePath();
        QFileInfo fileInfo(filePath);
        QListWidgetItem* item = new QListWidgetItem(fileInfo.fileName());
        this->addItem(item);
    }
}
