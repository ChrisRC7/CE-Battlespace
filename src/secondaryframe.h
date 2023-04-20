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
    void wave();
    void keyPressEvent(QKeyEvent *event) override;
    void Fire();
    void closeEvent(QCloseEvent *event) override;
    

private:
    Player *player;
    Collector<Enemya>* collectora = nullptr;
    Collector<Enemyb>* collectorb = nullptr;
    Collector<Enemya>* collectora1 = nullptr;
    Collector<Enemyb>* collectorb1 = nullptr;
    Collector<Enemya>* collectora2 = nullptr;
    Collector<Enemyb>* collectorb2 = nullptr;
    QTimer *timer; 

};

#endif // SECONDARYFRAME_H
