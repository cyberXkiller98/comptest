#ifndef FILESYSTE_H
#define FILESYSTE_H

#include <QWidget>
#include <QTextBrowser>

class fileSyste : public QWidget
{
    Q_OBJECT
public:
    explicit fileSyste(QWidget *parent = nullptr);
    void openFile();
    void saveFile();
private slots:
    void comboActivated(int index);

private:
    QString currentFile = "";
    QTextBrowser *absolutBrowser;
    QTextEdit *editText;
signals:

public slots:

};

#endif // FILESYSTE_H
