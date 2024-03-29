#include <QApplication>
#include "mainwindow.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

using namespace std;

/**
 * The function initializes a GUI application and sets up a serial port for communication.
 * 
 * @param argc The number of command line arguments passed to the program, including the name of the
 * program itself.
 * @param argv The `argv` parameter is an array of strings that contains the command line arguments
 * passed to the program. The first element (`argv[0]`) is the name of the program itself, and
 * subsequent elements contain any additional arguments passed to the program.
 * 
 * @return the value of `app.exec()`, which is the exit code of the Qt application event loop. This
 * value is typically used to indicate the success or failure of the application.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();

    /* Setting other Port Stuff */
    int serial_port = open("/dev/ttyACM0", O_RDWR);
    struct termios tty;
    memset(&tty, 0, sizeof tty);

    /* Error Handling */
    if (tcgetattr(serial_port, &tty) != 0) {
        cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << endl;
        return 1;
    }

    /* Set Baud Rate */
    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);
    tty.c_cflag &= ~PARENB; /* No Parity */
    tty.c_cflag &= ~CSTOPB; /* 1 Stop Bit */
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8; /* 8 Bits */
    tty.c_cflag &= ~CRTSCTS; /* No flow control */
    tty.c_lflag = 0; /* No signaling */
    tty.c_oflag = 0; /* No signaling */

    /* Reading stuff */
    tty.c_cc[VMIN] = 1; /* Wait until at least 1 character is received */
    tty.c_cc[VTIME] = 5; /* Wait 0.5 seconds before timeout */

    /* Save tty settings, also checking for error */
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        cout << "Error " << errno << " from tcsetattr" << endl;
        return 1;
    }

}