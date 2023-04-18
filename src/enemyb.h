#ifndef ENEMYB_H
#define ENEMYB_H

#include <QTimer>
#include <QLabel>
#include "node.h"

class Enemyb : public QLabel
{
    Q_OBJECT

public:
    Enemyb(QWidget *parent = nullptr);
    
    //void setCollectorNode(class Node<Enemyb>* node);
    //void removeFromCollector();

private:
    QPixmap m_pixmap;
    QTimer *timer;
    bool m;
    //class Node<Enemyb>* m_collectorNode;

public slots:
    void moveRight();
    int getRandomNumber();
};

#endif // ENEMYB_H
