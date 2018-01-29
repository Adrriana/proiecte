#include "addcompetitie.h"
#include "ui_addcompetitie.h"
#include <QMessageBox>

AddCompetitie::AddCompetitie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCompetitie),
    m_type(AddCompetitie::AddType::ADD_PERSON)
{
    ui->setupUi(this);
}

AddCompetitie::~AddCompetitie()
{
    delete ui;
}

void AddCompetitie::setData(const QString &id_competitie, const QString &etapa, const QString &locatie,
                              const QString &puncte_participare, const QString &puncte_runda,
                              const QString &puncte_semifinala, const QString &puncte_finala)
{

    ui->id_competitie->setText(id_competitie);
    ui->etapa->setText(etapa);
    ui->locatie->setText(locatie);
    ui->puncte_participare->setText(puncte_participare);
    ui->puncte_runda->setText(puncte_runda);
    ui->puncte_semifinala->setText(puncte_semifinala);
    ui->puncte_finala->setText(puncte_finala);
}
void AddCompetitie::data(QString &id_competitie,  QString &etapa,  QString &locatie,
                           QString &puncte_participare,  QString &puncte_runda,
                           QString &puncte_semifinala,  QString &puncte_finala)
{
    id_competitie = ui->id_competitie->text();
    etapa = ui->etapa->text();
    locatie = ui->locatie->text();
    puncte_participare = ui->puncte_participare->text();
    puncte_runda = ui->puncte_runda->text();
    puncte_semifinala = ui->puncte_semifinala->text();
    puncte_finala = ui->puncte_finala->text();
}

void AddCompetitie::accept()
{
    bool ok = true;

    if(m_type == AddType::ADD_PERSON)
    {
        ui->id_competitie->text().toInt(&ok);
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

void AddCompetitie::showEvent(QShowEvent *)
{
    if(m_type == AddType::ADD_PERSON)
    {
        setData("", "", "", "", "", "","");
        ui->id_competitie->setEnabled(true);
        ui->etapa->setEnabled(true);
        ui->locatie->setEnabled(true);
        ui->puncte_participare->setEnabled(true);
        ui->puncte_runda->setEnabled(true);
        ui->puncte_semifinala->setEnabled(true);
        ui->puncte_finala->setEnabled(true);
    }
}
void AddCompetitie::setType(AddType type)
{
    m_type = type;
}
