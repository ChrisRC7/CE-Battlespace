#ifndef ENEMYA_H
#define ENEMYA_H

#include <QTimer>
#include <QLabel>
#include "node.h"

class Enemya : public QLabel
{
    Q_OBJECT

public:
    Enemya(QWidget *parent = nullptr);
    
    //void setCollectorNode(class Node<Enemya>* node);
    //void removeFromCollector();

private:
    QPixmap m_pixmap;
    QTimer *timer;
    class Node<Enemya>* m_collectorNode;

public slots:
    void moveRight();
    int getRandomNumber();
};

#endif // ENEMYA_H
