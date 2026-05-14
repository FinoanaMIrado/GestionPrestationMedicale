#ifndef PATIENT_H
#define PATIENT_H

#include <QWidget>

namespace Ui {
class patient;
}

class patient : public QWidget
{
    Q_OBJECT

public:
    explicit patient(QWidget *parent = nullptr);
    ~patient();

private slots:
    void on_AjouterPatient_clicked();

    void on_AnulerPat_clicked();

private:
    Ui::patient *ui;
};

#endif // PATIENT_H
