#include "mainwindow.h"

#include <QApplication>
#include <QString>

#include <iostream>
#include <cstring>
#include <algorithm>

#include "bitwisecalchandler.h"

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

    BitwiseCalcHandler handler;

    // CONSOLE MODE
    if(PROGRAM_MODE == CONSOLE) {
        std::string input;
        char *inp = new char[100];
        do{
            cout << "BitwiseCalc > "; cin.getline(inp, 100);//std::getline(cin, input);
            input = std::string(inp);
            auto ret = handler.execute(QString::fromStdString(input));
            std::for_each(ret.begin(), ret.end(), [](QString& str){cout << str.toStdString() << endl;});

        } while(input != "quit");
        return 0;
    }

    // GUI
    QApplication a(argc, argv);
    MainWindow w(&handler);
    w.show();
    return a.exec();
}
