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

void MainWindow::on_btnAbout_clicked()
{
    QMessageBox::about(this, "О нас", "Пример");
}

void MainWindow::on_btnCritical_clicked()
{
    QMessageBox::critical(this, " Упс...", "Что-то пошло не так...");
}

void MainWindow::on_btnQuestion_clicked()
{
    QMessageBox::StandardButton ans;
    ans = QMessageBox::question(this,
                                "Важный вопрос",
                                "Сегодня подня понедельник?",
                                QMessageBox::Yes | QMessageBox::No | QMessageBox::Help);

    if (ans == QMessageBox::Yes){
        QMessageBox::about(this, "Yes", "");
    } else if (ans == QMessageBox::No){
        QMessageBox::about(this, "No", "");
    } else if (ans == QMessageBox::Help){
        QMessageBox::about(this, "Help", "");
    } else {
        QMessageBox::about(this, "Another", "");
    }

}
