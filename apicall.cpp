#include "apicall.h"
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextBrowser>

Q_DECLARE_METATYPE(QJsonDocument)

apiCall::apiCall(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *topLayout = new QHBoxLayout;
    cityEdit = new QLineEdit;
    cityEdit->setPlaceholderText("Укажите город");
    QPushButton *callButton = new QPushButton("Запросить");
    connect(callButton, SIGNAL(clicked()), this, SLOT(apiClick()));
    topLayout->addWidget(cityEdit);
    topLayout->addWidget(callButton);
    QHBoxLayout *botLayout = new QHBoxLayout;
    apiBrowser = new QTextBrowser;
    botLayout->addWidget(apiBrowser);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(botLayout);

}

void apiCall::apiClick()
{
    QString city = cityEdit->text();
    QNetworkAccessManager Manager;
    QString keke = "http://api.weatherapi.com/v1/current.json?key=3550410010fb4e9ea7c05942230108&q=" + city;
    QUrl APIurl(keke);
    QNetworkRequest request(APIurl);
    QNetworkReply *reply = Manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString weather = reply->readAll();
    QJsonObject jsonObject = QJsonDocument::fromJson(weather.toUtf8()).object();
    QString country = jsonObject["location"].toObject()["country"].toString();
    QString name = jsonObject["location"].toObject()["name"].toString();
    double temp_c = jsonObject["current"].toObject()["temp_c"].toDouble();
    double wind_kph = jsonObject["current"].toObject()["wind_kph"].toDouble();
    QString condition = jsonObject["current"].toObject()["condition"].toObject()["text"].toString();
    int humidity = jsonObject["current"].toObject()["humidity"].toInt();

    QString answer = QString("Страна: \"%1\"\nГород: \"%2\"\nТемпература: %3°C\nВлажность: %4%\nОписание: %5\nСкорость ветра: %6м/с")
                        .arg(country)
                        .arg(name)
                        .arg(temp_c)
                        .arg(humidity)
                        .arg(condition)
                        .arg(wind_kph);

    apiBrowser->setText(answer);

}
