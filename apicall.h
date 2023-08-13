#ifndef APICALL_H
#define APICALL_H

#include <QWidget>
#include <QLineEdit>
#include <QTextBrowser>
#include <QtNetwork>
#include <QtGui>
#include <QtCore>

class apiCall : public QWidget
{
    Q_OBJECT
public:
    explicit apiCall(QWidget *parent = nullptr);

signals:

public slots:
private:
    QLineEdit *cityEdit;
    QTextBrowser *apiBrowser;

private slots:
    void apiClick();
};

#endif // APICALL_H
