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

private:
    Ui::MainWindow *ui;
    void init_Connections();
    void close_onglet(int index);

private slots:
    void ajouterFichierMenu();
    void creditFichierMenu();
    void editerFichierMenu();
};
#endif // MAINWINDOW_H
