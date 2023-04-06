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
    void onButtonClicked();

private:
    QPushButton *m_button;
    SecondaryFrame *m_secondaryFrame;
};

#endif // MAINWINDOW_H


