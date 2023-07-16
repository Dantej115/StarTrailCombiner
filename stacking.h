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
    void processStart();
    void processCancel();

signals:
    void currentProgressChanged(int Value);
    void totalProgressChanged(int Value);
    void imageCompleted();
    void progressShow();

private:
    QImage compareImages(const QImage &prevImg, const QImage &currImg);

private:
    QVBoxLayout* layout;
    bool m_isInterrupted;

};

#endif // STACKING_H
