#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::ifstream f("data.txt");
    int a, b;
    f >> a >> b;
    QString s;
    s.setNum(a);
    ui->edtNum->setText(s);

    s.setNum(b);
    ui->edtNum_2->setText(s);

    f.close();

}

MainWindow::~MainWindow()
{
    std::ofstream f("data.txt");
    f << ui->edtNum->text().toInt();
    f << " ";
    f << ui->edtNum_2->text().toInt();
    f.close();

    delete ui;
}

void MainWindow::on_btnAbout_clicked()
{
    About about_window;
    about_window.exec();
}

void MainWindow::on_btnSave_clicked()
{
    std::ofstream f("data.txt");

    f << ui->edtNum->text().toInt();

    /*
     * int a = ui->edtNum->text().toInt();
     * f << a;
     */

    f.close();
}


void MainWindow::on_btnLoad_clicked()
{
    std::ifstream f("data.txt");
    int a;
    f >> a;
    QString s;
    s.setNum(a);
    ui->edtNum->setText(s);
    f.close();
}
