#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Msg.h"
#include "mythread.h"
#include"msgrecivetask.h"
#include"ShdMemSendTask.h"
#include"piperecievetask.h"
#include"SocketRecvTask.h"
#include"param.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    taskList[0]=new ShdMemSendTask();
    taskList[1]=new MsgReciveTask();
    taskList[2]=new PipeRecieveTask();
    taskList[3]=new SocketRecvTask();

    taskList[0]->init();
    taskList[1]->init();

    ui->setupUi(this);
    bg=new QButtonGroup(this);
    bg->addButton(ui->radioButton,0);
    bg->addButton(ui->radioButton_2,1);
    bg->addButton(ui->radioButton_3,2);
    bg->addButton(ui->radioButton_4,3);
    ui->radioButton->setChecked(true);
    connect(bg, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onButtonClicked(QAbstractButton*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked(QAbstractButton *button){
    int sel=bg->checkedId();
    getParam(sel);
}

int MainWindow::getParam(int sel){
    bool ok;
    switch(sel){
    case 0:
    {
        int num = QInputDialog::getInt(this,QObject:: tr("key"),QObject:: tr("请输入key"),0,0,200000,1,&ok);
                if(ok)
                {
                    Param::Shdkey=num;
                }else{
                    return 1;
                }
        break;
    }
    case 1:
    {
        int num = QInputDialog::getInt(this,QObject:: tr("key"),QObject:: tr("请输入key"),0,0,200000,1,&ok);
                if(ok)
                {
                    Param::mqkey=num;
                }else{
                    return 1;
                }
        break;
    }
    case 2:
    {
        // /tmp/hjw_pipe
        QString text = QInputDialog::getText(this, tr("pip name:"),
                                             tr("pip name:"), QLineEdit::Normal,
                                             "/tmp/hjw_pipe", &ok);
        if(ok&&!text.isEmpty()){
            Param::pipname=text;
        }else{
            return 1;
        }


        break;
    }
    case 3:
    {
        QString ip = QInputDialog::getText(this, tr("IP"),
                                             tr("IP:"), QLineEdit::Normal,
                                             "127.0.0.1", &ok);
        if(ok){
            qDebug()<<ip;
        }else{
            return 1;
        }
        QString port = QInputDialog::getText(this, tr("Port"),
                                             tr("Port:"), QLineEdit::Normal,
                                             "6666", &ok);
        if(ok){
            qDebug()<<port;
        }else{
            return 1;
        }
        break;
    }
    }



}




void MainWindow::on_startListenButton_clicked()
{



    ui->startListenButton->setEnabled(false);
    int sel=bg->checkedId();

    QMutex mutex;
    MyThread myThread(&mutex,taskList[sel]);
    myThread.start();

    run=true;
    while (true) {
        mutex.lock();
        if(myThread.isFull()){
            QString msg=myThread.getData();
            qDebug()<<"recive:"<<msg;
            ui->textEdit->append(msg);
        }
        mutex.unlock();
        if(!run){
            myThread.quit();
            while (!myThread.isFinished()) {
                myThread.usleep(100000);
                QCoreApplication::processEvents(QEventLoop::AllEvents,100);
            }
            break;
        }
        myThread.usleep(500000);
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        qDebug()<<"run";
    }
    qDebug()<<"quit method";


}

void MainWindow::on_stopListenButton_clicked()
{
    run=false;
    ui->startListenButton->setEnabled(true);
    qDebug()<<"stop";
}

//void MainWindow::on_pushButton_clicked()
//{
//    taskList[2]->recv();
//    QString s=taskList[2]->getData();
//    qDebug()<<s;
//}


void MainWindow::on_clearButton_clicked()
{
    ui->textEdit->setText("");
}
