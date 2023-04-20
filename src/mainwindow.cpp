#include "mainwindow.h"

/**
 * The function creates a window with three buttons and connects them to their respective click events.
 * 
 * @param parent The parent parameter is a pointer to the parent widget of the current widget. It is
 * used to specify the parent-child relationship between widgets. If a widget has a parent, it is
 * displayed within the parent widget's area. If the parent widget is deleted, all its child widgets
 * are also deleted. If
 */
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

/**
 * This function creates and shows a secondary frame when button 1 is clicked in the main window.
 */
void MainWindow::onButton1Clicked()
{
    m_secondaryFrame = new SecondaryFrame(this, 1);
    m_secondaryFrame->show();
}

/**
 * This function creates and displays a secondary frame when button 2 is clicked in the main window.
 */
void MainWindow::onButton2Clicked()
{
    m_secondaryFrame = new SecondaryFrame(this, 2);
    m_secondaryFrame->show();
}

/**
 * This function creates and shows a new secondary frame with a value of 3 when button 3 is clicked in
 * the main window.
 */
void MainWindow::onButton3Clicked()
{
    m_secondaryFrame = new SecondaryFrame(this, 3);
    m_secondaryFrame->show();
}