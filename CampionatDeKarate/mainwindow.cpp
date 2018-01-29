#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addsportiv.h"
#include "addorganizatie.h"
#include "addcategorievarsta.h"
#include "addcompetitie.h"
#include "addcategoriegreutate.h"
//#include "addexperiencecategory.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlField>
#include <QSqlRecord>
#include <QSettings>
#include <QActionGroup>
#include <QItemSelectionModel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_tableActions = new QActionGroup(this);
    m_tableActions->addAction(ui->actionTables);
    m_tableActions->addAction(ui->actionOrganizatie);
    m_tableActions->addAction(ui->actionCompetitie);
    m_tableActions->addAction(ui->actionVarsta);
    m_tableActions->addAction(ui->actionGreutate);
   // m_tableActions->addAction(ui->actionExperience);
    m_tableActions->addAction(ui->actionJoin_Table);
    //m_tableActions->addAction(ui->actionNext_Round);

    connect(m_tableActions, &QActionGroup::triggered, this, &MainWindow::onTableActionsTriggered);
    connect(ui->actionAdd_Item, &QAction::triggered, this, &MainWindow::onAddItem);
    connect(ui->actionAdd_Organizatie, &QAction::triggered, this, &MainWindow::onAddOrganizatie);
    connect(ui->actionAdd_Competitie, &QAction::triggered, this, &MainWindow::onAddCompetitie);
    connect(ui->actionAdd_Categorie_Varsta, &QAction::triggered, this, &MainWindow::onAddCategorieVarsta);
    connect(ui->actionAdd_Categorie_Greutate, &QAction::triggered, this, &MainWindow::onAddCategorieGreutate);
    //connect(ui->actionAdd_Experience_Category, &QAction::triggered, this, &MainWindow::onAddExperienceCategory);

    m_AddSportiv = new AddSportiv(this);
    m_addOrganizatie = new AddOrganizatie(this);
    m_addCategorieVarsta = new AddCategorieVarsta(this);
    m_addCategorieGreutate = new AddCategorieGreutate(this);
    m_addCompetitie = new AddCompetitie(this);
   // m_addExperienceCategory = new AddExperienceCategory(this);

    QString hostName = "baasu.db.elephantsql.com";
    QString databaseName = "fimgdyzt";
    QString userName = "fimgdyzt";
    QString password = "I8x7_EzP_5NeQBBQWgkqEaJdUMkRrEsE";
    readSettings(hostName, databaseName, userName, password);
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName(hostName);
    m_db.setDatabaseName(databaseName);
    m_db.setUserName(userName);
    m_db.setPassword(password);
    bool ok = m_db.open();
    if(!ok)
    {
        ui->statusBar->showMessage(tr("Database not connected!"));
        cout<<m_db.lastError().databaseText().toStdString();
        cout<< m_db.lastError().driverText().toStdString();
    }
    else
    {
        ui->statusBar->showMessage(tr("Database connected!"));
    }
    setupModel();
    ui->tablePersons->setModel(m_personsModel);
    ui->tableSim->setModel(m_sportivJoinChampModel);
    ui->tableOrganizatie->setModel(m_organizatieModel);
    ui->tableCompetitie->setModel(m_competitieModel);
    ui->tableVarsta->setModel(m_varstaModel);
    ui->tableGreutate->setModel(m_greutateModel);
    //ui->tableExperience->setModel(m_experienceModel);
    connect(ui->actionRefresh, &QAction::triggered, this, &MainWindow::onRefreshDB);
    connect(ui->actionNext_Round, &QAction::triggered, this, &MainWindow::onNextRound);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSettings(QString &hostName, QString &databaseName, QString &userName, QString &password)
{
    qDebug() << "App dir path " << qApp->applicationDirPath();
    QSettings s(qApp->applicationDirPath() + "/DBTests.conf", QSettings::IniFormat);
    hostName = s.value("HOSTNAME").toString();
    databaseName = s.value("DATABASENAME").toString();
    userName = s.value("USERNAME").toString();
    password = s.value("PASSWORD").toString();
    qDebug() << "Settings file name " << s.fileName();
}

