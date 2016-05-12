#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QtCore>
#include <QMainWindow>
#include <Qpushbutton>
#include <QLabel>
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer *timer;
    int score, x[6];
    int card[25], i, j;
    double playtime;
    bool ever;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void MySlot();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *);
};

#endif // MAINWINDOW_H
