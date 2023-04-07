#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    int x=100, y=100, a=50, t = 0, dx = 1;
    QTimer *MyTimer;


private slots:
    void on_btnPrimer_clicked();
    void AlarmSlot();

    void on_btnStart_clicked();

    void on_btnStop_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
