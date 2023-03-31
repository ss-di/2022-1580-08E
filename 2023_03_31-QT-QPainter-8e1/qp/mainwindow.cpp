#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *ev){
    Q_UNUSED(ev);
    QPainter p(this);
    p.drawRect(x, y, a, a);
    p.drawPoint(x+5, y+5);
    p.setPen(Qt::green);
    p.drawLine(x+a, y, x, y+a);
    p.setBrush(QBrush(Qt::red, Qt::CrossPattern));
    p.drawEllipse(x, y+a, a*2, a);
    //p.drawArc(x+a, y, a, a, 45*16, 90*16);
    p.drawPie(x+a, y, a, a, 45*16, 90*16);
    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setColor(Qt::red);
    p.setPen(pen);
    p.drawChord(x+a, y, a, a, 45*16, 90*16);
    p.drawText(x, y, "Hi");
    p.eraseRect(x, y, int(a*0.75), a);

}

void MainWindow::on_btnDraw_clicked()
{
    x = ui->edtX->text().toInt();
    y = ui->edtY->text().toInt();
    a = ui->edtA->text().toInt();
    repaint();
}
