#include <QtCore/QRandomGenerator>

#include "enemya.h"
#include "node.h"

Enemya::Enemya(QWidget *parent)
    : QLabel(parent)
{
    m_pixmap.load("src/enemya.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
    int pos1 = getRandomNumber();
    setGeometry(500, pos1, 68, 64);
    // Crear QTimer y conectar su señal timeout a la función moveRight()
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemya::moveRight);

    // Iniciar el QTimer para que envíe la señal timeout cada segundo
    timer->start(50);
    m_collectorNode = nullptr;
}

void Enemya::moveRight() {
    // Obtener la posición actual del jugador
    int x = pos().x();

    // Actualizar la posición del jugador hacia la derecha
    setGeometry(x - 1, pos().y(), width(), height());
}

int Enemya::getRandomNumber()
{
    return QRandomGenerator::global()->bounded(0, 450 + 1);
}

/*void Enemya::setCollectorNode(class Node<Enemya>* node)
{
    m_collectorNode = node;
}

void Enemya::removeFromCollector()
{
    if (m_collectorNode) {
        m_collectorNode->setNext(m_collectorNode->getNext()->getNext());
        m_collectorNode->setData(nullptr);
        delete m_collectorNode->getNext();
        m_collectorNode->setNext(nullptr);
        m_collectorNode->setData(nullptr);
    }
    m_collectorNode = nullptr;
}*/

