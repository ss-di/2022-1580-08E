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
    void paintEvent(QPaintEvent *ev);
    int x=200, y=100, a=50, t = 0, dx = +10;
    QTimer *MyTimer;

private slots:
    void on_btnDraw_clicked();
    void slotMyTimerAlarm();

    void on_btnStart_clicked();

    void on_btnStop_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
