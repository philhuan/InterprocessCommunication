#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"head.h"

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

    void on_startListenButton_clicked();

    void on_stopListenButton_clicked();


void onButtonClicked(QAbstractButton *button);
//    void on_pushButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    bool run;
    QButtonGroup *bg;
    Task*taskList[4];
    int getParam(int sel);


};

#endif // MAINWINDOW_H
