#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "secondaryframe.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onButton1Clicked();
    void onButton2Clicked();
    void onButton3Clicked();

private:
    QPushButton *m_button1;
    QPushButton *m_button2;
    QPushButton *m_button3;
    SecondaryFrame *m_secondaryFrame;
};

#endif // MAINWINDOW_H
