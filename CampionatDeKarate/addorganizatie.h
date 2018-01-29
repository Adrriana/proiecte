#ifndef ADDORGANIZATIE_H
#define ADDORGANIZATIE_H


#include <QDialog>

namespace Ui {
class AddOrganizatie;
}

class AddOrganizatie : public QDialog
{
    Q_OBJECT

public:
    enum class AddType
    {
        ADD_PERSON,
        ADD_HOURS
    };

public:
    explicit AddOrganizatie(QWidget *parent = 0);
    ~AddOrganizatie();

    void setData(const QString &id_organizatie, const QString &denumire, const QString &adresa);
    void data(QString &id_organizatie, QString &denumire, QString &adresa);
    void setType(AddType type);

protected:
    void accept() override;
    void showEvent(QShowEvent *);

private:
    Ui::AddOrganizatie *ui;
    AddType m_type;
};
#endif // ADDORGANIZATIE_H
