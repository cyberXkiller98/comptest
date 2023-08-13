#include "welcome.h"
#include "QLayout"
#include "QPushButton"
#include "QGraphicsView"
#include "QGraphicsPixmapItem"
#include "QLabel"

welcome::welcome(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *welcomeLayout= new QVBoxLayout(this);
        QLabel* imageLabel = new QLabel;
        QPixmap pixmap(":/images/img/Sketch_Logo.svg");
        imageLabel->setPixmap(pixmap.scaledToWidth(this->width()/2)); // Использование ширины виджета-родителя
        welcomeLayout->addWidget(imageLabel);
}
