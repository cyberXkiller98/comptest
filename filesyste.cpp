#include "filesyste.h"
#include <QLayout>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QTextBrowser>
#include <QLabel>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

fileSyste::fileSyste(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *fileLayout = new QVBoxLayout(this);
    QComboBox *choiceBox = new QComboBox;
    connect(choiceBox, SIGNAL(activated(int)), this, SLOT(comboActivated(int)));
    choiceBox->setFixedWidth(130);
    QStringList justList = {"Открыть файл", "Сохранить файл"};
    choiceBox->addItems(justList);
    QLabel *absolutLabel = new QLabel("Абсолютный путь к файлу:");
    absolutBrowser = new QTextBrowser;
    absolutBrowser->setFixedHeight(30);
    QLabel *dannyLabel = new QLabel("Данные из файла:");
    editText = new QTextEdit;
    fileLayout->addWidget(choiceBox);
    fileLayout->addWidget(absolutLabel);
    fileLayout->addWidget(absolutBrowser);
    fileLayout->addWidget(dannyLabel);
    fileLayout->addWidget(editText);
}

void fileSyste::openFile()
{
QString filename = QFileDialog::getOpenFileName(this, "Open the file");
QFile file(filename);
currentFile = filename;

if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
    return;
}

absolutBrowser->setText(filename);
setWindowTitle(filename);

QTextStream in(&file);
QString text = in.readAll();
editText->setText(text);

file.close();
}

void fileSyste::saveFile()
{
QString filename = QFileDialog::getSaveFileName(this, "Save as");
QFile file(filename);

if (!file.open(QFile::WriteOnly | QFile::Text)) {
    QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
    return;
}

currentFile = filename;
setWindowTitle(filename);

QTextStream out(&file);
QString text = editText->toPlainText();
out << text;

file.close();
}

void fileSyste::comboActivated(int index)
{
if (index == 0) {
openFile();
} else if (index == 1) {
saveFile();
}
}
