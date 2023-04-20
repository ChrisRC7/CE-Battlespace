#include <QtCore/QRandomGenerator>

#include "enemya.h"
#include "node.h"

Enemya::Enemya(QWidget *parent)
    : QLabel(parent)
{
    /*m_pixmap.load("src/enemya.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
    int pos1 = getRandomNumber();
    setGeometry(500, pos1, 68, 64);
    life=5;
    // Crear QTimer y conectar su señal timeout a la función moveRight()
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemya::moveRight);
    
    // Iniciar el QTimer para que envíe la señal timeout cada segundo

    timer->start(50);*/
    
}

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

void Enemya::moveRight() {
    // Obtener la posición actual del jugador
    int x = pos().x();

    // Actualizar la posición del jugador hacia la derecha
    setGeometry(x - 1, pos().y(), width(), height());
}

int Enemya::getLife()
{
    return life;
}

void Enemya::reduceLife(int damage)
{
    life= life-damage;
}

int Enemya::getRandomNumber()
{
    return QRandomGenerator::global()->bounded(0, 450 + 1);
}


