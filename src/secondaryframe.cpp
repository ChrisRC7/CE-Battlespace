#include "secondaryframe.h"
#include "player.h"
#include "bala.h"
#include<iostream>
using namespace std;


SecondaryFrame::SecondaryFrame(QWidget *parent, int diff)
    : QDialog(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
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
        Enemya* enemyA1 = new Enemya(this);
        Enemyb* enemyB1 = new Enemyb(this);
        Enemya* enemyA2 = new Enemya(this);
        Enemyb* enemyB2 = new Enemyb(this);
        collectora->insertFirst(enemyA);
        collectorb->insertFirst(enemyB);
        /*collectora->insertFirst(enemyA1);
        collectorb->insertFirst(enemyB1);
        collectora1->insertFirst(enemyA1);
        collectorb1->insertFirst(enemyB1);
        collectora2->insertFirst(enemyA2);
        collectorb2->insertFirst(enemyB2);*/
    }
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SecondaryFrame::Fire);
    timer->start(1500);   
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
        if(!collectora->isEmpty() && !collectorb->isEmpty())
        {
            Bala* bala = new Bala(this, x + 68, y + 28, collectora, collectorb);
            bala->show();
        } else if(!collectora1->isEmpty() && !collectorb1->isEmpty()){
            Bala* bala = new Bala(this, x + 68, y + 28, collectora1, collectorb2);
            bala->show();
        } else if(!collectora2->isEmpty() && !collectorb2->isEmpty())
        {
            Bala* bala = new Bala(this, x + 68, y + 28, collectora1, collectorb2);
            bala->show();
        }
    }
}

void SecondaryFrame::closeEvent(QCloseEvent *event)
{
    cout<<"Se detuvo";
    Enemya* enemyA = collectora->getFirstNode();
    Enemya* temp= nullptr;
    while (enemyA != nullptr)
    {
        temp= enemyA;
        enemyA = collectora->getNext(enemyA);
        collectora->removeNode(temp);
        delete temp;
    }
    Enemyb* enemyB = collectorb->getFirstNode();
    Enemyb* temp2= nullptr;
    while (enemyB != nullptr)
    {
        temp2= enemyB;
        enemyB = collectorb->getNext(enemyB);
        collectorb->removeNode(temp2);
        delete temp2;
    }
    delete collectora;
    delete collectorb;
    timer->stop();
    event->accept();
}