void MainWindow::onAddItem()
{
    m_AddSportiv->setType(AddSportiv::AddType::ADD_PERSON);
    int r = m_AddSportiv->exec();
    if(r == QDialog::Accepted)
    {
        QString id;
        QString nume;
        QString prenume;
        QString varsta;
        QString greutate;
        QString experienta;
        QString id_organizatie;
        QString id_competitie;

        m_AddSportiv->data(id, nume, prenume, varsta, greutate, experienta,id_organizatie,id_competitie);
        insertQuery(id, nume, prenume, varsta, greutate, experienta,id_organizatie,id_competitie);
    }
}

void MainWindow::onAddOrganizatie()
{
    m_addOrganizatie->setType(AddOrganizatie::AddType::ADD_PERSON);
    int r = m_addOrganizatie->exec();
    if(r == QDialog::Accepted)
    {
        QString id_organizatie;
        QString denumire;
        QString adresa;
        m_addOrganizatie->data(id_organizatie, denumire, adresa);
        insertQuery(id_organizatie, denumire, adresa);
    }
}
void MainWindow::onAddCategorieVarsta()
{
    m_addCategorieVarsta->setType(AddCategorieVarsta::AddType::ADD_PERSON);
    int r = m_addCategorieVarsta->exec();
    if(r == QDialog::Accepted)
    {
        QString id_varsta;
        QString prag_min;
        QString prag_max;
        m_addCategorieVarsta->data(id_varsta, prag_min, prag_max);
        insertQuery1(id_varsta, prag_min, prag_max);
    }
}

/*void MainWindow::onAddExperienceCategory()
{
    m_addExperienceCategory->setType(AddExperienceCategory::AddType::ADD_PERSON);
    int r = m_addExperienceCategory->exec();
    if(r == QDialog::Accepted)
    {
        QString exp;
        QString experience_id;
        m_addExperienceCategory->data(exp, experience_id);
        insertQuery(exp, experience_id);
    }
}*/

void MainWindow::onAddCategorieGreutate()
{
    m_addCategorieGreutate->setType(AddCategorieGreutate::AddType::ADD_PERSON);
    int r = m_addCategorieGreutate->exec();
    if(r == QDialog::Accepted)
    {
        QString id_greutate;
        QString prag_min;
        QString prag_max;
        m_addCategorieGreutate->data(id_greutate, prag_min, prag_max);
        insertQuery2(id_greutate, prag_min, prag_max);
    }
}

void MainWindow::onAddCompetitie()
{
    m_addCompetitie->setType(AddCompetitie::AddType::ADD_PERSON);
    int r = m_addCompetitie->exec();
    if(r == QDialog::Accepted)
    {
        QString id_competitie;
        QString etapa;
        QString locatie;
        QString puncte_participare;
        QString puncte_runda;
        QString puncte_semifinala;
        QString puncte_finala;
        m_addCompetitie->data(id_competitie,  etapa,  locatie,
                                puncte_participare, puncte_runda,
                                puncte_semifinala, puncte_finala);
        insertQuery(id_competitie,  etapa,  locatie,
                    puncte_participare, puncte_runda,
                    puncte_semifinala, puncte_finala);
    }
}

void MainWindow::onRefreshDB()
{
    selectQuery();
}

