#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <cmath>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
// 180гр = pi rad
    for (int i = 0; i < 180; i += 1){
        int x = 130 + 50*cos(M_PI/180*i);
        int y = 130 - 100*sin(M_PI/180*i);
        kv.push_back({x, y, 10});
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter p(this);
    for (unsigned long long i = 0; i <kv.size(); i += 1)
        p.drawRect(kv[i].x, kv.at(i).y, kv[i].a, kv[i].a);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    QString s;
    s.setNum(event->key());
    ui->lblKey->setText(s);
    if (event->key() == Qt::Key_Right)
        kv[0].x += 10;
    else if (event->key() == Qt::Key_Left)
        kv[0].x -= 10;
    else if (event->key() == Qt::Key_Up)
        kv[1].y -= 10;
    else if (event->key() == Qt::Key_Down)
        kv[1].y += 10;
    repaint();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    QString s;
    s.setNum(event->pos().x());
    ui->lblX->setText(s);
    s.setNum(event->pos().y());
    ui->lblY->setText(s);
    if (event->buttons() & Qt::LeftButton)
        kv.push_back({event->pos().x(), event->pos().y(), 10});
    else if (event->buttons() & Qt::RightButton)
        kv.pop_back();
    repaint();

}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    QString s;
    s.setNum(event->pos().x());
    ui->lblX->setText(s);
    s.setNum(event->pos().y());
    ui->lblY->setText(s);

    kv.push_back({event->pos().x(), event->pos().y(), 10});
    repaint();

}
