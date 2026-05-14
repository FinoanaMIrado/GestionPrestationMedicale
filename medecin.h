#ifndef MEDECIN_H
#define MEDECIN_H

#include <QWidget>

namespace Ui {
class medecin;
}

class medecin : public QWidget
{
    Q_OBJECT

public:
    explicit medecin(QWidget *parent = nullptr);
    ~medecin();

private slots:
    void on_Ajouter_clicked();

    void on_AnulerMed_clicked();

private:
    Ui::medecin *ui;
};

#endif // MEDECIN_H
