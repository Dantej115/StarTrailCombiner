#ifndef WIDGETLIST_H
#define WIDGETLIST_H

#include <QWidget>
#include <QListWidget>
#include <QWidget>
#include <QFileInfo>
#include "globalcontainer.h"


class WidgetList : public QListWidget
{
    Q_OBJECT
public:
    explicit WidgetList(QWidget *parent = nullptr);

signals:

public slots:
    void loadWidget();
};

#endif // WIDGETLIST_H
