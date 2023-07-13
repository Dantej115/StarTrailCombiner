#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include <QWidget>
#include <QString>
#include <QPlainTextEdit>
#include <QTime>

class MessageBoard : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit MessageBoard(QWidget *parent = nullptr);

signals:
public slots:
    void printLog(QString string);

};

#endif // MESSAGEBOARD_H
