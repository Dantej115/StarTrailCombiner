#ifndef STACKING_H
#define STACKING_H

#include <QObject>
#include <QDialog>
#include <QVBoxLayout>


class Stacking : public QObject
{
    Q_OBJECT
public:
    explicit Stacking(QObject *parent = nullptr);

signals:
    void progressChanged();

private:

    QVBoxLayout* layout;

};

#endif // STACKING_H
