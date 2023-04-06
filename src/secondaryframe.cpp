#include <thread>
#include "secondaryframe.h"
#include "player.cpp"
#include "enemya.cpp"
#include "enemyb.cpp"

SecondaryFrame::SecondaryFrame(QWidget *parent, int diff)
    : QDialog(parent)
{
    setFixedSize(800, 500);
    player = new Player(this);
    
    player->move(0, 200);
    player->show();
    setFocusPolicy(Qt::StrongFocus);
    for (int i = 0; i < diff; i++)
    {
        Enemya* enemyA= new Enemya(this, i);
        Enemyb* ememyA = new Enemyb(this, i);
    }
    
    

    
}

void SecondaryFrame::keyPressEvent(QKeyEvent *event)
{
    int y = player->y();
    if (event->key() == Qt::Key_Up) {
        player->move(0, y - 10);
    } else if (event->key() == Qt::Key_Down) {
        player->move(0, y + 10);
    }
}

