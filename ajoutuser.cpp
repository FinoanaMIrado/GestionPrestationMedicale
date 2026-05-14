#include "ajoutuser.h"
#include "ui_ajoutuser.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>


ajoutuser::ajoutuser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ajoutuser)
{
    ui->setupUi(this);
}

ajoutuser::~ajoutuser()
{
    delete ui;
}

void ajoutuser::on_btnajouter_clicked()
{ QString user=ui->utilisateur->text();
  QString mdp=ui->motdepasse->text();

  QSqlQuery query;
        query.prepare("INSERT into utilisateurs(nom_utilisateur,mot_de_passe) VALUES(:user,:mdp) ");
        query.bindValue(":user",user);
        query.bindValue(":mdp",mdp);
        query.exec();
         QMessageBox::information(nullptr,"RÉUSSI","Ajout réussi");
         this->close();

}

