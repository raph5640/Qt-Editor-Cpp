#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include <QPaintEvent>
#include <QWidget>
#include "codeeditor.h"
/**
 * @class LineNumberArea
 *
 * @brief LineNumberArea est un widget personnalisé pour afficher les numéros de ligne associés à un éditeur de code (Ma nouvelle classe codeeditor)
 *
 * Cette classe est conçue pour fonctionner avec une instance de la classe CodeEditor. Elle se charge d'afficher les numéros de ligne pour chaque bloc de texte visible dans l'éditeur associé.
 */
class LineNumberArea : public QWidget
{
    Q_OBJECT
public:
    explicit LineNumberArea(CodeEditor *editor);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    CodeEditor *codeEditor;
};

#endif // LINENUMBERAREA_H
