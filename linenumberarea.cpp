#include "linenumberarea.h"

LineNumberArea::LineNumberArea(CodeEditor *editor) : QWidget(editor), codeEditor(editor)
{
    // Pas de changements majeurs ici
}

QSize LineNumberArea::sizeHint() const {
    return QSize(codeEditor->getFixedLineNumberWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    codeEditor->lineNumberAreaPaintEvent(event);
}
