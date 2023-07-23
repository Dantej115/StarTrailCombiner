#ifndef GLOBALCONTAINER_H
#define GLOBALCONTAINER_H

#include <QObject>
#include <QImage>
#include <QFileInfoList>

class globalContainer : public QObject
{
    Q_OBJECT
public:
    virtual ~globalContainer() final {}
    static globalContainer *getInstance();
    QFileInfoList* getFileList();
    void setImage(QImage img);
    QImage getImage() const;
    void fillFileList(QFileInfoList fileList);

private:
    explicit globalContainer(QObject * parent = nullptr){}
    globalContainer(const globalContainer&) = delete;
    globalContainer operator= (const globalContainer&) = delete;

private:
    QFileInfoList m_fileList;
    QImage starTrail;

signals:
    void loadWidget();
    void imageCompleted(QImage img);

};

#endif // GLOBALCONTAINER_H
