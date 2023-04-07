#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString s;
    s.setNum(x);
    ui->edtX->setText(s);
    s.setNum(y);
    ui->edtY->setText(s);
    s.setNum(a);
    ui->edtA->setText(s);
    s.setNum(t);
    ui->lblTimer->setText(s);

    MyTimer = new QTimer();
    connect(MyTimer, SIGNAL(timeout()), this, SLOT(AlarmSlot()));
    MyTimer -> start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPrimer_clicked()
{
    x = ui->edtX->text().toInt();
    y = ui->edtY->text().toInt();
    a = ui->edtA->text().toInt();
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter p(this);
    p.drawRect(x, y, a, a);
    p.drawPoint(x+5, y+5);
    p.setPen(Qt::red);
    p.drawLine(x+a, y, x, y+a);
    p.setBrush(QBrush(Qt::red, Qt::CrossPattern));
    p.drawEllipse(x, y+a, a*2, a);
    // p.drawArc(x+a, y, a, a*2, 45*16, 90*16);
    //p.drawPie(x+a, y, a, a*2, 45*16, 90*16);
    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setColor(Qt::green);
    p.setPen(pen);
    p.drawChord(x+a, y, a, a*2, 45*16, 90*16);
    p.drawText(x, y, "Привет!");
    p.eraseRect(x+5, y+5, a, a);

}

void MainWindow::AlarmSlot()
{
    t += 1;
    QString s;
    s.setNum(t);
    ui->lblTimer->setText(s);

    x+=dx;
    //x = x % 800;
    if (x > 800 && dx > 0 || x<0 && dx <0)
        dx *= -1;
    repaint();

}

void MainWindow::on_btnStart_clicked()
{
    MyTimer -> start(100);
}

void MainWindow::on_btnStop_clicked()
{
    MyTimer -> stop();
}
