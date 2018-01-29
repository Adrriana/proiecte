#ifndef AddSportiv_H
#define AddSportiv_H

#include <QDialog>

namespace Ui {
class AddSportiv;
}

class AddSportiv : public QDialog
{
    Q_OBJECT

public:
    enum class AddType
    {
        ADD_PERSON,
        ADD_HOURS
    };

public:
    explicit AddSportiv(QWidget *parent = 0);
    ~AddSportiv();

    void setData(const QString &id, const QString &nume, const QString &prenume,
                 const QString &varsta, const QString &greutate, const QString &experienta, const QString &id_organizatie, const QString &id_competitie);
    void data(QString &id, QString &nume, QString &prenume,
               QString &varsta,  QString &greutate,  QString &experienta,  QString &id_organizatie,  QString &id_competitie);
    void setType(AddType type);

protected:
    void accept() override;
    void showEvent(QShowEvent *);

private:
    Ui::AddSportiv *ui;
    AddType m_type;
};

#endif // AddSportiv_H
