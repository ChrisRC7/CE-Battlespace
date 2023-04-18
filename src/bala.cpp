#include "bala.h"


Bala::Bala(QWidget *parent, int posx, int posy, Collector<Enemya>* collectorA, Collector<Enemyb>* collectorB)
    : QLabel(parent)
{
    m_pixmap.load("src/bala.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
    setGeometry(posx, posy, m_pixmap.width(), m_pixmap.height());

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
    int xb= pos().x();
    int yb= pos().y();
    int i= 0;
    Enemya* enemyA = m_collectorA->getFirstNode();
    while (i < m_collectorA->getSize())
    {
        if (enemyA->geometry().intersects(geometry()))
        {
            enemyA->hide();
            //Enemya* enemytemp= enemyA;
            enemyA = m_collectorA->getNext(enemyA);
            
            //m_collectorA->removeNode(enemyA);
            //delete enemyA;
            //this->hide();
            //break;

        } else{
            enemyA = m_collectorA->getNext(enemyA);
        }
        i++;
    }
    
        
    // Revisar colisiones con Enemyb
    Enemyb* enemyB = m_collectorB->getFirstNode();
    if (enemyB != nullptr) {
        i= 0;
        while (i < m_collectorA->getSize())
        {
            if (enemyB->geometry().intersects(geometry()))
        {
            enemyB->hide();
            //Enemya* enemytemp= enemyA;
            enemyB = m_collectorB->getNext(enemyB);

            //m_collectorA->removeNode(enemyA);
            //delete enemyA;
            //this->hide();
            //break;

        } else{
            enemyB = m_collectorB->getNext(enemyB);
        }
        i++;
        }
    }
    
}
   

