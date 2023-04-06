#ifndef ENEMYB_H
#define ENEMYB_H

#include <QTimer>
#include <QLabel>

class Enemyb : public QLabel
{
    Q_OBJECT

public:
    Enemyb(QWidget *parent = nullptr, int pos = 0);

private:
    QPixmap m_pixmap;

public slots:
    void moveRight();
    int getRandomNumber();


};

#endif // ENEMYB_H