#include "addorganizatie.h"
#include "ui_addorganizatie.h"

#include <QMessageBox>

AddOrganizatie::AddOrganizatie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddOrganizatie),
    m_type(AddOrganizatie::AddType::ADD_PERSON)
{
    ui->setupUi(this);
}

AddOrganizatie::~AddOrganizatie()
{
    delete ui;
}

void AddOrganizatie::setData(const QString &id_organizatie, const QString &denumire, const QString &adresa)
{
    ui->id_organizatie->setText(id_organizatie);
    ui->denumire->setText(denumire);
    ui->adresa->setText(adresa);
}
void AddOrganizatie::data(QString &id_organizatie, QString &denumire, QString &adresa)
{
    id_organizatie = ui->id_organizatie->text();
    denumire = ui->denumire->text();
    adresa = ui->adresa->text();
}

void AddOrganizatie::accept()
{
    bool ok = true;

    if(m_type == AddType::ADD_PERSON)
    {
        ui->id_organizatie->text().toInt(&ok);
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

void AddOrganizatie::showEvent(QShowEvent *)
{
    if(m_type == AddType::ADD_PERSON)
    {
        setData("", "", "");
        ui->id_organizatie->setEnabled(true);
        ui->denumire->setEnabled(true);
        ui->adresa->setEnabled(true);
    }
}
void AddOrganizatie::setType(AddType type)
{
    m_type = type;
}
