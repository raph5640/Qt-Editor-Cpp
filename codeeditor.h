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
class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    CodeEditor(QWidget *parent = nullptr);
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int getFixedLineNumberWidth() const { return FIXED_LINE_NUMBER_WIDTH; }

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void updateLineNumberArea(const QRect &, int dy);

private:
    const int FIXED_LINE_NUMBER_WIDTH = 50;
    QWidget *lineNumberArea;
};

#endif // CODEEDITOR_H
