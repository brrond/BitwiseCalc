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


void MainWindow::on_BSet_clicked()
{
    QString command;

    if(ui->radioButton->isChecked()){
        command = "bin ";
    }
    else if(ui->radioButton_2->isChecked()){
        command = "oct ";
    }
    else if(ui->radioButton_3->isChecked()){
        command = "dec ";
    }
    else{
        command = "hex ";
    }

    auto res = handler->execute(command + ui->lineEdit->text());
    auto proc_res = res[1].split("\t");
    ui->EBin->setText(proc_res[0]);
    ui->EOct->setText(proc_res[1]);
    ui->EDec->setText(proc_res[2]);
    ui->EHex->setText(proc_res[3]);

    print_command();
}

void MainWindow::on_BAdd_clicked()
{
    QString command;

    if(ui->radioButton->isChecked()){
        command = "bin ";
    }
    else if(ui->radioButton_2->isChecked()){
        command = "oct ";
    }
    else if(ui->radioButton_3->isChecked()){
        command = "dec ";
    }
    else{
        command = "hex ";
    }

    handler->execute("add " + command + ui->lineEdit->text());

    ui->EBin->setText(handler->execute("get bin d")[0]);
    ui->EOct->setText(handler->execute("get oct d")[0]);
    ui->EDec->setText(handler->execute("get dec d")[0]);
    ui->EHex->setText(handler->execute("get hex d")[0]);

    print_command();
}

void MainWindow::on_BSub_clicked()
{
    QString command;

    if(ui->radioButton->isChecked()){
        command = "bin ";
    }
    else if(ui->radioButton_2->isChecked()){
        command = "oct ";
    }
    else if(ui->radioButton_3->isChecked()){
        command = "dec ";
    }
    else{
        command = "hex ";
    }

    handler->execute("sub " + command + ui->lineEdit->text());

    ui->EBin->setText(handler->execute("get bin d")[0]);
    ui->EOct->setText(handler->execute("get oct d")[0]);
    ui->EDec->setText(handler->execute("get dec d")[0]);
    ui->EHex->setText(handler->execute("get hex d")[0]);

    print_command();
}

void MainWindow::on_BMul_clicked()
{
    QString command;

    if(ui->radioButton->isChecked()){
        command = "bin ";
    }
    else if(ui->radioButton_2->isChecked()){
        command = "oct ";
    }
    else if(ui->radioButton_3->isChecked()){
        command = "dec ";
    }
    else{
        command = "hex ";
    }

    handler->execute("mul " + command + ui->lineEdit->text());

    ui->EBin->setText(handler->execute("get bin d")[0]);
    ui->EOct->setText(handler->execute("get oct d")[0]);
    ui->EDec->setText(handler->execute("get dec d")[0]);
    ui->EHex->setText(handler->execute("get hex d")[0]);

    print_command();
}

void MainWindow::on_BDiv_clicked()
{
    QString command;

    if(ui->radioButton->isChecked()){
        command = "bin ";
    }
    else if(ui->radioButton_2->isChecked()){
        command = "oct ";
    }
    else if(ui->radioButton_3->isChecked()){
        command = "dec ";
    }
    else{
        command = "hex ";
    }

    handler->execute("div " + command + ui->lineEdit->text());

    ui->EBin->setText(handler->execute("get bin d")[0]);
    ui->EOct->setText(handler->execute("get oct d")[0]);
    ui->EDec->setText(handler->execute("get dec d")[0]);
    ui->EHex->setText(handler->execute("get hex d")[0]);

    print_command();
}
