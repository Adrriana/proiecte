#ifndef ADDCATEGORIEVARSTA_H
#define ADDCATEGORIEVARSTA_H

#include <QDialog>

namespace Ui {
class AddCategorieVarsta;
}

class AddCategorieVarsta : public QDialog
{
    Q_OBJECT

public:
    enum class AddType
    {
        ADD_PERSON,
        ADD_HOURS
    };

public:
    explicit AddCategorieVarsta(QWidget *parent = 0);
    ~AddCategorieVarsta();

    void setData(const QString &prag_min, const QString &prag_max, const QString &id_varsta);
    void data(QString &prag_min, QString &prag_max, QString &id_varsta);
    void setType(AddType type);

protected:
    void accept() override;
    void showEvent(QShowEvent *);

private:
    Ui::AddCategorieVarsta *ui;
    AddType m_type;
};

#endif // ADDCATEGORIEVARSTA_H
