#include "viewscene.h"

ViewScene::ViewScene(QWidget *parent) : QGraphicsView(parent)
{
    Scene = new QGraphicsScene(this);
}

void ViewScene::viewImage()
{
    QPixmap img = QPixmap::fromImage(globalContainer::getInstance()->getImage());
    if (!img.isNull()) {

        QPixmap rescaled = img.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        Scene->addPixmap(rescaled);
        this->setScene(Scene);
        this->fitInView(Scene->sceneRect(), Qt::KeepAspectRatio);
    }
}
