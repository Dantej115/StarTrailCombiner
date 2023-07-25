#ifndef PROGRESWINDOW_H
#define PROGRESWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QObject>
#include <QThread>

namespace Ui {
class ProgresWindow;
}

class ProgresWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgresWindow(QWidget *parent = nullptr);
    ~ProgresWindow();

public slots:
    void totalProgressChange(int Value);

signals:
    void canceled();

private slots:
    void on_cancelButton_clicked();

private:
    Ui::ProgresWindow *ui;
};

#endif // PROGRESWINDOW_H
