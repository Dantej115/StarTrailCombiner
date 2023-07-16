#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ProgresWindow* progresDialog = new ProgresWindow(this);
    Stacking* stacker = new Stacking(this);
    globalContainer* contener = globalContainer::getInstance();


    // Signals for messageBox
    QObject::connect(this, &MainWindow::Logged, ui->msgBoard, &MessageBoard::printLog);
    QObject::connect(ui->b_widget, &ButtonBar::Logged, ui->msgBoard, &MessageBoard::printLog);

    // Signal file list loaded -> load Widget
    QObject::connect(contener,&globalContainer::loadWidget, ui->listWidget, &WidgetList::loadWidget);
    // Signal button combined clicked -> start stacking
    QObject::connect(ui->b_widget, &ButtonBar::combineClicked, stacker, &Stacking::processStarted);
    // Signal button combined clicked -> show window
    QObject::connect(stacker, &Stacking::progressShow, progresDialog, &ProgresWindow::show);
    QObject::connect(stacker, &Stacking::currentProgressChanged, progresDialog, &ProgresWindow::currentProgressChanged);
    QObject::connect(stacker, &Stacking::totalProgressChanged, progresDialog, &ProgresWindow::totalProgressChanged);
    // Signal stacker send info about completed image
    QObject::connect(stacker, &Stacking::imageCompleted, this, &MainWindow::imageCompleted);

    emit Logged("Welcome adventurer in StarTrails Composer");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::imageCompleted()
{
    QPixmap img = QPixmap::fromImage(globalContainer::getInstance()->getImage());
    if (!img.isNull()) {
        QGraphicsScene* Scene = new QGraphicsScene(this);
        Scene->addPixmap(img);
        ui->graphicsView->setScene(Scene);
        ui->graphicsView->fitInView(Scene->sceneRect(), Qt::KeepAspectRatio);
    }
}

//void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
//{
//    QVariant varImg = item->data(Qt::UserRole);
//    QPixmap img = varImg.value<QPixmap>();
//    if (!img.isNull()) {
//        QGraphicsScene* Scene = new QGraphicsScene(this);
//        Scene->addPixmap(img);
//        ui->graphicsView->setScene(Scene);
//        ui->graphicsView->fitInView(Scene->sceneRect(), Qt::KeepAspectRatio);
//    }
//}
