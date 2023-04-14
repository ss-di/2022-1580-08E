#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QKeyEvent>

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

void MainWindow::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter p(this);
    for (unsigned long long i = 0; i < kv.size(); i +=1)
        p.drawRect(kv[i].x, kv.at(i).y, kv[i].xs, kv[i].ys);
}

void MainWindow::keyPressEvent(QKeyEvent *e){
    QString s;
    s.setNum(e->key());
    ui->lblKey->setText(s);
    if (e->key() == Qt::Key_Down)
        kv[0].y += 10;
    else if (e->key() == Qt::Key_Up)
        kv[0].y -= 10;
    else if (e->key() == Qt::Key_Left)
        kv[1].x -= 10;
    else if (e->key() == Qt::Key_Right)
        kv[1].x += 10;
    repaint();
}
