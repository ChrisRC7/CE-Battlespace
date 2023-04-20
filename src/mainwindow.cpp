#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(800, 500);
    m_button1 = new QPushButton("Eazy", this);
    m_button1->setGeometry(100, 100, 200, 50);
    connect(m_button1, &QPushButton::clicked, this, &MainWindow::onButton1Clicked);

    m_button2 = new QPushButton("Medium", this);
    m_button2->setGeometry(100, 200, 200, 50);
    connect(m_button2, &QPushButton::clicked, this, &MainWindow::onButton2Clicked);

    m_button3 = new QPushButton("Hard", this);
    m_button3->setGeometry(100, 300, 200, 50);
    connect(m_button3, &QPushButton::clicked, this, &MainWindow::onButton3Clicked);
}

void MainWindow::onButton1Clicked()
{
    m_secondaryFrame = new SecondaryFrame(this, 1);
    m_secondaryFrame->show();
}

void MainWindow::onButton2Clicked()
{
    m_secondaryFrame = new SecondaryFrame(this, 2);
    m_secondaryFrame->show();
}

void MainWindow::onButton3Clicked()
{
    m_secondaryFrame = new SecondaryFrame(this, 3);
    m_secondaryFrame->show();
}