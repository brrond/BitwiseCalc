#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(BitwiseCalcHandler *handler, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    this ->handler = handler;
    ui->setupUi(this);
    ui->EIndex->setText("0");
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_BBin_2_clicked() {
    auto res = handler->execute("bin " + ui->lineEdit->text());
    auto proc_res = res[1].split("\t");
    ui->EBin->setText(proc_res[0]);
    ui->EOct->setText(proc_res[1]);
    ui->EDec->setText(proc_res[2]);
    ui->EHex->setText(proc_res[3]);

    print_command();
}

void MainWindow::on_BOct_2_clicked() {
    auto res = handler->execute("oct " + ui->lineEdit->text());
    auto proc_res = res[1].split("\t");
    ui->EBin->setText(proc_res[0]);
    ui->EOct->setText(proc_res[1]);
    ui->EDec->setText(proc_res[2]);
    ui->EHex->setText(proc_res[3]);

    print_command();
}

void MainWindow::on_BDec_2_clicked() {
    auto res = handler->execute("dec " + ui->lineEdit->text());
    auto proc_res = res[1].split("\t");
    ui->EBin->setText(proc_res[0]);
    ui->EOct->setText(proc_res[1]);
    ui->EDec->setText(proc_res[2]);
    ui->EHex->setText(proc_res[3]);

    print_command();
}

void MainWindow::on_BHex_2_clicked() {
    auto res = handler->execute("hex " + ui->lineEdit->text());
    auto proc_res = res[1].split("\t");
    ui->EBin->setText(proc_res[0]);
    ui->EOct->setText(proc_res[1]);
    ui->EDec->setText(proc_res[2]);
    ui->EHex->setText(proc_res[3]);

    print_command();

}

void MainWindow::on_BNext_clicked() {
    auto t = handler->execute("next")[0].split(" : ");
    if(t.size() == 1){
        return;
    }
    QString res = t[1];
    ui->EIndex->setText(res);

    auto r = handler->execute("get bin " + type)[0];
    ui->EBin->setText(r);
    r = handler->execute("get oct " + type)[0];
    ui->EOct->setText(r);
    r = handler->execute("get dec " + type)[0];
    ui->EDec->setText(r);
    r = handler->execute("get hex " + type)[0];
    ui->EHex->setText(r);
}

void MainWindow::on_BPrev_clicked() {
    auto t = handler->execute("prev")[0].split(" : ");
    if(t.size() == 1){
        return;
    }
    QString res = t[1];
    ui->EIndex->setText(res);

    auto r = handler->execute("get bin " + type)[0];
    ui->EBin->setText(r);
    r = handler->execute("get oct " + type)[0];
    ui->EOct->setText(r);
    r = handler->execute("get dec " + type)[0];
    ui->EDec->setText(r);
    r = handler->execute("get hex " + type)[0];
    ui->EHex->setText(r);
}

void MainWindow::print_command() {
    auto t = handler->execute("print " + type);
    ui->listWidget->clear();
    for(int i = 0; i < t.size(); i++){
        ui->listWidget->addItem(t[i]);
        ui->listWidget->item(i)->setStatusTip(t[i]);
    }
}

void MainWindow::on_BByte_clicked()
{
    type = "b";
    print_command();
}

void MainWindow::on_BWord_clicked()
{
    type = "w";
    print_command();
}

void MainWindow::on_BDWord_clicked()
{
    type = "d";
    print_command();
}

void MainWindow::on_BQWord_clicked()
{
    type = "q";
    print_command();
}



void MainWindow::on_listWidget_clicked(const QModelIndex &index) {
    ui->statusbar->showMessage(ui->listWidget->item(index.row())->text());
}

void MainWindow::on_BByte_2_clicked()
{
    type = "ub";
    print_command();
}

void MainWindow::on_BWord_2_clicked()
{
    type = "uw";
    print_command();
}

void MainWindow::on_BDWord_2_clicked()
{
    type = "ud";
    print_command();
}

void MainWindow::on_BQWord_2_clicked()
{
    type = "uq";
    print_command();
}

void MainWindow::on_BBin_3_clicked()
{

}
