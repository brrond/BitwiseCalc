#include "bitwisecalchandler.h"

BitwiseCalcHandler::BitwiseCalcHandler() {
    DATA.push_back(Data_t());
}

QStringList BitwiseCalcHandler::execute(QString command) {
    QStringList argv = command.toLower().split(" ");
    QStringList ret;
    if(argv[0] == "help") {
        ret.push_back("Ok. I'll explain everything.");
        ret.push_back("Commands : ");
        ret.push_back("BIN/OCT/DEC/HEX [number] \t\t\t-\t\tset currenct cell and print it in every base");
        ret.push_back("set {BIN/OCT/DEC/HEX} [number]\t\t\t-\t\tset number to current cell");
        ret.push_back("get {BIN/OCT/DEC/HEX} {U|B/W/D/Q}\t\t-\t\tget (print) number of current cell");
        ret.push_back("next \t\t\t\t\t\t-\t\tgo to next cell");
        ret.push_back("prev \t\t\t\t\t\t-\t\tgo to previous cell");
        ret.push_back("print {U|B/W/D/Q}\t\t\t\t-\t\tprint all numbers like B/W/D/Q");
        ret.push_back("add {BIN/OCT/DEC/HEX} [number]\t\t\t-\t\tadd number to current cell");
        ret.push_back("sub {BIN/OCT/DEC/HEX} [number]\t\t\t-\t\tsubtract number of current cell");
        ret.push_back("mul {BIN/OCT/DEC/HEX} [number]\t\t\t-\t\tmultiply number of current cell");
        ret.push_back("div {BIN/OCT/DEC/HEX} [number]\t\t\t-\t\tdivide number of current cell");
        ret.push_back("That's all");
    }
    else if(argv[0] == "set" && argv.size() == 3) {
        Data_t dat;
        if(argv[1] == "bin")
            dat.base = BIN;
        else if(argv[1] == "oct")
            dat.base = OCT;
        else if(argv[1] == "dec")
            dat.base = DEC;
        else if(argv[1] == "hex")
            dat.base = HEX;
        dat.number = argv[2];
        DATA[index] = dat;
        ret.push_back("Recived : " + DATA[index].number);
    }
    else if(argv[0] == "get" && argv.size() == 3) {
        QString n;
        DataBase b;
        if(argv[1] == "bin")
            b = BIN;
        else if(argv[1] == "oct")
            b = OCT;
        else if(argv[1] == "dec")
            b = DEC;
        else if(argv[1] == "hex")
            b = HEX;

        if(argv[2] == "ub")
            n = QString::number( (DATA[index].number.toInt(nullptr, DATA[index].base) & 127), b);
        else if(argv[2] == "b")
            n = QString::number((int)(char)DATA[index].number.toInt(nullptr, DATA[index].base), b);
        else if(argv[2] == "uw")
            n = QString::number( (DATA[index].number.toInt(nullptr, DATA[index].base) & 32767), b);
        else if(argv[2] == "w")
            n = QString::number(DATA[index].number.toShort(nullptr, DATA[index].base), b);
        else if(argv[2] == "ud") {
            n = QString::number( (DATA[index].number.toInt(nullptr, DATA[index].base) & 2147483647), b);
        }
        else if(argv[2] == "d")
            n = QString::number(DATA[index].number.toInt(nullptr, DATA[index].base), b);
        else if(argv[2] == "uq")
            n = QString::number( (DATA[index].number.toLongLong(nullptr, DATA[index].base) & 9223372036854775807), b);
        else if(argv[2] == "q")
            n = QString::number(DATA[index].number.toLongLong(nullptr, DATA[index].base), b);

        ret.push_back(n);
    }
    else if(argv[0] == "next" && argv.size() == 1) {
        index++;
        DATA.push_back(Data_t());
        ret.push_back("Current index : " + QString::number(index));
    }
    else if(argv[0] == "prev" && argv.size() == 1) {
        if(index == 0)
            ret.push_back("Riched maximum of cells");
        else {
            index--;
            ret.push_back("Current index : " + QString::number(index));
        }
    }
    else if(argv[0] == "print" && argv.size() == 2) {
        for(int i = 0; i < DATA.size(); i++){
            QString str = QString::number(i);
            str.push_back('\t');
            if(argv[1] == "ub") {
                str += QString::number( (DATA[i].number.toInt(nullptr, DATA[i].base) & 127), 2); str.push_back('\t');
                str += QString::number( (DATA[i].number.toInt(nullptr, DATA[i].base) & 127), 8); str.push_back('\t');
                str += QString::number( (DATA[i].number.toInt(nullptr, DATA[i].base) & 127), 10); str.push_back('\t');
                str += QString::number( (DATA[i].number.toInt(nullptr, DATA[i].base) & 127), 16); str.push_back('\t');
            }
            else if(argv[1] == "b") {
                str += QString::number((int)(char)DATA[i].number.toInt(nullptr, DATA[i].base), 2); str.push_back('\t');
                str += QString::number((int)(char)DATA[i].number.toInt(nullptr, DATA[i].base), 8); str.push_back('\t');
                str += QString::number((int)(char)DATA[i].number.toInt(nullptr, DATA[i].base), 10); str.push_back('\t');
                str += QString::number((int)(char)DATA[i].number.toInt(nullptr, DATA[i].base), 16); str.push_back('\t');
            }
            else if(argv[1] == "uw") {
                str += QString::number( (DATA[i].number.toShort(nullptr, DATA[i].base) & 32767), 2); str.push_back('\t');
                str += QString::number( (DATA[i].number.toShort(nullptr, DATA[i].base) & 32767), 8); str.push_back('\t');
                str += QString::number( (DATA[i].number.toShort(nullptr, DATA[i].base) & 32767), 10); str.push_back('\t');
                str += QString::number( (DATA[i].number.toShort(nullptr, DATA[i].base) & 32767), 16); str.push_back('\t');
            }
            else if(argv[1] == "w") {
                str += QString::number(DATA[i].number.toShort(nullptr, DATA[i].base), 2); str.push_back('\t');
                str += QString::number(DATA[i].number.toShort(nullptr, DATA[i].base), 8); str.push_back('\t');
                str += QString::number(DATA[i].number.toShort(nullptr, DATA[i].base), 10); str.push_back('\t');
                str += QString::number(DATA[i].number.toShort(nullptr, DATA[i].base), 16); str.push_back('\t');
            }
            else if(argv[1] == "ud") {
                str += QString::number( (DATA[i].number.toInt(nullptr, DATA[i].base) & 2147483647), 2); str.push_back('\t');
                str += QString::number( (DATA[i].number.toInt(nullptr, DATA[i].base) & 2147483647), 8); str.push_back('\t');
                str += QString::number( (DATA[i].number.toInt(nullptr, DATA[i].base) & 2147483647), 10); str.push_back('\t');
                str += QString::number( (DATA[i].number.toInt(nullptr, DATA[i].base) & 2147483647), 16); str.push_back('\t');
            }
            else if(argv[1] == "d") {
                str += QString::number(DATA[i].number.toInt(nullptr, DATA[i].base), 2); str.push_back('\t');
                str += QString::number(DATA[i].number.toInt(nullptr, DATA[i].base), 8); str.push_back('\t');
                str += QString::number(DATA[i].number.toInt(nullptr, DATA[i].base), 10); str.push_back('\t');
                str += QString::number(DATA[i].number.toInt(nullptr, DATA[i].base), 16); str.push_back('\t');
            }
            else if(argv[1] == "uq") {
                str += QString::number( (DATA[i].number.toLongLong(nullptr, DATA[i].base) & 9223372036854775807), 2); str.push_back('\t');
                str += QString::number( (DATA[i].number.toLongLong(nullptr, DATA[i].base) & 9223372036854775807), 8); str.push_back('\t');
                str += QString::number( (DATA[i].number.toLongLong(nullptr, DATA[i].base) & 9223372036854775807), 10); str.push_back('\t');
                str += QString::number( (DATA[i].number.toLongLong(nullptr, DATA[i].base) & 9223372036854775807), 16); str.push_back('\t');
            }
            else if(argv[1] == "q") {
                str += QString::number(DATA[i].number.toLongLong(nullptr, DATA[i].base), 2); str.push_back('\t');
                str += QString::number(DATA[i].number.toLongLong(nullptr, DATA[i].base), 8); str.push_back('\t');
                str += QString::number(DATA[i].number.toLongLong(nullptr, DATA[i].base), 10); str.push_back('\t');
                str += QString::number(DATA[i].number.toLongLong(nullptr, DATA[i].base), 16); str.push_back('\t');
            }
            ret.push_back(str);
        }
    }
    else if(argv[0] == "add" && argv.size() == 3) {
        Data_t dat;
        if(argv[1] == "bin")
            dat.base = BIN;
        else if(argv[1] == "oct")
            dat.base = OCT;
        else if(argv[1] == "dec")
            dat.base = DEC;
        else if(argv[1] == "hex")
            dat.base = HEX;
        dat.number = argv[2];
        long long tmp = DATA[index].number.toLongLong(nullptr, DATA[index].base);
        tmp += dat.number.toLongLong(nullptr, dat.base);
        DATA[index].number = QString::number(tmp, dat.base);
        DATA[index].base = dat.base;
        ret.push_back(DATA[index].number);
    }
    else if(argv[0] == "sub" && argv.size() == 3) {
        Data_t dat;
        if(argv[1] == "bin")
            dat.base = BIN;
        else if(argv[1] == "oct")
            dat.base = OCT;
        else if(argv[1] == "dec")
            dat.base = DEC;
        else if(argv[1] == "hex")
            dat.base = HEX;
        dat.number = argv[2];
        long long tmp = DATA[index].number.toLongLong(nullptr, DATA[index].base);
        tmp -= dat.number.toLongLong(nullptr, dat.base);
        DATA[index].number = QString::number(tmp, dat.base);
        DATA[index].base = dat.base;
        ret.push_back(DATA[index].number);
    }
    else if(argv[0] == "mul" && argv.size() == 3) {
        Data_t dat;
        if(argv[1] == "bin")
            dat.base = BIN;
        else if(argv[1] == "oct")
            dat.base = OCT;
        else if(argv[1] == "dec")
            dat.base = DEC;
        else if(argv[1] == "hex")
            dat.base = HEX;
        dat.number = argv[2];
        long long tmp = DATA[index].number.toLongLong(nullptr, DATA[index].base);
        tmp *= dat.number.toLongLong(nullptr, dat.base);
        DATA[index].number = QString::number(tmp, dat.base);
        DATA[index].base = dat.base;
        ret.push_back(DATA[index].number);
    }
    else if(argv[0] == "div" && argv.size() == 3) {
        Data_t dat;
        if(argv[1] == "bin")
            dat.base = BIN;
        else if(argv[1] == "oct")
            dat.base = OCT;
        else if(argv[1] == "dec")
            dat.base = DEC;
        else if(argv[1] == "hex")
            dat.base = HEX;
        dat.number = argv[2];
        long long tmp = DATA[index].number.toLongLong(nullptr, DATA[index].base);
        tmp /= dat.number.toLongLong(nullptr, dat.base);
        DATA[index].number = QString::number(tmp, dat.base);
        DATA[index].base = dat.base;
        ret.push_back(DATA[index].number);
    }
    else if((argv[0] == "bin" || argv[0] == "oct" || argv[0] == "dec" || argv[0] == "hex") &&
            (argv.size() == 2)) {
        Data_t dat;
        if(argv[0] == "bin")
            dat.base = BIN;
        else if(argv[0] == "oct")
            dat.base = OCT;
        else if(argv[0] == "dec")
            dat.base = DEC;
        else if(argv[0] == "hex")
            dat.base = HEX;
        dat.number = argv[1];
        DATA[index] = dat;
        ret.push_back("Recived : " + DATA[index].number);
        QString str;
        str += QString::number(DATA[index].number.toLongLong(nullptr, DATA[index].base), 2); str.push_back('\t');
        str += QString::number(DATA[index].number.toLongLong(nullptr, DATA[index].base), 8); str.push_back('\t');
        str += QString::number(DATA[index].number.toLongLong(nullptr, DATA[index].base), 10); str.push_back('\t');
        str += QString::number(DATA[index].number.toLongLong(nullptr, DATA[index].base), 16); str.push_back('\t');
        ret.push_back(str);
    }
    else if(argv[0] == "quit"){

    }
    else {
        ret.push_back("Wrong command. Use help to see command list.");
    }
    return ret;
}
