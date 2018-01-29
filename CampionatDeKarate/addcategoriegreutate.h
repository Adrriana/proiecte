#ifndef ADDCATEGORIEGREUTATE_H
#define ADDCATEGORIEGREUTATE_H


#include <QDialog>

namespace Ui {
class AddCategorieGreutate;
}

class AddCategorieGreutate : public QDialog
{
    Q_OBJECT

public:
    enum class AddType
    {
        ADD_PERSON,
        ADD_HOURS
    };

public:
    explicit AddCategorieGreutate(QWidget *parent = 0);
    ~AddCategorieGreutate();

    void setData(const QString &prag_min, const QString &prag_max, const QString &id_greutate);
    void data( QString &prag_min,  QString &prag_max,  QString &id_greutate);
    void setType(AddType type);

protected:
    void accept() override;
    void showEvent(QShowEvent *);

private:
    Ui::AddCategorieGreutate *ui;
    AddType m_type;
};

#endif // ADDCATEGORIEGREUTATE_H
