#include "bala.h"

Bala::Bala(QWidget *parent, int posx, int posy, Collector<Enemya>* collectorA, Collector<Enemyb>* collectorB)
    : QLabel(parent)
{
    m_pixmap.load("src/bala.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
    setGeometry(posx, posy, m_pixmap.width(), m_pixmap.height());
    damage=2;
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
                return;
            }
            timer->stop();
            hide();
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
                return;
            }
            timer->stop();
            hide();
            return;
        }
        enemyB = m_collectorB->getNext(enemyB); 
    }
    
}

void Bala::setDamage()
{
    damage=1;
}
   

