#include "mainwindow.h"

#include <QApplication>
#include <QString>

#include <iostream>
#include <cstring>

#include "dataclass.h"

enum PROGRAM_MODE_TYPE {
    CONSOLE = 0,
    GUI = 1,
    HELP = 2
};

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char *argv[])
{
    PROGRAM_MODE_TYPE PROGRAM_MODE;
    // --help
    // --GUI (launch prog. in GUI mode)
    // number
    //
    // BitwiseCalc --help (console)
    // BitwiseCalc --GUI  (gui)
    // BitwiseCalc (console)

    if(argc == 1) {
        // BitwiseCalc (console)
        PROGRAM_MODE = CONSOLE;
    }
    else if(argc == 2) {
        // BitwiseCalc --help (console)
        // BitwiseCalc --GUI  (gui)
        if(argv[1] == "--GUI") {
            PROGRAM_MODE = GUI;
        }
        else {
            PROGRAM_MODE = HELP;
        }
    }
    else {
        PROGRAM_MODE = HELP;
    }

    // HELP MODE
    if(PROGRAM_MODE == HELP) {
        // HELP HERE
        cout << "Welcome, user" << endl;
        cout << "You can use this program to convert data (numbers) between numeric systems" << endl;
        cout << "You can use BIN, OCT, DEC, HEX for now" << endl;
        cout << "Some possible commands are : " << endl;
        cout << "BitwiseCalc\t\t-\tto run program in console mode" << endl;
        cout << "BitwiseCalc --help\t-\tto run this message" << endl;
        cout << "BitwiseCalc --GUI\t-\tto run program in GUI mode" << endl;
        cout << "Good luck, have fun" << endl;
        return 0;
    }

    // CONSOLE MODE
    if(PROGRAM_MODE == CONSOLE) {
        std::string input;
        do{
            cout << "BitwiseCalc > "; cin >> input;
            cout << "TEST" << endl;
            DataClass a;
            a.set(10, BIN);
            getchar();
        } while(0);//while(input != "quit");
        return 0;
    }

    // GUI
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
