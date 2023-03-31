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
    int x=200, y=100, a=50;

private slots:
    void on_btnDraw_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