void MainWindow::setupModel()
{
    // model Participanti
    ui->tablePersons->setSelectionMode(QAbstractItemView::SingleSelection);
    m_personsModel = new QSqlTableModel(this, m_db);
    m_personsModel->setTable("Participanti");
//  m_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    m_personsModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_personsModel->setHeaderData(0, Qt::Horizontal, tr("Id"));
    m_personsModel->setHeaderData(1, Qt::Horizontal, tr("Nume"));
    m_personsModel->setHeaderData(2, Qt::Horizontal, tr("Prenume"));
    m_personsModel->select();

    // model oraganizatii
    ui->tableOrganizatie->setSelectionMode(QAbstractItemView::SingleSelection);
    m_organizatieModel = new QSqlTableModel(this, m_db);
    m_organizatieModel->setTable("organizatie");
//  m_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    m_organizatieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_organizatieModel->setHeaderData(0, Qt::Horizontal, tr("Id"));
    m_organizatieModel->setHeaderData(1, Qt::Horizontal, tr("Denumire"));
    m_organizatieModel->setHeaderData(2, Qt::Horizontal, tr("Adresa"));
    m_organizatieModel->select();

    // model categorii varsta
    ui->tableVarsta->setSelectionMode(QAbstractItemView::SingleSelection);
    m_varstaModel = new QSqlTableModel(this, m_db);
    m_varstaModel->setTable("age");
//  m_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    m_varstaModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_varstaModel->setHeaderData(0, Qt::Horizontal, tr("Id Varsta"));
    m_varstaModel->setHeaderData(1, Qt::Horizontal, tr("Prag min"));
    m_varstaModel->setHeaderData(2, Qt::Horizontal, tr("Prag max"));
    m_varstaModel->select();

    // model categorii greutate
    ui->tableGreutatet->setSelectionMode(QAbstractItemView::SingleSelection);
    m_greutateModel = new QSqlTableModel(this, m_db);
    m_greutateModel->setTable("greutate");
//  m_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    m_greutateModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_greutateModel->setHeaderData(0, Qt::Horizontal, tr("Id Greutate"));
    m_greutateModel->setHeaderData(1, Qt::Horizontal, tr("Prag min"));
    m_greutateModel->setHeaderData(2, Qt::Horizontal, tr("Prag max"));
    m_greutateModel->select();

    /*// model categorii experienta
    ui->tableExperience->setSelectionMode(QAbstractItemView::SingleSelection);
    m_experienceModel = new QSqlTableModel(this, m_db);
    m_experienceModel->setTable("experience");
//  m_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    m_experienceModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_experienceModel->setHeaderData(0, Qt::Horizontal, tr("Id"));
    m_experienceModel->setHeaderData(1, Qt::Horizontal, tr("Experience"));
    m_experienceModel->select();
*/
    // model competitie
    ui->tableCompetitie->setSelectionMode(QAbstractItemView::SingleSelection);
    m_competitieModel = new QSqlTableModel(this, m_db);
    m_competitieModel->setTable("competitie");
//  m_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    m_competitieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_competitieModel->setHeaderData(0, Qt::Horizontal, tr("Id"));
    m_competitieModel->setHeaderData(1, Qt::Horizontal, tr("Etapa"));
    m_competitieModel->setHeaderData(2, Qt::Horizontal, tr("Locatie"));
    m_competitieModel->setHeaderData(3, Qt::Horizontal, tr("Puncte Participare"));
    m_competitieModel->setHeaderData(4, Qt::Horizontal, tr("Puncte Runda"));
    m_competitieModel->setHeaderData(5, Qt::Horizontal, tr("Puncte Semifinala"));
    m_competitieModel->setHeaderData(6, Qt::Horizontal, tr("Puncte Finala"));
    m_competitieModel->select();


    m_sportivJoinChampModel = new QSqlQueryModel(this);
    QSqlQuery query("SELECT Sportivi.nume, Sportivi.prenume, competitie.puncte_participare, competitie.puncte_runda, competitie.puncte_semifinala, competitie.puncte_finala FROM Sportivi INNER JOIN competitie ON Sportivi.id_competitie=competitie.id_competitie");
    m_sportivJoinChampModel->setQuery(query);
    m_sportivJoinChampModel->setHeaderData(0, Qt::Horizontal, tr("Nume"));
    m_sportivJoinChampModel->setHeaderData(1, Qt::Horizontal, tr("Prenume"));
    m_sportivJoinChampModel->setHeaderData(2, Qt::Horizontal, tr("Puncte Participare"));
    m_sportivJoinChampModel->setHeaderData(3, Qt::Horizontal, tr("Puncte Runda"));
    m_sportivJoinChampModel->setHeaderData(4, Qt::Horizontal, tr("Puncte Semifinala"));
    m_sportivJoinChampModel->setHeaderData(5, Qt::Horizontal, tr("Puncte Finala"));
    //m_participantJoinChampModel->select();
}

