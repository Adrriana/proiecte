#include "addsportiv.h"
#include "ui_addSportiv.h"

#include <QMessageBox>

AddSportiv::AddSportiv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSportiv),
    m_type(AddSportiv::AddType::ADD_PERSON)
{
    ui->setupUi(this);
}

AddSportiv::~AddSportiv()
{
    delete ui;
}

void AddSportiv::setData(const QString &id, const QString &nume, const QString &prenume,
                            const QString &varsta, const QString &greutate, const QString &experienta, const QString &id_organizatie, const QString &id_competitie)
{
    ui->id->setText(id);
    ui->nume->setText(nume);
    ui->prenume->setText(prenume);
    ui->varsta->setText(varsta);
    ui->greutate->setText(greutate);
    ui->experienta->setText(experienta);
    ui->id_organizatie->setText(id_organizatie);
    ui->id_competitie->setText(id_competitie);
}

void AddSportiv::data(QString &id, QString &nume, QString &prenume,
                          QString &varsta,  QString &greutate,  QString &experienta,  QString &id_organizatie,  QString &id_competitie)
{
    id = ui->id->text();
    nume = ui->nume->text();
    prenume = ui->prenume->text();
    varsta = ui->varsta->text();
    greutate = ui->greutate->text();
    experienta = ui->experienta->text();
    id_organizatie = ui->id_organizatie->text();
    id_competitie = ui->id_competitie->text();
}

void AddSportiv::accept()
{
    bool ok = true;

    if(m_type == AddType::ADD_PERSON)
    {
        ui->id->text().toInt(&ok);
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

void AddSportiv::showEvent(QShowEvent *)
{
    if(m_type == AddType::ADD_PERSON)
    {
        setData("", "", "", "", "", "", "", "");
        ui->id->setEnabled(true);
        ui->nume->setEnabled(true);
        ui->prenume->setEnabled(true);
        ui->varsta->setEnabled(true);
        ui->greutate->setEnabled(true);
        ui->experienta->setEnabled(true);
        ui->id_organizatie->setEnabled(true);
        ui->id_competitie->setEnabled(true);

    }

    if(m_type == AddType::ADD_HOURS)
    {
        ui->id->setEnabled(false);
        ui->nume->setEnabled(false);
        ui->prenume->setEnabled(false);
        ui->varsta->setEnabled(false);
        ui->greutate->setEnabled(false);
        ui->experienta->setEnabled(false);
        ui->id_organizatie->setEnabled(false);
        ui->id_competitie->setEnabled(false);
    }
}

void AddSportiv::setType(AddType type)
{
    m_type = type;
}


