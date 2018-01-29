#include "addcategoriegreutate.h"
#include "ui_addcategoriegreutate.h"

#include <QMessageBox>

AddCategorieGreutate::AddCategorieGreutate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCategorieGreutate),
    m_type(AddCategorieGreutate::AddType::ADD_PERSON)
{
    ui->setupUi(this);
}

AddCategorieGreutate::~AddCategorieGreutate()
{
    delete ui;
}

void AddCategorieGreutate::setData(const QString &prag_min, const QString &prag_max, const QString &id_greutate)
{
    ui->prag_min->setText(prag_min);
    ui->prag_max->setText(prag_max);
    ui->id_greutate->setText(id_greutate);
}
void AddCategorieGreutate::data(QString &prag_min, QString &prag_max, QString &id_greutate)
{
    prag_min = ui->prag_min->text();
    prag_max = ui->prag_max->text();
    id_greutate = ui->id_greutate->text();
}

void AddCategorieGreutate::accept()
{
    bool ok = true;

    if(m_type == AddType::ADD_PERSON)
    {
        ui->id_greutate->text().toInt(&ok);
        if(!ok)
        {
            QMessageBox::warning(this, tr("Add Item Error"), tr("Id should be a number"));
        }
        else
        {
            QDialog::accept();
        }
    }
}

void AddWeightCategory::showEvent(QShowEvent *)
{
    if(m_type == AddType::ADD_PERSON)
    {
        setData("", "", "");
        ui->prag_min->setEnabled(true);
        ui->prag_max->setEnabled(true);
        ui->id_greutate->setEnabled(true);
    }
}
void AddWeightCategory::setType(AddType type)
{
    m_type = type;
}
