#include <QtCore/QRandomGenerator>
#include "enemyb.h"

Enemyb::Enemyb(QWidget *parent, Collector<Enemyb>* collector)
    : QLabel(parent)
{
    collectorb= collector;
}

void Enemyb::start()
{
    m= true;
    m_pixmap.load("src/enemyb.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
    int pos1 = getRandomNumber();
    setGeometry(500, pos1, 68, 64);
    life=5;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemyb::moveRight);

    timer->start(50);
}

void Enemyb::moveRight() {
    int x = pos().x() - 1;
    int y= pos().y();
    if(m==true)
    {
        y= y  + 10;
    } else {y= y- 10;}
    if (y>450){m=false;}
    if (y < 10){m=true;}
    setGeometry(x, y, width(), height());
    if (x<10)
    {
        timer->stop();
        hide();
        collectorb->removeNode(this);
        delete this;
    }
}

int Enemyb::getLife()
{
    return life;
}

void Enemyb::reduceLife(int damage)
{
    life= life-damage;
}

int Enemyb::getRandomNumber()
{
    return QRandomGenerator::global()->bounded(0, 450 + 1);
}

