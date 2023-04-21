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
