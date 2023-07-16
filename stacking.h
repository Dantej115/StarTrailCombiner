#ifndef STACKING_H
#define STACKING_H

#include <QObject>
#include <QDialog>
#include <QVBoxLayout>
#include <QScopedPointer>
#include <globalcontainer.h>


class Stacking : public QObject
{
    Q_OBJECT
public:
    explicit Stacking(QObject *parent = nullptr);

public slots:
    void processStarted();

signals:
    void currentProgressChanged(int Value);
    void totalProgressChanged(int Value);
    void imageCompleted();
    void progressShow();

private:
    QImage compareImages(const QImage& img1, const QImage& img2);

private:
    QVBoxLayout* layout;


};

#endif // STACKING_H
