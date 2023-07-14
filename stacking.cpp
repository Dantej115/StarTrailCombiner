#include "stacking.h"

Stacking::Stacking(QObject *parent) : QObject(parent)
{

}
void Stacking::processStarted()
{
    globalContainer::getInstance()->getFileList();
}
