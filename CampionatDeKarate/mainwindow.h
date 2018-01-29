#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QStandardItemModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include<iostream>
using namespace std;

namespace Ui {
class MainWindow;
}
class AddSportiv;
class QActionGroup;
class AddOrganizatie;
class AddCompetitie;
class AddCategorieVarsta;
class AddCategorieGreutate;
//class AddExperienceCategory;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onAddItem();
    void onAddOrganizatie();
    void onAddCategorieVarsta();
    void onAddCategorieGreutate();
    void onAddCompetitie();
    //void onAddExperienceCategory();
    void onRefreshDB();
    void onNextRound();
    int calculateIdGreutate(int greutate);
    int calculateIdVarsta(int varsta);
    void onTableActionsTriggered(QAction *action);


private:
    void setupModel();
    void insertQuery(const QString &id, const QString &nume, const QString &prenume,
                     const QString &varsta, const QString &greutate, const QString &experienta,
                     const QString &id_organizatie, const QString &id_competitie);
    void insertQuery1(const QString &id_varsta, const QString &prag_min, const QString &prag_max);
   // void insertQuery(const QString &exp, const QString &experience_id);
    void insertQuery2(const QString &id_greutate, const QString &prag_min, const QString &prag_max);
    void insertQuery(const QString &id_organizatie, const QString &denumire, const QString &adresa);
    void insertQuery(const QString &id_competitie, const QString &etapa, const QString &locatie,
                                  const QString &puncte_participare, const QString &puncte_runda,
                                  const QString &puncte_semifinala, const QString &puncte_finala);
    void selectQuery();
    void readSettings(QString &hostName, QString &databaseName, QString &userName, QString &password);

private:
    Ui::MainWindow *ui;
    QActionGroup *m_tableActions;
    AddSportiv *m_AddSportiv;
    AddOrganizatie *m_addOrganizatie;
    AddCompetitie *m_addCompetitie;
    AddCategorieVarsta *m_addCategorieVarsta;
    //AddExperienceCategory *m_addExperienceCategory;
    AddCategorieGreutate *m_addCategorieGreutate;
    QSqlTableModel *m_personsModel;
    QSqlTableModel *m_varstaModel;
    //QSqlTableModel *m_experienceModel;
    QSqlTableModel *m_greutateModel;
    QSqlTableModel *m_organizatieModel;
    QSqlTableModel *m_competitieModel;
    QSqlRelationalTableModel *m_simModel;
    QSqlQueryModel *m_sportivJoinChampModel;
    QSqlDatabase m_db;

};

#endif // MAINWINDOW_H
