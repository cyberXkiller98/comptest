#ifndef ELEMUPRAV_H
#define ELEMUPRAV_H

#include <QWidget>
#include <QTextBrowser>

class elemUprav : public QWidget
{
    Q_OBJECT
public:
    explicit elemUprav(QWidget *parent = nullptr);

signals:

public slots:
private:
    QTextBrowser *infoBrowser;
    QTextBrowser *numBrowser;
private slots:
    void buttonPush();
    void comboBox(int index);
    void SliderChanged(int value);
    void radio1click();
    void radio2click();
    void radio3click();
};

#endif // ELEMUPRAV_H