// introduce sportiv
void MainWindow::insertQuery(const QString &id, const QString &nume, const QString &prenume,
                             const QString &varsta, const QString &greutate, const QString &experienta,
                              const QString &id_organizatie, const QString &id_competitie)
{
    QSqlField idField("sportiv_id", QVariant::Int);
    QSqlField numeField("nume", QVariant::String);
    QSqlField prenumeField("prenume", QVariant::String);
    QSqlField varstaField("varsta", QVariant::Int);
    QSqlField greutateField("greutate", QVariant::Int);
    QSqlField experientaField("experienta", QVariant::String);
    QSqlField Id_greutateField("id_greutate", QVariant::Int);
    QSqlField Id_varstaField("id_varsta", QVariant::Int);
    QSqlField Id_organizatieField("id_organizatie", QVariant::Int);
    QSqlField Id_competitieField("competitie_id", QVariant::Int);

    idField.setValue(id);
    numeField.setValue(nume);
    prenumeField.setValue(prenume);
    varstaField.setValue(varsta);
    greutateField.setValue(greutate);
    experientaField.setValue(experienta);
    int Id_greutate = calculateIdGreutate(greutateField.value().toInt());
    int Id_varsta = calculateIdVarsta(varstaField.value().toInt());
    Id_greutateField.setValue(Id_greutate);
    Id_varstaField.setValue(Id_varsta);
    Id_organizatieField.setValue(id_organizatie);
    Id_competitieField.setValue(id_competitie);

    QSqlRecord record;
    record.append(idField);
    record.append(numeField);
    record.append(prenumeField);
    record.append(varstaField);
    record.append(greutateField);
    record.append(experientaField);
    record.append(Id_greutateField);
    record.append(Id_varstaField);
    record.append(Id_organizatieField);
    record.append(Id_competitieField);

    m_personsModel->insertRecord(-1, record);
    if(!m_personsModel->submitAll())
    {
        ui->statusBar->showMessage(tr("Values not submitted to remote database!"));
         qDebug()<< m_personsModel->lastError();
    }
    else
    {
        ui->statusBar->showMessage(tr("Values submitted to remote database."));
    }
}


// introduce organiatie
void MainWindow::insertQuery(const QString &id_organizatie, const QString &denumire, const QString &adresa)
{
    QSqlField id_organizatieField("id_organizatie", QVariant::Int);
    QSqlField denumireField("denumire", QVariant::String);
    QSqlField adresaField("adresa", QVariant::String);
    id_organizatieField.setValue(id_organizatie);
    denumireField.setValue(denumire);
    adresaField.setValue(adresa);
    QSqlRecord record;
    record.append(id_organizatieField);
    record.append(denumireField);
    record.append(adresaField);
    m_organizatieModel->insertRecord(-1, record);
    if(!m_organizatieModel->submitAll())
    {
        ui->statusBar->showMessage(tr("Values not submitted to remote database!"));
    }
    else
    {
        ui->statusBar->showMessage(tr("Values submitted to remote database."));
    }
}

/*// introduce experienta
void MainWindow::insertQuery(const QString &exp, const QString &experience_id)
{
    QSqlField idField("experience_id", QVariant::Int);
    QSqlField expField("exp", QVariant::String);
    idField.setValue(experience_id);
    expField.setValue(exp);
    QSqlRecord record;
    record.append(idField);
    record.append(expField);
    m_experienceModel->insertRecord(-1, record);
    if(!m_experienceModel->submitAll())
    {
        ui->statusBar->showMessage(tr("Values not submitted to remote database!"));
    }
    else
    {
        ui->statusBar->showMessage(tr("Values submitted to remote database."));
    }
}*/

// adauga categorie varsta
void MainWindow::insertQuery1(const QString &id_varsta, const QString &prag_min, const QString &prag_max)
{
    QSqlField idField("id_varsta", QVariant::Int);
    QSqlField prag_minField("prag_min", QVariant::Int);
    QSqlField prag_maxField("prag_max", QVariant::Int);
    idField.setValue(id_varsta);
    prag_minField.setValue(prag_min);
    prag_maxField.setValue(prag_max);
    QSqlRecord record;
    record.append(idField);
    record.append(prag_minField);
    record.append(prag_maxField);
    m_varstaModel->insertRecord(-1, record);
    if(!m_varstaModel->submitAll())
    {
        ui->statusBar->showMessage(tr("Values not submitted to remote database!"));

    }
    else
    {
        ui->statusBar->showMessage(tr("Values submitted to remote database."));
    }
}

// adauga categorie greutate
void MainWindow::insertQuery2(const QString &id_greutate, const QString &prag_min, const QString &prag_max)
{
    QSqlField idField("id_greutate", QVariant::Int);
    QSqlField prag_minField("prag_min", QVariant::Int);
    QSqlField prag_maxField("prag_max", QVariant::Int);
    idField.setValue(id_greutate);
    prag_minField.setValue(prag_min);
    prag_maxField.setValue(prag_max);
    QSqlRecord record;
    record.append(idField);
    record.append(prag_minField);
    record.append(prag_maxField);
    m_greutateModel->insertRecord(-1, record);
    if(!m_greutateModel->submitAll())
    {
        ui->statusBar->showMessage(tr("Values not submitted to remote database!"));
    }
    else
    {
        ui->statusBar->showMessage(tr("Values submitted to remote database."));
    }
}

