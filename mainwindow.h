#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPlainTextEdit>
#include <QMainWindow>
#include <QList>
#include <QFile>

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
    Ui::MainWindow *ui;
    QList<QFile*> liste_fichier_ouvert;
    void init_Connections();
    void init_shortcut();
    void close_onglet(int index);
    void sauvegarde_fichier(int index);

private slots:
    void ajouterFichierMenu();
    void creditFichierMenu();
    void editerFichierMenu();
    void sauvegarderFichierActuel();
    void updateCursor();
    void chercherText();
    void remplacerText();
};
#endif // MAINWINDOW_H
