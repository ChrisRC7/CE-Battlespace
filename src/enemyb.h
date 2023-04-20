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

private:
    QPixmap m_pixmap;
    QTimer *timer;
    bool m;
    int life;

public slots:
    void start();
    void moveRight();
    int getLife();
    void reduceLife(int damage);
    int getRandomNumber();
};

#endif // ENEMYB_H
