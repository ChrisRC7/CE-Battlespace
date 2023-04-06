#include "player.h"

Player::Player(QWidget *parent)
    : QLabel(parent)
{
    m_pixmap.load("src/ship.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
}
