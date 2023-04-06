#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(800, 500);
    m_button = new QPushButton("Open secondary frame", this);
    m_button->setGeometry(100, 100, 200, 50);
    connect(m_button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

void MainWindow::onButtonClicked()
{
    m_secondaryFrame = new SecondaryFrame(this, 3);
    m_secondaryFrame->show();
}


