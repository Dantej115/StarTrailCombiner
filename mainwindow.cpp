#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ProgresWindow* progresDialog = new ProgresWindow(this);
    progresDialog->show();


    QObject::connect(this, &MainWindow::Logged, ui->msgBoard, &MessageBoard::printLog);
    QObject::connect(ui->b_widget, &ButtonBar::Logged, ui->msgBoard, &MessageBoard::printLog);
    QObject::connect(ui->b_widget, &ButtonBar::listLoaded, this, &MainWindow::collectList);
    QObject::connect(this, &MainWindow::collectList, this, &MainWindow::loadWidget);
    QObject::connect(ui->b_widget, &ButtonBar::combineClicked, this, &MainWindow::progresBarShown);

    //connect(stacker, &Stacker::progressed, progressDialog, &ProgressDialog::setProgress);

    emit Logged("Welcome adventurer in StarTrails Composer");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QVariant varImg = item->data(Qt::UserRole);
    QPixmap img = varImg.value<QPixmap>();
    if (!img.isNull()) {
        QGraphicsScene* Scene = new QGraphicsScene(this);
        Scene->addPixmap(img);
        ui->graphicsView->setScene(Scene);
        ui->graphicsView->fitInView(Scene->sceneRect(), Qt::KeepAspectRatio);
    }
}

void MainWindow::loadWidget(QFileInfoList fileList)
{
    ui->listWidget->clear();
    for(const auto& file : fileList){
        QString filePath = file.absoluteFilePath();
        QFileInfo fileInfo(filePath);
        QListWidgetItem* item = new QListWidgetItem(fileInfo.fileName());
        ui->listWidget->addItem(item);
    }
}

void MainWindow::progresBarShown()
{

}

void MainWindow::collectList(QFileInfoList fileList)
{
    this->fileList = fileList;
    emit loadWidget(fileList);
}

void MainWindow::generateStarTrail()
{

}
