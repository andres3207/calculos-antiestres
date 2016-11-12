#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_radioCircular_clicked();

    void on_radioRectangular_clicked();

    void on_pushButtonCalc_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena= new QGraphicsScene();
};

#endif // MAINWINDOW_H
