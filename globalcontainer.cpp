#include "globalcontainer.h"

globalContainer *globalContainer::getInstance()
{
    static globalContainer m_Instance;
    return &m_Instance;
}

QFileInfoList* globalContainer::getFileList()
{
    return &m_fileList;
}

void globalContainer::fillFileList(QFileInfoList fileList)
{
    m_fileList = std::move(fileList);
    emit loadWidget();
}
