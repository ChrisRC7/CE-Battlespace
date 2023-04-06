#ifndef PLAYER_H
#define PLAYER_H

#include <QLabel>

class Player : public QLabel
{
    Q_OBJECT

public:
    Player(QWidget *parent = nullptr);

private:
    QPixmap m_pixmap;
};

#endif // PLAYER_H


