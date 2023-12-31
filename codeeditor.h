#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QWidget>
#include <QPainter>
#include <QTextBlock>
/**
 * @brief Classe CodeEditor qui hérite de QPlainTextEdit afin d'y intégrer une ligne de numérotation comme dans les environnements de développements
 *
 * l'éditeur de code possède une zone de numérotation des lignes. Ce que ne possède pas un QPLainTextEdit classique
 *
 * @param parent Le widget parent.
 */
class CodeEditor : public QPlainTextEdit{
    Q_OBJECT
public:
    CodeEditor(QWidget *parent = nullptr);
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int getFixedLineNumberWidth() const { return largeur; }
    void toggleLineNumberArea(bool visible);
    bool isShowingLineNumbers() const { return showLineNumbers; }

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void updateLineNumberArea(const QRect &, int dy);

private:
    bool showLineNumbers = true;
    const int largeur = 50;
    QWidget *lineNumberArea;
};

#endif // CODEEDITOR_H
