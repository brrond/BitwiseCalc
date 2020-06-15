#ifndef BITWISECALCHANDLER_H
#define BITWISECALCHANDLER_H

#include <QString>
#include <QStringList>
#include <QVector>

enum DataBase {
    BIN = 2,
    OCT = 8,
    DEC = 10,
    HEX = 16
};


struct Data_t{
    QString number;
    DataBase base;
};

class BitwiseCalcHandler {
    QVector<Data_t> DATA;
    size_t index = 0;
public:
    BitwiseCalcHandler();
    QStringList execute(QString command);
};

#endif // BITWISECALCHANDLER_H
