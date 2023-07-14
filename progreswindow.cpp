#include "progreswindow.h"
#include "ui_progreswindow.h"

ProgresWindow::ProgresWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgresWindow)
{
    ui->setupUi(this);
    ui->currentProgressBar->setRange(0, 100);
    ui->totalProgressBar->setRange(0, 100);
}

ProgresWindow::~ProgresWindow()
{
    delete ui;
}

void ProgresWindow::progressChanged(int totalVal, int tempVal)
{

}
