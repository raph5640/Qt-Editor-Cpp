#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QPlainTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_Connections();
    //ajouterFichierMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_Connections(){
    connect(ui->actionAjouter_fichier_txt, &QAction::triggered, this, &MainWindow::ajouterFichierMenu);
    connect(ui->actionEcriture_de_fichier_txt, &QAction::triggered, this, &MainWindow::ecritureFichierMenu);
    connect(ui->tabWidgetFichier, &QTabWidget::tabCloseRequested, this, &MainWindow::close_onglet);
}

void MainWindow::ajouterFichierMenu(){
    qDebug()<<"lecture fichier menu";
    ui->stackedWidget->setCurrentIndex(0);
    QString nom_fichier = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), "", tr("Fichiers texte (*.txt);;Tous les fichiers (*)"));

    if (!nom_fichier.isEmpty()){
        QFile fichier(nom_fichier);
        if (fichier.open(QIODevice::ReadOnly)){
            QTextStream in(&fichier);
            QString contenu_fichier = in.readAll();
            fichier.close();

            QPlainTextEdit *editor = new QPlainTextEdit;
            editor->setPlainText(contenu_fichier);

            ui->tabWidgetFichier->addTab(editor, QFileInfo(nom_fichier).fileName());
            ui->tabWidgetFichier->setTabsClosable(true);
        }
        else{
            qDebug()<<"Erreur d'ouverture du fichier";
        }
    }
}

void MainWindow::ecritureFichierMenu(){
    qDebug()<<"ecriture fichier menu";
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::close_onglet(int index){
    QWidget *widget = ui->tabWidgetFichier->widget(index);
    ui->tabWidgetFichier->removeTab(index);
    delete widget;  // Libération de la mémoire
}
