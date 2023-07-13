#include "progreswindow.h"
#include "ui_progreswindow.h"

ProgresWindow::ProgresWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgresWindow)
{
    ui->setupUi(this);
}

ProgresWindow::~ProgresWindow()
{
    delete ui;
}
