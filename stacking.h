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
    void progressChanged(int totalVal, int tempVal);

private:
    QVBoxLayout* layout;


};

#endif // STACKING_H
