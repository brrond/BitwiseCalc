#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "bitwisecalchandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(BitwiseCalcHandler *handler, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BBin_2_clicked();

    void on_BOct_2_clicked();

    void on_BDec_2_clicked();

    void on_BHex_2_clicked();

    void on_BNext_clicked();

    void on_BPrev_clicked();

    void on_BByte_clicked();

    void on_BWord_clicked();

    void on_BDWord_clicked();

    void on_BQWord_clicked();

    void on_listWidget_clicked(const QModelIndex &index);

private:
    void print_command();

    QString type = "d";
    BitwiseCalcHandler *handler;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
