#ifndef BUTTONBAR_H
#define BUTTONBAR_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QFileInfo>
#include <QMessageBox>
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

    void on_saveFileButton_clicked();

private:
    Ui::ButtonBar *ui;
    QFileInfoList loadFileList();
    bool fileSave();
};

#endif // BUTTONBAR_H
