#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_button = new QPushButton("Open Secondary Frame", this);
    connect(m_button, &QPushButton::clicked, this, &MainWindow::openSecondaryFrame);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_button);
}

void MainWindow::openSecondaryFrame()
{
    SecondaryFrame *secondaryFrame = new SecondaryFrame();
    secondaryFrame->show();
}