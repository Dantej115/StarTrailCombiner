#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QFileDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QDialog>
#include <QGraphicsView>
#include <QListWidget>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QPixmap>
#include <QDebug>
#include <QThread>
#include "messageboard.h"
#include "stacking.h"
#include "progreswindow.h"
#include "widgetlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void Logged(QString str);
    void showImageRequested();

public slots:
    void imageComplete();
    void startStacking();

private:
    void connectObjects();

private:
    Ui::MainWindow *ui;
    QFileInfoList fileList;
    Stacking* stacker;
    QThread* stackingThread;
    ProgresWindow* progresDialog;
    globalContainer* contener;


};
#endif // MAINWINDOW_H
