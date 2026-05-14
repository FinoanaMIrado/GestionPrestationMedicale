#include "ajoututilisateur.h"
#include "ui_ajoututilisateur.h"

ajoutUtilisateur::ajoutUtilisateur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ajoutUtilisateur)
{
    ui->setupUi(this);
}

ajoutUtilisateur::~ajoutUtilisateur()
{
    delete ui;
}
