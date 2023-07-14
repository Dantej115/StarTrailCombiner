#include "stacking.h"

Stacking::Stacking(QObject *parent) : QObject(parent)
{

}
void Stacking::processStarted()
{
    QFileInfoList* fileList = globalContainer::getInstance()->getFileList();


}
