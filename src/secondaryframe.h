#ifndef SECONDARYFRAME_H
#define SECONDARYFRAME_H

#include <QWidget>
#include <QDialog>
#include <QKeyEvent>
#include "player.h"
#include "enemya.h"
#include "enemyb.h"

class SecondaryFrame : public QDialog
{
    Q_OBJECT

public:
    SecondaryFrame(QWidget *parent = nullptr, int dif = 0);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Player *player;
    Enemya *enemya;
    Enemyb *enemyb;

};

#endif // SECONDARYFRAME_H

