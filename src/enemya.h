#ifndef ENEMYA_H
#define ENEMYA_H

#include <QTimer>
#include <QLabel>

class Enemya : public QLabel
{
    Q_OBJECT

public:
    Enemya(QWidget *parent = nullptr, int pos = 0);

private:
    QPixmap m_pixmap;
    QTimer *timer;

public slots:
    void moveRight();
    int getRandomNumber();
};


#endif // ENEMYA_H