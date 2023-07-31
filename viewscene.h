#ifndef VIEWSCENE_H
#define VIEWSCENE_H

#include <QObject>
#include <QGraphicsView>
#include <globalcontainer.h>
#include <QtDebug>

class ViewScene : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ViewScene(QWidget *parent = nullptr);

signals:

public slots:
    void viewImage();

private:
    QGraphicsScene* Scene;


};

#endif // VIEWSCENE_H
