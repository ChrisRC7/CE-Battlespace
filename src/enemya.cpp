#include <QtCore/QRandomGenerator>

#include "enemya.h"



Enemya::Enemya(QWidget *parent, int pos)
    : QLabel(parent)
{
    m_pixmap.load("src/enemya.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
    int pos2= getRandomNumber();
    setGeometry(500, pos2, 68, 64);
    // Crear QTimer y conectar su señal timeout a la función moveRight()
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemya::moveRight);

    // Iniciar el QTimer para que envíe la señal timeout cada segundo
    timer->start(1000);
}

void Enemya::moveRight() {
        // Obtener la posición actual del jugador
        int x = pos().x();

        // Actualizar la posición del jugador hacia la derecha
        setGeometry(x - 10, pos().y(), width(), height());
}

int Enemya::getRandomNumber()
{
    return QRandomGenerator::global()->bounded(0, 501 + 1);
}


