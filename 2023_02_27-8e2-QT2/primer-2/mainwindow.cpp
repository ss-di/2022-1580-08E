#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPushMe_clicked()
{
    QMessageBox::StandardButton ans;

    ans = QMessageBox::question(this, "Заголовок", "Текст",
                                QMessageBox::Yes | QMessageBox::Abort | QMessageBox::No);

    if (ans == QMessageBox::Yes)
        QMessageBox::about(this, "YES", "yes");
    else if (ans == QMessageBox::No)
        QMessageBox::about(this, "NO", "no");
    else
        QMessageBox::about(this, "ELSE", "else");

}
