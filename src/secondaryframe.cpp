#include "secondaryframe.h"
#include <QKeyEvent>

SecondaryFrame::SecondaryFrame(QWidget *parent)
    : QDialog(parent)
{
    m_imageLabel = new QLabel(this);
    m_imageLabel->setPixmap(QPixmap("src/ship.png"));
}

void SecondaryFrame::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        m_imageLabel->move(m_imageLabel->x(), m_imageLabel->y() - 10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        m_imageLabel->move(m_imageLabel->x(), m_imageLabel->y() + 10);
    }
    
    QDialog::keyPressEvent(event);
}