#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_textEdit_2_textChanged();

    void on_actionElektri_dosieron_triggered();

    void on_actionKonservi_kiel_txt_dosieron_triggered();

    void on_actionEliri_triggered();

    void on_actionPri_la_programo_htmltekstigilo_triggered();

    void on_actionPri_QT_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
