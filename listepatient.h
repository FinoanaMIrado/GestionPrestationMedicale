#ifndef LISTEPATIENT_H
#define LISTEPATIENT_H

#include <QWidget>

namespace Ui {
class listepatient;
}

class listepatient : public QWidget
{
    Q_OBJECT

public:
    explicit listepatient(QWidget *parent = nullptr);
    ~listepatient();

private slots:
    void on_rechercherPatTr_clicked();

private:
    Ui::listepatient *ui;
};

#endif // LISTEPATIENT_H
