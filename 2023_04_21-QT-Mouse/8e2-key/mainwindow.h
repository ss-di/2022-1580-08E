#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

namespace Ui {
class MainWindow;
}

struct Kvadr{
    int x, y;
    int a;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    std::vector<Kvadr> kv {{100, 100, 50}, {20, 100, 20}, {100, 20, 70}};

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
