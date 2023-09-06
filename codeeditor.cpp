#include "codeeditor.h"
#include "linenumberarea.h"
/**
 * @brief Constructeur pour la classe CodeEditor.
 *
 * Initialise l'éditeur de code avec une zone de numérotation des lignes fixe. Connecte également un signal pour la mise à jour de cette zone.
 *
 * @param parent Le widget parent.
 */
CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent){
    lineNumberArea = new LineNumberArea(this);
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumberArea);
    setViewportMargins(largeur, 0, 0, 0);
}
/**
 * @brief Met à jour la zone de numérotation des lignes lors des changements ou des défilements.
 *
 * Si le contenu est déplacé verticalement (dy), fait défiler la zone de numérotation des lignes. Sinon, met simplement à jour le rectangle spécifié.
 *
 * @param rect La zone de l'éditeur qui nécessite une mise à jour.
 * @param dy Le décalage vertical en pixels du contenu.
 */
void CodeEditor::updateLineNumberArea(const QRect &rect, int dy){
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
}
/**
 * @brief Gère les événements de redimensionnement pour s'assurer que la zone de numérotation des lignes est correctement dimensionnée et placée.
 *
 * Adapte la géométrie de la zone de numérotation des lignes à la nouvelle taille de l'éditeur.
 *
 * @param e L'événement de redimensionnement.
 */
void CodeEditor::resizeEvent(QResizeEvent *e){
    QPlainTextEdit::resizeEvent(e);
    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), largeur, cr.height()));
}
/**
 * @brief Dessine les numéros de ligne dans la zone de numérotation des lignes.
 *
 * Cette méthode est appelée pour peindre la zone de numérotation des lignes. Elle dessine les numéros de ligne pour chaque bloc de texte visible.
 *
 * @param event L'événement de peinture.
 */
void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event){
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(), Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}
