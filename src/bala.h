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
    Bala(QWidget *parent = nullptr, int posx = 0, int posy = 0, Collector<Enemya>* collectorA = nullptr, Collector<Enemyb>* collectorB = nullptr);

private:
    QPixmap m_pixmap;
    QTimer *timer;
    Collector<Enemya>* m_collectorA;
    Collector<Enemyb>* m_collectorB;


public slots:
    void moveRight();
};

#endif // BALA_H