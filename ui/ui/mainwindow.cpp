#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Msg.h"
#include"msgsendtask.h"
#include"shdmemsendtask.h"
#include"PipeSendTask.h"
#include"SocketSendTask.h"
#include"param.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    taskList[0]=new ShdMemSendTask();
    taskList[1]=new MsgSendTask();
    taskList[2]=new PipeSendTask();
    taskList[3]=new SocketSendTask();

    //taskList[]

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

void MainWindow::onButtonClicked(QAbstractButton *button)
{

    int sel=bg->checkedId();

    bool ok;
    switch(sel){
    case 0:
    {
        int num = QInputDialog::getInt(this,QObject:: tr("key"),QObject:: tr("请输入key"),0,0,200000,1,&ok);
                if(ok)
                {
                    Param::Shdkey=num;
                }else{
                    return ;
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
                    return ;
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
            return ;
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
            return ;
        }
        QString port = QInputDialog::getText(this, tr("Port"),
                                             tr("Port:"), QLineEdit::Normal,
                                             "6666", &ok);
        if(ok){
            qDebug()<<port;
        }else{
            return ;
        }
        break;
    }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    int sel=bg->checkedId();
    QString text=ui->textEdit->toPlainText();
    taskList[sel]->send(text);

}
