#ifndef LISTEMEDECINCONSULTER_H
#define LISTEMEDECINCONSULTER_H

#include <QWidget>

namespace Ui {
class listemedecinconsulter;
}

class listemedecinconsulter : public QWidget
{
    Q_OBJECT

public:
    explicit listemedecinconsulter(QWidget *parent = nullptr);
    ~listemedecinconsulter();

private slots:
    void on_recherche_clicked();

private:
    Ui::listemedecinconsulter *ui;
};

#endif // LISTEMEDECINCONSULTER_H
