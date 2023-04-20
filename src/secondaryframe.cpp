#include "secondaryframe.h"
#include "player.h"
#include "bala.h"
#include<iostream>
using namespace std;


SecondaryFrame::SecondaryFrame(QWidget *parent, int diff)
    : QDialog(parent)
{
    speed=500;
    waves=3;
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(800, 500);
    player = new Player(this);
    
    player->move(0, 200);
    player->show();
    setFocusPolicy(Qt::StrongFocus);
    collectora= new Collector<Enemya>();
    collectorb= new Collector<Enemyb>();
    collectora1= new Collector<Enemya>();
    collectorb1= new Collector<Enemyb>();
    collectora2= new Collector<Enemya>();
    collectorb2= new Collector<Enemyb>();
    for (int i = 0; i < diff; i++)
    {
        Enemya* enemyA = new Enemya(this, collectora);
        Enemyb* enemyB = new Enemyb(this, collectorb);
        Enemya* enemyA1 = new Enemya(this, collectora1);
        Enemyb* enemyB1 = new Enemyb(this, collectorb1);
        Enemya* enemyA2 = new Enemya(this, collectora2);
        Enemyb* enemyB2 = new Enemyb(this, collectorb2);
        collectora->insertFirst(enemyA);
        collectorb->insertFirst(enemyB);
        collectora1->insertFirst(enemyA1);
        collectorb1->insertFirst(enemyB1);
        collectora2->insertFirst(enemyA2);
        collectorb2->insertFirst(enemyB2);
    }
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SecondaryFrame::Fire);
    timer->start(speed);
    Enemya* enemyA = collectora->getFirstNode();
    while (enemyA != nullptr)
    {
        enemyA->start();
        enemyA = collectora->getNext(enemyA);
    }
    Enemyb* enemyB = collectorb->getFirstNode();
    while (enemyB != nullptr)
    {
        enemyB->start();
        enemyB = collectorb->getNext(enemyB);
    }
    cambio= true;
    cambio1= false;
    cambio2= false;

}

void SecondaryFrame::changeSpeed()
{
    if(speed==500)
    {
        speed=1500;
    } else if(speed==1500)
    {
        speed=2500;
    } else
    {
        speed=500;
    }
}

/**
 * The function starts the movement of enemies in wave 1 and disconnects a signal.
 */
void SecondaryFrame::wave1()
{
    waves--;
    printf("wave");
    disconnect(bala, &Bala::empty1, nullptr, nullptr);
    cambio= false;
    cambio1= true;
    Enemya* enemyA = collectora1->getFirstNode();
    while (enemyA != nullptr)
    {
        enemyA->start();
        enemyA = collectora1->getNext(enemyA);
    }
    Enemyb* enemyB = collectorb1->getFirstNode();
    while (enemyB != nullptr)
    {
        enemyB->start();
        enemyB = collectorb1->getNext(enemyB);
    }
    
}

void SecondaryFrame::wave2()
{
    waves--;
    disconnect(bala, &Bala::empty2, nullptr, nullptr);
    cambio1=false;
    cambio2= true;
    Enemya* enemyA = collectora2->getFirstNode();
    while (enemyA != nullptr)
    {
        enemyA->start();
        enemyA = collectora2->getNext(enemyA);
    }
    Enemyb* enemyB = collectorb2->getFirstNode();
    while (enemyB != nullptr)
    {
        enemyB->start();
        enemyB = collectorb2->getNext(enemyB);
    }
}

/**
 * The function creates and shows a bullet object based on the state of three different collections and
 * connects it to different signals.
 */
void SecondaryFrame::Fire()
{
    if((!collectora->isEmpty() or !collectorb->isEmpty()) or cambio)
    {
        bala = new Bala(this, player->x() + 68, player->y() + 28, collectora, collectorb, true, false);
        bala->show();
        connect(bala, &Bala::empty1, this, &SecondaryFrame::wave1);
    } else if((!collectora1->isEmpty() or !collectorb1->isEmpty()) or cambio1)
    {
        bala = new Bala(this, player->x() + 68, player->y() + 28, collectora1, collectorb1, false, true);
        bala->show();
        connect(bala, &Bala::empty2, this, &SecondaryFrame::wave2);
    } else if((!collectora2->isEmpty() or !collectorb2->isEmpty()) or cambio2)
    {
        bala = new Bala(this, player->x() + 68, player->y() + 28, collectora2, collectorb2, false, false);
        bala->show();
        connect(bala, &Bala::empty3, this, &SecondaryFrame::closeFrame);
    }
}

void SecondaryFrame::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up or event->key() == Qt::Key_W) {
        SecondaryFrame::up();
    } else if (event->key() == Qt::Key_Down or event->key() == Qt::Key_S) {
        SecondaryFrame::down();
    } else if (event->key() == Qt::Key_R) {
        SecondaryFrame::changeSpeed();
    }
}

void SecondaryFrame::up()
{
    player->move(0, player->y() - 10);
}

void SecondaryFrame::down()
{
    player->move(0, player->y() + 10);
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

void SecondaryFrame::closeFrame()
{
    close();
}