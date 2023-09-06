//Auteur : Raphael De Oliveira
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPlainTextEdit>
#include <QMainWindow>
#include <QList>
#include <QFile>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**
 * @brief La fenêtre principale de l'application.
 *
 * À partir de cette fenêtre, vous pouvez sélectionner différentes actions via la barre de menu.
 *
 * Menu Fichier :
 * - Editer les fichiers ouverts : permet de se déplacer dans la fenêtre pour éditer des fichiers après les avoir ajoutés.
 * - Ajouter fichier .txt : ouvre un fichier .txt de votre répertoire et l'ajoute à l'ensemble des fichiers ouverts.
 *
 * Menu Edition :
 * - Crédit : vous permet de voir les crédit (createurs de l'application)
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //Mes attributs privé
    Ui::MainWindow *ui;
    QList<QFile*> liste_fichier_ouvert;
    QSettings *editor_settings;
    QList<QAction *> recentFileActs;
    const int MaxRecentFiles = 10;
    //Quelques methodes
    void init_Connections();
    void init_shortcut();
    void init_Enables(bool b=false);
    void close_onglet(int index);
    void sauvegarde_fichier(int index);
    void sauvegarder_sous(int index);

private slots:
    void ouvrirFichierMenu();
    void ajouterFichierMenuText(const QString &fileName = "");
    void creditFichierMenu();
    void editerFichierMenu();
    void sauvegarderFichierActuel();
    void updateCursor();
    void recherche_remplacerText();
    void updateFichierRecent();
    void ouvrirFichierRecent();
    void ouvrirToutFichierRecent();
    void newfile();
    void enregistrer_sous();
};
#endif // MAINWINDOW_H
