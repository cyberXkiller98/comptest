#ifndef WIDGET_H
#define WIDGET_H

#include "elemuprav.h"
#include "welcome.h"
#include "filesyste.h"
#include "apicall.h"
#include <QWidget>
#include <QLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    elemUprav *eleWin;
    welcome *welcomePage;
    fileSyste *filesisa;
    apiCall *HTTPcall;
private:
    QVBoxLayout *testButtons;
    QVBoxLayout *elementLayout;
    QVBoxLayout *fileLayout;
    QVBoxLayout *HTTPLayout;

private slots:
    void elementUprav();
    void fileSys();
    void callHTTP();
};

#endif // WIDGET_H
