#ifndef BALA_H
#define BALA_H

#include <QTimer>
#include <QLabel>
#include "collector.h"
#include "enemya.h"
#include "enemyb.h"

class Bala : public QLabel
{
    Q_OBJECT

public:
    Bala(QWidget *parent = nullptr, int posx = 0, int posy = 0, Collector<Enemya>* collectorA = nullptr, Collector<Enemyb>* collectorB = nullptr, bool wave1= false, bool wave2= false);

private:
    QPixmap m_pixmap;
    QTimer *timer;
    Collector<Enemya>* m_collectorA;
    Collector<Enemyb>* m_collectorB;
    bool mwave1;
    bool mwave2;
    int damage;


public slots:
    void moveRight();
    void setDamage();

signals:
    void empty1();
    void empty2();
    void empty3();
};

#endif // BALA_H