#ifndef PROGRESWINDOW_H
#define PROGRESWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>

namespace Ui {
class ProgresWindow;
}

class ProgresWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgresWindow(QWidget *parent = nullptr);
    ~ProgresWindow();

private:
    Ui::ProgresWindow *ui;
};

#endif // PROGRESWINDOW_H
