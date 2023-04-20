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

private:
    QPixmap m_pixmap;
    QTimer *timer;
    int life;

public slots:
    void start();
    void moveRight();
    int getLife();
    void reduceLife(int damage);
    int getRandomNumber();
};

#endif // ENEMYA_H
