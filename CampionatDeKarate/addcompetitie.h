#ifndef ADDCOMPETITIE_H
#define ADDCOMPETITIE_H


#include <QDialog>

namespace Ui {
class AddCompetitie;
}

class AddCompetitie : public QDialog
{
    Q_OBJECT

public:
    enum class AddType
    {
        ADD_PERSON,
        ADD_HOURS
    };

public:
    explicit AddCompetitie(QWidget *parent = 0);
    ~AddCompetitie();

    void setData(const QString &id_competitie, const QString &etapa, const QString &locatie,
                 const QString &puncte_participare, const QString &puncte_runda, const QString &puncte_semifinala, const QString &puncte_finala);
    void data( QString &id_competitie,  QString &etapa,  QString &locatie,
               QString &puncte_participare,  QString &puncte_runda,  QString &puncte_semifinala,  QString &puncte_finala);
    void setType(AddType type);


protected:
    void accept() override;
    void showEvent(QShowEvent *);

private:
    Ui::AddCompetitie *ui;
    AddType m_type;
};

#endif // ADDCOMPETITIE_H
