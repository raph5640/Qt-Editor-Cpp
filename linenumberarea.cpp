#include "linenumberarea.h"

LineNumberArea::LineNumberArea(CodeEditor *editor) : QWidget(editor), codeEditor(editor){

}

QSize LineNumberArea::sizeHint() const {
    return QSize(codeEditor->getFixedLineNumberWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    if (show_Line_Number==false) return;
    codeEditor->lineNumberAreaPaintEvent(event);
}

void LineNumberArea::setShowLineNumbers(bool show){
    this->show_Line_Number = show;
    update();
}
