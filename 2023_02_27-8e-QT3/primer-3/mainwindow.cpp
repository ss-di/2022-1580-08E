#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cnt = 0;
    s_cnt = "Количество нажатий: %1";
    ui->lblCount->setText(s_cnt.arg(cnt));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPlusOne_clicked()
{
    cnt += 1;
    ui->lblCount->setText(s_cnt.arg(cnt));
}
