#ifndef CREDITBOXDIALOG_H
#define CREDITBOXDIALOG_H

#include <QDialog>

namespace Ui {
class CreditBoxDialog;
}

class CreditBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreditBoxDialog(QWidget *parent = nullptr);
    ~CreditBoxDialog();

private:
    Ui::CreditBoxDialog *ui;
private slots:
    void fermer_box();
};

#endif // CREDITBOXDIALOG_H
