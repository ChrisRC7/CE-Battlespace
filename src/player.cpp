#include "player.h"

/**
 * This function sets the image of a player's ship in a QLabel widget.
 * 
 * @param parent The parent parameter is a pointer to the parent widget of the Player widget. It is
 * used to specify the parent-child relationship between widgets in the widget hierarchy. If a parent
 * widget is specified, the Player widget becomes a child of that parent widget and is displayed within
 * it. If no parent widget is specified
 */
Player::Player(QWidget *parent)
    : QLabel(parent)
{
    m_pixmap.load("src/ship.png");
    setPixmap(m_pixmap);
    setFixedSize(m_pixmap.width(), m_pixmap.height());
}
