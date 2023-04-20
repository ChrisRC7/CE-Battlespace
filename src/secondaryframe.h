#ifndef SECONDARYFRAME_H
#define SECONDARYFRAME_H

#include <QWidget>
#include <QTimer>
#include <QDialog>
#include <QKeyEvent>
#include "player.h"
#include "bala.h"
#include "enemya.h"
#include "enemyb.h"
#include "collector.h"

class SecondaryFrame : public QDialog
{
    Q_OBJECT

public:
    SecondaryFrame(QWidget *parent = nullptr, int dif = 0);

protected:
    void changeSpeed();
    void wave1();
    void wave2();
    void keyPressEvent(QKeyEvent *event) override;
    void up();
    void down();
    void Fire();
    void closeEvent(QCloseEvent *event) override;
    void closeFrame();
    

private:
    Player *player;
    Bala *bala;
    Collector<Enemya>* collectora = nullptr;
    Collector<Enemyb>* collectorb = nullptr;
    Collector<Enemya>* collectora1 = nullptr;
    Collector<Enemyb>* collectorb1 = nullptr;
    Collector<Enemya>* collectora2 = nullptr;
    Collector<Enemyb>* collectorb2 = nullptr;
    QTimer *timer;
    int speed;
    int waves;
    bool cambio;
    bool cambio1;
    bool cambio2; 

};

#endif // SECONDARYFRAME_H
