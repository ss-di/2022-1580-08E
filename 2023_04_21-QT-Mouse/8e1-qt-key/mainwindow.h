#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

struct Kvard{
    int x, y;
    int xs, ys;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    std::vector<Kvard> kv{{100, 100, 50, 50}, {50, 100, 20, 30}, {100, 50, 30, 20}};


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
