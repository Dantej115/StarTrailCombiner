#include "messageboard.h"

MessageBoard::MessageBoard(QWidget *parent) : QPlainTextEdit(parent){}

void MessageBoard::printLog(QString string)
{
    QTime currentTime = QTime::currentTime();
    this->appendPlainText(currentTime.toString("hh:mm:ss") + ":\t" + string);
}
