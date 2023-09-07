#include "linenumberarea.h"

LineNumberArea::LineNumberArea(CodeEditor *editor) : QWidget(editor), codeEditor(editor){

}

QSize LineNumberArea::sizeHint() const {
    return QSize(codeEditor->getFixedLineNumberWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    if (!codeEditor->isShowingLineNumbers()) return;
    codeEditor->lineNumberAreaPaintEvent(event);
}

