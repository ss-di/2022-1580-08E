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
    int cnt;
    QString s_cnt;

private slots:
    void on_btnPlusOne_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
