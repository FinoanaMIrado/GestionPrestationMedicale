#ifndef MODIFTRAIT_H
#define MODIFTRAIT_H

#include <QWidget>

namespace Ui {
class ModifTrait;
}

class ModifTrait : public QWidget
{
    Q_OBJECT

public:
    explicit ModifTrait(QWidget *parent = nullptr, const QString num_trait=0);
    ~ModifTrait();

private slots:
    void on_modTrait_clicked();

    void on_annModTr_clicked();

private:
    Ui::ModifTrait *ui;
};

#endif // MODIFTRAIT_H
