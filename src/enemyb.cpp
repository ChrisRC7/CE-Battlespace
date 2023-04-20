#include <QtCore/QRandomGenerator>
#include "enemyb.h"

/**
 * This is a constructor for the Enemyb class that takes a QWidget pointer and a Collector pointer as
 * parameters.
 * 
 * @param parent The parent parameter is a pointer to the parent widget of the Enemyb widget. It is
 * used to specify the parent-child relationship between widgets in the widget hierarchy. If the parent
 * parameter is set to nullptr, then the Enemyb widget will be a top-level widget.
 * @param collector The parameter "collector" is a pointer to an object of type "Collector" that is
 * templated with the type "Enemyb". This object is used to collect and manage instances of the
 * "Enemyb" class.
 */
Enemyb::Enemyb(QWidget *parent, Collector<Enemyb>* collector)
    : QLabel(parent)
{
    collectorb= collector;
}
/**
 * This function creates and displays a new secondary frame when button 1 is clicked in the main
 * window.
 */

/**
 * This function initializes and starts the movement of an enemy object in a game.
 */
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

/**
 * The function moves an enemy object to the right and updates its position, while also checking if it
 * has reached the edge of the screen and removing it if it has.
 */
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

/**
 * The function returns the current life of an object of the Enemyb class.
 * 
 * @return The function `getLife()` is returning the value of the private member variable `life` of the
 * `Enemyb` class.
 */
int Enemyb::getLife()
{
    return life;
}

void Enemyb::reduceLife(int damage)
{
    life= life-damage;
}

/**
 * The function returns a random integer between 0 and 450 (inclusive).
 * 
 * @return A random integer between 0 and 450 (inclusive) is being returned.
 */
int Enemyb::getRandomNumber()
{
    return QRandomGenerator::global()->bounded(0, 450 + 1);
}

