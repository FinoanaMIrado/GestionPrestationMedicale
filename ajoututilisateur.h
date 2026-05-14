#ifndef AJOUTUTILISATEUR_H
#define AJOUTUTILISATEUR_H

#include <QWidget>

namespace Ui {
class ajoutUtilisateur;
}

class ajoutUtilisateur : public QWidget
{
    Q_OBJECT

public:
    explicit ajoutUtilisateur(QWidget *parent = nullptr);
    ~ajoutUtilisateur();

private:
    Ui::ajoutUtilisateur *ui;
};

#endif // AJOUTUTILISATEUR_H
