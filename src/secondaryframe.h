#ifndef SECONDARYFRAME_H
#define SECONDARYFRAME_H

#include <QDialog>
#include <QLabel>

class SecondaryFrame : public QDialog
{
    Q_OBJECT

public:
    SecondaryFrame(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QLabel *m_imageLabel;
};

#endif // SECONDARYFRAME_H