#ifndef BUTTONBAR_H
#define BUTTONBAR_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QFileInfo>
#include <globalcontainer.h>

namespace Ui {
class ButtonBar;
}

class ButtonBar : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonBar(QWidget *parent = nullptr);
    ~ButtonBar();

signals:
    void listLoaded(QFileInfoList fileList);
    void Logged(QString str);
    void combineClicked();

private slots:
    void on_openButton_clicked();
    void on_combineButton_clicked();

private:
    Ui::ButtonBar *ui;
    QFileInfoList loadFileList(const QString& selectedFolder);
};

#endif // BUTTONBAR_H
