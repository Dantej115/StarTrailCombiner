#include "progreswindow.h"
#include "ui_progreswindow.h"

ProgresWindow::ProgresWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgresWindow)
{
    ui->setupUi(this);
    ui->currentProgressBar->setRange(0, 100);
    ui->totalProgressBar->setRange(0, 100);
    ui->currentProgressBar->setValue(0);
    ui->totalProgressBar->setValue(0);

}

ProgresWindow::~ProgresWindow()
{
    delete ui;
}

void ProgresWindow::progressChanged(int totalVal, int tempVal)
{
    ui->currentProgressBar->setValue(tempVal);
    ui->totalProgressBar->setValue(totalVal);

}

void ProgresWindow::on_cancelButton_clicked()
{
    ui->currentProgressBar->setValue(0);
    ui->totalProgressBar->setValue(0);
    this->close();
}
