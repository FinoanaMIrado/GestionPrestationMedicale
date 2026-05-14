#ifndef MODIFMED_H
#define MODIFMED_H


#include <QWidget>
#include"mainwindow.h"

namespace Ui {
class ModifMed;
}

class ModifMed : public QWidget
{
    Q_OBJECT

public:
    explicit ModifMed(QWidget *parent = nullptr, const QString &num_Med = 0);
    ~ModifMed();

private slots:
    void on_modMed_clicked();

    void on_annMod_clicked();

private:
    Ui::ModifMed *ui;
};

#endif // MODIFMED_H
