#include "widget.h"
#include <QPushButton>
#include <QLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    eleWin = new elemUprav;
    welcomePage = new welcome;
    filesisa = new fileSyste;
    HTTPcall = new apiCall;
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    //левая часть
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QPushButton *leftElement = new QPushButton("Элементы управления");
    leftElement->setFixedHeight(40);
    connect(leftElement, SIGNAL(clicked()), this, SLOT(elementUprav()));
    QPushButton *leftBD = new QPushButton("База данных");
    leftBD->setFixedHeight(40);
    leftBD->setEnabled(false);
    connect(leftBD, SIGNAL(clicked()), this, SLOT(elementUprav()));
    QPushButton *leftHTTP = new QPushButton("HTTP");
    leftHTTP->setFixedHeight(40);
    connect(leftHTTP, SIGNAL(clicked()), this, SLOT(callHTTP()));
    QPushButton *leftFile = new QPushButton("Файловая система");
    leftFile->setFixedHeight(40);
    connect(leftFile, SIGNAL(clicked()), this, SLOT(fileSys()));
    QPushButton *leftCam = new QPushButton("Веб-камера");
    leftCam->setFixedHeight(40);
    leftCam->setEnabled(false);
    connect(leftCam, SIGNAL(clicked()), this, SLOT(elementUprav()));
    leftLayout->addWidget(leftElement);
    leftLayout->addWidget(leftBD);
    leftLayout->addWidget(leftHTTP);
    leftLayout->addWidget(leftFile);
    leftLayout->addWidget(leftCam);



    //правая часть
    QVBoxLayout *rightLayout = new QVBoxLayout;
    testButtons = new QVBoxLayout;
    testButtons->addWidget(welcomePage);
    elementLayout = new QVBoxLayout;
    elementLayout->addWidget(eleWin);
    eleWin->hide();
    fileLayout = new QVBoxLayout;
    fileLayout->addWidget(filesisa);
    filesisa->hide();
    HTTPLayout = new QVBoxLayout;
    HTTPLayout->addWidget(HTTPcall);
    HTTPcall->hide();


    rightLayout->addLayout(testButtons);
    rightLayout->addLayout(elementLayout);
    rightLayout->addLayout(fileLayout);
    rightLayout->addLayout(HTTPLayout);

    mainLayout->addLayout(leftLayout, 1);
    mainLayout->addLayout(rightLayout, 3);

}

Widget::~Widget()
{

}

void Widget::elementUprav(){
    welcomePage->hide();
    filesisa->hide();
    HTTPcall->hide();
    eleWin->show();
}

void Widget::fileSys(){
    welcomePage->hide();
    eleWin->hide();
    HTTPcall->hide();
    filesisa->show();
}

void Widget::callHTTP(){
    welcomePage->hide();
    eleWin->hide();
    filesisa->hide();
    HTTPcall->show();
}
