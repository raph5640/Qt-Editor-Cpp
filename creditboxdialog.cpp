#include "creditboxdialog.h"
#include "ui_creditboxdialog.h"

CreditBoxDialog::CreditBoxDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditBoxDialog)
{
    ui->setupUi(this);
    ui->labelcredit->setText("Cet editeur de texte a été développé par Raphael De Oliveira");
    QPixmap pixmap(":/images/photo_cv.jpg");
    QPixmap scaledPixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->labelPhoto->setPixmap(scaledPixmap);
    //GITHUB
    QString gitSHA1 = QString("Version : %1").arg(GIT_VERSION);
    QString compileDate = QString("Date dernier commit : %1").arg(__DATE__);
    QString compileTime = QString("Heure du dernier commit : %1").arg(__TIME__);

    ui->labelgithub->setText("git hub : <a href=\"https://github.com/raph5640/QtProjectCpp.git\">GitHub</a>");
    ui->labelgithub->setOpenExternalLinks(true);
    ui->labelSHA1->setText(gitSHA1);
    ui->labelCompileDate->setText(compileDate);
    ui->labelCompileTime->setText(compileTime);

    connect(ui->pushButtonFermer,&QPushButton::clicked, this, &CreditBoxDialog::fermer_box);
}

CreditBoxDialog::~CreditBoxDialog()
{
    delete ui;
}

void CreditBoxDialog::fermer_box(){
    this->close();
}
