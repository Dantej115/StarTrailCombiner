#include "progreswindow.h"
#include "ui_progreswindow.h"

ProgresWindow::ProgresWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgresWindow)
{
    ui->setupUi(this);
    //ui->currentProgressBar->setRange(0, 100);
    ui->totalProgressBar->setRange(0, 100);
    //ui->currentProgressBar->setValue(0);
    ui->totalProgressBar->setValue(0);

}

ProgresWindow::~ProgresWindow()
{
    delete ui;
}

void ProgresWindow::totalProgressChange(int Value)
{
    ui->totalProgressBar->setValue(Value);
}

void ProgresWindow::on_cancelButton_clicked()
{
    ui->totalProgressBar->setValue(0);
    emit canceled();
    this->close();
}
