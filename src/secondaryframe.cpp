#include "secondaryframe.h"
#include "player.h"
#include "bala.h"


SecondaryFrame::SecondaryFrame(QWidget *parent, int diff)
    : QDialog(parent)
{
    setFixedSize(800, 500);
    player = new Player(this);
    
    player->move(0, 200);
    player->show();
    setFocusPolicy(Qt::StrongFocus);
    collectora= new Collector<Enemya>();
    collectorb= new Collector<Enemyb>();
    for (int i = 0; i < 1; i++)
    {
        Enemya* enemyA = new Enemya(this);
        Enemyb* enemyB = new Enemyb(this);
        collectora->insertFirst(enemyA);
        collectorb->insertFirst(enemyB);
        Enemya* enemyA2 = new Enemya(this);
        Enemyb* enemyB2 = new Enemyb(this);
        collectora->insertFirst(enemyA2);
        collectorb->insertFirst(enemyB2);
    }
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SecondaryFrame::Fire);
    timer->start(250);

}

void SecondaryFrame::Fire()
{
    Bala* bala = new Bala(this, player->x() + 68, player->y() + 28, collectora, collectorb);
    bala->show();
}

void SecondaryFrame::keyPressEvent(QKeyEvent *event)
{
    int x= player->x();
    int y = player->y();
    if (event->key() == Qt::Key_Up or event->key() == Qt::Key_W) {
        player->move(0, y - 10);
    } else if (event->key() == Qt::Key_Down or event->key() == Qt::Key_S) {
        player->move(0, y + 10);
    } else if (event->key() == Qt::Key_Space) {
        Bala* bala = new Bala(this, x + 68, y + 28, collectora, collectorb);
        bala->show();
    }
}


