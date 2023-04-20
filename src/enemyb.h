#ifndef ENEMYB_H
#define ENEMYB_H

#include <QTimer>
#include <QLabel>
#include "collector.h"

class Enemyb : public QLabel
{
    Q_OBJECT

public:
    Enemyb(QWidget *parent = nullptr, Collector<Enemyb>* collector= nullptr);

private:
    QPixmap m_pixmap;
    QTimer *timer;
    bool m;
    int life;
    Collector<Enemyb>* collectorb;

public slots:
    void start();
    void moveRight();
    int getLife();
    void reduceLife(int damage);
    int getRandomNumber();
};

#endif // ENEMYB_H
