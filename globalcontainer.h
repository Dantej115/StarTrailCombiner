#ifndef GLOBALCONTAINER_H
#define GLOBALCONTAINER_H

#include <QObject>
#include <QFileInfoList>

class globalContainer : public QObject
{
    Q_OBJECT
public:
    virtual ~globalContainer() final {}
    static globalContainer *getInstance();
    QFileInfoList* getFileList();
    void fillFileList(QFileInfoList fileList);

private:
    explicit globalContainer(QObject * parent = nullptr){}
    globalContainer(const globalContainer&) = delete;
    globalContainer operator= (const globalContainer&) = delete;
private:
    QFileInfoList m_fileList;

signals:
    void loadWidget();

};

#endif // GLOBALCONTAINER_H
