#include "bala.h"
#include<iostream>
using namespace std;

/**
 * This function creates a bullet object with a pixmap and assigns collector pointers to its
 * attributes.
 * 
 * @param parent The parent widget of the QLabel. It is the widget that owns and manages the memory of
 * this QLabel.
 * @param posx The x-coordinate position of the bullet on the screen.
 * @param posy posy is the y-coordinate of the position where the Bala object will be placed on the
 * screen.
 * @param collectorA A pointer to a Collector object that collects objects of type Enemya.
 * @param collectorB `collectorB` is a pointer to an object of the `Collector` class that collects
 * objects of type `Enemyb`. This is used in the `Bala` class to keep track of the enemies that the
 * bullet can hit and damage.
 * @param wave1 The parameter "wave1" is a boolean variable that indicates whether the bullet belongs
 * to the first wave of enemies or not.
 * @param wave2 The parameter "wave2" is a boolean variable that indicates whether the bullet was fired
 * during the second wave of enemies or not. It is used to determine the amount of damage the bullet
 * will cause to the enemies.
 */
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


/**
 * This function moves an object to the right and checks for collisions with two different types of
 * enemies, deleting the object and the enemy if a collision occurs, and emitting a signal if all
 * enemies have been defeated.
 * 
 * @return void, which means it is not returning any value but rather performing certain actions within
 * the function.
 */
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

/**
 * The function sets the damage of an object of class Bala to 1.
 */
void Bala::setDamage()
{
    damage=1;
}
   

