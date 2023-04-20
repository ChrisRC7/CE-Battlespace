#include "bala.h"
#include<iostream>
using namespace std;

Bala::Bala(QWidget *parent, int posx, int posy, Collector<Enemya>* collectorA, Collector<Enemyb>* collectorB, bool wave1, bool wave2)
    : QLabel(parent)
{
    m_pixmap.load("src/bala.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
    setGeometry(posx, posy, m_pixmap.width(), m_pixmap.height());
    damage=2;
    mwave1= wave1;
    mwave2= wave2;
    // Asignar los punteros de Collector a los atributos de la clase
    m_collectorA = collectorA;
    m_collectorB = collectorB;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bala::moveRight);
    timer->start(1);
}
void Bala::moveRight()
{
    int x = pos().x();
    int y = pos().y();
    if (x>800){
        timer->stop();
        hide();
        delete this;
        return;
    }
    setGeometry(x + 1, y, width(), height());
      
    // Revisar colisiones con Enemya
    Enemya* enemyA = m_collectorA->getFirstNode();
    while (enemyA != nullptr)
    {
        if (enemyA->geometry().intersects(geometry()))
        {
            enemyA->reduceLife(damage);
            if(enemyA->getLife()<=0)
            {
                enemyA->hide();
                m_collectorA->removeNode(enemyA);
                delete enemyA;
                timer->stop();
                hide();
                delete this;
                return;
            }
            timer->stop();
            hide();
            delete this;
            return;
        }
        enemyA = m_collectorA->getNext(enemyA);
    }
    
    // Revisar colisiones con Enemyb
    Enemyb* enemyB = m_collectorB->getFirstNode();
    while (enemyB != nullptr)
    {
        if (enemyB->geometry().intersects(geometry()))
        {
            enemyB->reduceLife(damage);
            if(enemyB->getLife()<=0)
            {
                enemyB->hide();
                m_collectorB->removeNode(enemyB);
                delete enemyB;
                timer->stop();
                hide();
                delete this;
                return;
            }
            timer->stop();
            hide();
            delete this;
            return;
        }
        enemyB = m_collectorB->getNext(enemyB); 
    }
    if (m_collectorA->isEmpty() && m_collectorB->isEmpty()) 
    {
        
        if(mwave1)
        {
            printf("Se emito1");
            emit empty1();
            delete this;
            return;
        }else if(mwave2)
        {
            printf("Se emito");
            emit empty2();
            delete this;
            return;
        } else
        {
            emit empty3();
            delete this;
            return;
        }
        
    }

    
}

void Bala::setDamage()
{
    damage=1;
}
   

