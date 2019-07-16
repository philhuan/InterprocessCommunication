#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"head.h"
#include"task.h"
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
    void on_pushButton_clicked();
    void onButtonClicked(QAbstractButton *button);

private:
    Ui::MainWindow *ui;
    QButtonGroup *bg;
    Task* taskList[4];
};

#endif // MAINWINDOW_H
