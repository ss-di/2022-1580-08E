#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <cmath>
#define _USE_MATH_DEFINES


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // pi = 180
    ui->setupUi(this);
    for (int i = 0; i < 4; i+=1) {
        int x = 100+100 * cos(360*M_PI/180/4*i);
        int y = 100+- 50 * sin(360*M_PI/180/4*i);
        kv.push_back({x, y, 10, 10});
    }

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


void MainWindow::mousePressEvent(QMouseEvent *e){
    QString s;
    s.setNum(e->pos().x());
    ui->lblX->setText(s);
    s.setNum(e->pos().y());
    ui->lblY->setText(s);
    if (e->buttons() & Qt::LeftButton) {
        kv.push_back({e->pos().x(), e->pos().y(), 10, 10});
    } else if (e->buttons() & Qt::RightButton) {
        kv.pop_back();
    }
    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e){
    QString s;
    s.setNum(e->pos().x());
    ui->lblX->setText(s);
    s.setNum(e->pos().y());
    ui->lblY->setText(s);
    kv.push_back({e->pos().x(), e->pos().y(), 10, 10});
    repaint();

}