// adauga competitie
void MainWindow::insertQuery(const QString &id_competitie, const QString &etapa, const QString &locatie,
                             const QString &puncte_participare, const QString &puncte_runda,
                             const QString &puncte_semifinala, const QString &puncte_finala)
{
    QSqlField idField("id_competitie", QVariant::Int);
    QSqlField etapaField("etapa", QVariant::String);
    QSqlField locatieField("locatie", QVariant::String);
    QSqlField puncte_participareField("puncte_participare", QVariant::Int);
    QSqlField puncte_rundaField("puncte_runda", QVariant::Int);
    QSqlField puncte_semifinalaField("puncte_semifinala", QVariant::Int);
    QSqlField puncte_finalaField("puncte_finala", QVariant::Int);
    idField.setValue(id_competitie);
    etapaField.setValue(etapa);
    locatieField.setValue(locatie);
    puncte_participareField.setValue(puncte_participare);
    puncte_rundaField.setValue(puncte_runda);
    puncte_semifinalaField.setValue(puncte_semifinala);
    puncte_finalaField.setValue(puncte_finala);
    QSqlRecord record;
    record.append(idField);
    record.append(etapaField);
    record.append(locatieField);
    record.append(puncte_participareField);
    record.append(puncte_rundaField);
    record.append(puncte_semifinalaField);
    record.append(puncte_finalaField);
    m_competitieModel->insertRecord(-1, record);
    if(!m_competitieModel->submitAll())
    {
        ui->statusBar->showMessage(tr("Values not submitted to remote database!"));
    }
    else
    {
        ui->statusBar->showMessage(tr("Values submitted to remote database."));
    }
}

int MainWindow::calculateIdGreutate(int greutate){
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM greutate");
    query.exec();
    while(query.next()) {

        int id = query.value("id_greutate").toInt();
        int prag_min = query.value("prag_min").toInt();
        int prag_max = query.value("prag_max").toInt();
        if(greutate <= prag_max && greutate > prag_min ){
            return id;
        }
    }
    return 0;
}

int MainWindow::calculateIdVarsta(int varsta){
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM varsta");
    query.exec();
    while(query.next()) {

        int id = query.value("id_varsta").toInt();
        int prag_min = query.value("prag_min").toInt();
        int prag_max = query.value("prag_max").toInt();
        if(varsta <= prag_max && varsta > prag_min ){
            return id;
        }
    }
    return 0;
}


void MainWindow::selectQuery()
{
    m_personsModel->select();
}

void MainWindow::onNextRound()
{
        QSqlQuery query("SELECT Sportivi.nume, Sportivi.prenume, competitie.puncte_participare, competitie.puncte_runda, competitie.puncte_semifinala, competitie.puncte_finala FROM Sportivi INNER JOIN competitie ON Sportivi.id_competitie=competitie.id_competitie");
        m_sportivJoinChampModel->setQuery(query);
         qDebug() <<query.lastError();
         QTableView *view = new QTableView;
         view->setModel(m_sportivJoinChampModel);
         view->show();
}

void MainWindow::onTableActionsTriggered(QAction *action)
{
    if(action == ui->actionTables)
    {
        ui->stackedGreutate->setCurrentIndex(0);
    }
    if(action == ui->actionOrganizatie)
    {
        ui->stackedGreutate->setCurrentIndex(1);
        ui->tableOrganizatie->selectionModel()->clearSelection();
    }

    if(action == ui->actionCompetitie)
    {
        ui->stackedGreutate->setCurrentIndex(6);
        ui->tableCompetitie->selectionModel()->clearSelection();
    }
    if(action == ui->actionVarsta)
    {
        ui->stackedGreutate->setCurrentIndex(2);
        ui->tableVarsta->selectionModel()->clearSelection();
    }
    if(action == ui->actionGreutate)
    {
        ui->stackedGreutate->setCurrentIndex(3);
        ui->tableVarsta->selectionModel()->clearSelection();
    }
   /* if(action == ui->actionExperinta)
    {
        ui->stackedGreutate->setCurrentIndex(4);
        ui->tableExperienta->selectionModel()->clearSelection();
    }*/
}

