#ifndef SECONDARYFRAME_H
#define SECONDARYFRAME_H

#include <QWidget>
#include <QTimer>
#include <QDialog>
#include <QKeyEvent>
#include "player.h"
#include "enemya.h"
#include "enemyb.h"
#include "collector.h"

class SecondaryFrame : public QDialog
{
    Q_OBJECT

public:
    SecondaryFrame(QWidget *parent = nullptr, int dif = 0);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void Fire();
    

private:
    Player *player;
    Enemya *enemya;
    Enemyb *enemyb;
    Collector<Enemya>* collectora = nullptr;
    Collector<Enemyb>* collectorb = nullptr;
    QTimer *timer; 

};

#endif // SECONDARYFRAME_H
