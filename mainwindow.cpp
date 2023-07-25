#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stacker = new Stacking();
    stackingThread = new QThread(this);
    stacker->moveToThread(stackingThread);
    progresDialog = new ProgresWindow(this);
    contener = globalContainer::getInstance();

    connectObjects();
    emit Logged("Welcome adventurer in StarTrails Composer");

}

MainWindow::~MainWindow()
{
    stackingThread->exit();
    delete ui;
    delete stacker;
    delete contener;

}
void MainWindow::startStacking()
{
    stackingThread->start();
}


void MainWindow::imageComplete()
{
    QPixmap img = QPixmap::fromImage(globalContainer::getInstance()->getImage());
    if (!img.isNull()) {
        QGraphicsScene* Scene = new QGraphicsScene(this);
        Scene->addPixmap(img);
        ui->graphicsView->setScene(Scene);
        ui->graphicsView->fitInView(Scene->sceneRect(), Qt::KeepAspectRatio);
    }
    stackingThread->exit();
    stackingThread->wait();
}

void MainWindow::connectObjects()
{
    // Signals for messageBox
    QObject::connect(this, &MainWindow::Logged, ui->msgBoard, &MessageBoard::printLog);
    QObject::connect(ui->b_widget, &ButtonBar::Logged, ui->msgBoard, &MessageBoard::printLog);

    // Signal file list loaded -> load Widget
    QObject::connect(contener,&globalContainer::loadWidget, ui->listWidget, &WidgetList::loadWidget);
    // Signal button combined clicked -> start thread
    QObject::connect(ui->b_widget, &ButtonBar::combineClicked, this, &MainWindow::startStacking);
    // Signal button combined clicked -> start stacking
    QObject::connect(ui->b_widget, &ButtonBar::combineClicked, stacker, &Stacking::processStart);
    // Signal button combined clicked -> show window
    QObject::connect(stacker, &Stacking::progressShow, progresDialog, &ProgresWindow::show);
    // Signal stacker give info to progress dialog about total progress
    QObject::connect(stacker, &Stacking::totalProgressChanged, progresDialog, &ProgresWindow::totalProgressChange,Qt::DirectConnection);
    // Signal stacker send info about completed image
    QObject::connect(stacker, &Stacking::imageCompleted, this, &MainWindow::imageComplete);
    // Signal stacker send info about completed image
    QObject::connect(stacker, &Stacking::imageCompleted, progresDialog, &ProgresWindow::close);
    // Signal Progress dialog that cancel has been clicked. Stacking algorithm is aborted
    QObject::connect(progresDialog, &ProgresWindow::canceled, stacker, &Stacking::processCancel, Qt::DirectConnection);
}

