#include <QtCore/QRandomGenerator>

#include "enemya.h"
#include "node.h"

/**
 * This is a constructor for the Enemya class that takes a QWidget pointer and a Collector pointer as
 * parameters.
 * 
 * @param parent The parent parameter is a pointer to the parent widget of the Enemya widget. It is
 * used to specify the parent-child relationship between widgets in the widget hierarchy. If the parent
 * parameter is set to nullptr, then the Enemya widget will be a top-level widget.
 * @param collector The parameter "collector" is a pointer to an object of type "Collector" that is
 * templated with the type "Enemya". This object is used to collect and manage instances of the
 * "Enemya" class. The "parent" parameter is a pointer to the parent widget of the "Enemy
 */
Enemya::Enemya(QWidget *parent, Collector<Enemya>* collector)
    : QLabel(parent)
{
    collectora= collector;
}

/**
 * The function initializes an enemy object with a pixmap, position, and a QTimer that triggers the
 * moveRight() function every 50 milliseconds.
 */
void Enemya::start()
{
    m_pixmap.load("src/enemya.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
    int pos1 = getRandomNumber();
    setGeometry(500, pos1, 68, 64);
    life=5;
    // Crear QTimer y conectar su señal timeout a la función moveRight()
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemya::moveRight);
    
    // Iniciar el QTimer para que envíe la señal timeout cada segundo

    timer->start(50);
}

/**
 * This function moves an enemy object to the right and removes it from the game if it reaches a
 * certain position.
 */
void Enemya::moveRight() {
    // Obtener la posición actual del jugador
    int x = pos().x();

    // Actualizar la posición del jugador hacia la derecha
    setGeometry(x - 1, pos().y(), width(), height());
    if(x<10){
        timer->stop();
        hide();
        collectora->removeNode(this);
        delete this;
    }
}

/**
 * The function returns the current life of an object of the Enemya class.
 * 
 * @return The function `getLife()` is returning the value of the private member variable `life` of the
 * `Enemya` class.
 */
int Enemya::getLife()
{
    return life;
}

/**
 * The function reduces the life of an enemy object by a specified amount of damage.
 * 
 * @param damage The amount of damage that the enemy will receive and that will be subtracted from its
 * current life.
 */
void Enemya::reduceLife(int damage)
{
    life= life-damage;
}

/**
 * The function returns a random integer between 0 and 450 (inclusive).
 * 
 * @return A random integer between 0 and 450 (inclusive) is being returned.
 */
int Enemya::getRandomNumber()
{
    return QRandomGenerator::global()->bounded(0, 450 + 1);
}


