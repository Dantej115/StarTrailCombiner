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
#include "messageboard.h"
#include "stacking.h"
#include "progreswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void loadWidget(QFileInfoList fileList);
    void progresBarShown();

signals:
    void Logged(QString str);

private:
    void collectList(QFileInfoList fileList);
    void generateStarTrail();

private:
    Ui::MainWindow *ui;
    QFileInfoList fileList;


};
#endif // MAINWINDOW_H
