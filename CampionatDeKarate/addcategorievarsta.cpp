#include "addcategorievarsta.h"
#include "ui_addcategorievarsta.h"
#include <QMessageBox>

AddCategorieVarsta::AddCategorieVarsta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCategorieVarsta),
    m_type(AddCategorieVarsta::AddType::ADD_PERSON)
{
    ui->setupUi(this);
}

AddCategorieVarsta::~AddCategorieVarsta()
{
    delete ui;
}

void AddCategorieVarsta::setData(const QString &prag_min, const QString &prag_max, const QString &id_varsta)
{
    ui->prag_min->setText(prag_min);
    ui->prag_max->setText(prag_max);
    ui->id_varsta->setText(id_varsta);
}
void AddCategorieVarsta::data(QString &prag_min, QString &prag_max, QString &id_varsta)
{
    prag_min = ui->prag_min->text();
    prag_max = ui->prag_max->text();
    id_varsta = ui->id_varsta->text();
}

void AddCategorieVarsta::accept()
{
    bool ok = true;

    if(m_type == AddType::ADD_PERSON)
    {
        ui->id_varsta->text().toInt(&ok);
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

void AddCategorieVarsta::showEvent(QShowEvent *)
{
    if(m_type == AddType::ADD_PERSON)
    {
        setData("", "", "");
        ui->id_varsta->setEnabled(true);
        ui->prag_min->setEnabled(true);
        ui->prag_max->setEnabled(true);
    }
}
void AddCategorieVarsta::setType(AddType type)
{
    m_type = type;
}
