#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "programo.h"

#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_2_textChanged()
{
    ui->textEdit->setPlainText(AldoniCxaretrvenigo(ui->textEdit_2->toPlainText()));
}

void MainWindow::on_actionElektri_dosieron_triggered()
{
    QString dosiernomo = QFileDialog::getOpenFileName(this, QString::fromUtf8("Elekti dosieron"),
                                                      QDir::currentPath(),
                                                      "Teksta dosiero (*.txt);;Ĉiuj dosieroj (*.*)");
    if (dosiernomo != "") {
        QFile edosiero(dosiernomo);
        if (!edosiero.open(QIODevice::ReadOnly)) {
            return;
        }
        QTextStream tksto(&edosiero);
        ui->textEdit_2->setText(tksto.readAll());
        edosiero.close();
    }
}

void MainWindow::on_actionKonservi_kiel_txt_dosieron_triggered()
{
    QString dosiernomo = QFileDialog::getSaveFileName(this, QString::fromUtf8("Konservi dosieron"),
                                                      QDir::currentPath(),
                                                      "Teksta dosiero (*.txt);;Ĉiuj dosieroj (*.*)");
    if (dosiernomo != "") {
        QFile sdosiero(dosiernomo);
        if (!sdosiero.open(QIODevice::WriteOnly)) {

        } else {
            QTextStream strim(&sdosiero);
            strim << ui->textEdit->toPlainText();
            strim.flush();
            sdosiero.close();
        }
    }
}

void MainWindow::on_actionEliri_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionPri_la_programo_htmltekstigilo_triggered()
{
    QMessageBox prila(this);
    prila.setWindowTitle("Informaĵo");
    prila.setTextFormat(Qt::RichText);
    prila.setText("<h2>htmltekstigilo 0.0.1.201022</h2><p>Autoro: arbttrn6 (arturaiwasan[@]gmail.com)</p>\
<p>Ĉi tiu programo aldonas br-etikedo (tag) al finoj de linioj</p><a href='https://github.com/ArturAiwasan/htmltekstigilo-gui'>GitHub</a><br><a href='https://vk.com/btttrn6'>\
VK</a>");
    prila.exec();
}

void MainWindow::on_actionPri_QT_triggered()
{
    QMessageBox::aboutQt(this, "Pri QT");
}
