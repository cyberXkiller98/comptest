#include "elemuprav.h"
#include <QLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSlider>
#include <QLabel>
#include <QRadioButton>
#include <QTextBrowser>

elemUprav::elemUprav(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *allHere = new QVBoxLayout(this);
    QHBoxLayout *topLayout= new QHBoxLayout;
    //Layout с кнопкой и комбо
    QVBoxLayout *btnNCombo = new QVBoxLayout;
    QPushButton *justButton = new QPushButton("btnName");
    connect(justButton, SIGNAL(clicked()), this, SLOT(buttonPush()));
    QComboBox *justCombo= new QComboBox;
    connect(justCombo, SIGNAL(activated(int)), this, SLOT(comboBox(int)));
    QStringList justList = {"ListName", "ListName 1", "ListName 2", "ListName 3", "ListName 4"};
    justCombo->addItems(justList);
    btnNCombo->addWidget(justButton);
    btnNCombo->addWidget(justCombo);
    //slider layout
    QVBoxLayout *sliderLayout = new QVBoxLayout;
    //slider grid layout
    QGridLayout *sliderGrid= new QGridLayout;
    QSlider *vSlider = new QSlider(Qt::Vertical);
    vSlider->setMaximum(100);
    connect(vSlider, SIGNAL(valueChanged(int)), this, SLOT(SliderChanged(int)));
//    vSlider->setTickPosition(QSlider::TicksBothSides);
//    vSlider->setTickInterval(10);
    QLabel *numLVLLabel = new QLabel("Num LVL");
    QLabel *slider0Label = new QLabel("0");
    QLabel *slider1Label = new QLabel("10");
    QLabel *slider2Label = new QLabel("20");
    QLabel *slider3Label = new QLabel("30");
    QLabel *slider4Label = new QLabel("40");
    QLabel *slider5Label = new QLabel("50");
    QLabel *slider6Label = new QLabel("60");
    QLabel *slider7Label = new QLabel("70");
    QLabel *slider8Label = new QLabel("80");
    QLabel *slider9Label = new QLabel("90");
    QLabel *slider10Label = new QLabel("100");

    sliderGrid->addWidget(numLVLLabel, 0, 0, 1, 0);
    sliderGrid->addWidget(vSlider, 1, 0, 11, 0);
    sliderGrid->addWidget(slider10Label, 1, 1);
    sliderGrid->addWidget(slider9Label, 2, 1);
    sliderGrid->addWidget(slider8Label, 3, 1);
    sliderGrid->addWidget(slider7Label, 4, 1);
    sliderGrid->addWidget(slider6Label, 5, 1);
    sliderGrid->addWidget(slider5Label, 6, 1);
    sliderGrid->addWidget(slider4Label, 7, 1);
    sliderGrid->addWidget(slider3Label, 8, 1);
    sliderGrid->addWidget(slider2Label, 9, 1);
    sliderGrid->addWidget(slider1Label, 10, 1);
    sliderGrid->addWidget(slider0Label, 11, 1);

    sliderLayout->addLayout(sliderGrid);
    //layout с кнопками и цифрой
    QVBoxLayout *twoLayout = new QVBoxLayout;
    //layout с кнопками
    QVBoxLayout *radioLayout = new QVBoxLayout;
    QRadioButton *radioItem1 = new QRadioButton("radioitem 1");
    QObject::connect(radioItem1, SIGNAL(clicked()), this, SLOT(radio1click()));
    radioItem1->setChecked(true);
    QRadioButton *radioItem2 = new QRadioButton("radioitem 2");
    QObject::connect(radioItem2, SIGNAL(clicked()), this, SLOT(radio2click()));
    QRadioButton *radioItem3 = new QRadioButton("radioitem 3");
    QObject::connect(radioItem3, SIGNAL(clicked()), this, SLOT(radio3click()));
    radioLayout->addWidget(radioItem1);
    radioLayout->addWidget(radioItem2);
    radioLayout->addWidget(radioItem3);
    //layout с цифрой
    QHBoxLayout *numberLayout = new QHBoxLayout;
    QLabel *lvlLabel = new QLabel("Уровень =");
    numBrowser = new QTextBrowser;
    numBrowser->setPlaceholderText("Num");
    numBrowser->setFixedSize(40, 25);
    numberLayout->addWidget(lvlLabel);
    numberLayout->addWidget(numBrowser);

    twoLayout->addLayout(radioLayout);
    twoLayout->addLayout(numberLayout);


    topLayout->addLayout(btnNCombo);
    topLayout->addLayout(sliderLayout);
    topLayout->addStretch(1);
    topLayout->addLayout(twoLayout);

    QHBoxLayout *botLayout = new QHBoxLayout;
    infoBrowser = new QTextBrowser;
    botLayout->addWidget(infoBrowser);

    allHere->addLayout(topLayout);
    allHere->addLayout(botLayout);
}


void elemUprav::buttonPush(){
    infoBrowser->setText("Клик по кнопке btnName");
}

void elemUprav::comboBox(int index){
    QString itemName = (index > 0) ? "itemName " + QString::number(index) : "listName";
    infoBrowser->setText("выбран элемент " + itemName + " из списка listName");
}

void elemUprav::SliderChanged(int value){
    numBrowser->setText(QString::number(value));
}

void elemUprav::radio1click(){
    infoBrowser->setText("выбран элемент radioItem 1 из radioName");
}

void elemUprav::radio2click(){
    infoBrowser->setText("выбран элемент radioItem 2 из radioName");
}

void elemUprav::radio3click(){
    infoBrowser->setText("выбран элемент radioItem 3 из radioName");
}
