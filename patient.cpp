#include "patient.h"
#include "ui_patient.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include <QDebug>
#include<QMessageBox>
patient::patient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patient)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Patient");
}

patient::~patient()
{
    delete ui;
}

void patient::on_AjouterPatient_clicked()
{
    QString formNumeroPatient = ui->formNumeroPatient->text();
    QString formNomPatient = ui->formNomPatirnt->text();
    QString formAddressePatient = ui->formAddressePatient->text();

    QSqlQuery query;
    query.prepare("SELECT n_patient FROM patient where n_patient= :numeroPat");
     query.bindValue(":numeroPat", formNumeroPatient);
     query.exec();
    if (formNumeroPatient.isEmpty()){
        QMessageBox::critical(nullptr,"INVALID", "l'id NUMERO DOIT ETRE REMPLI!!");
    }
    else if(query.next()){
         QMessageBox::critical(nullptr,"INVALIDE","Le numéro existe déjà");
     }else {
         query.prepare("SELECT nom FROM patient where nom = :nomP");
         query.bindValue(":nomP", formNomPatient);
         query.exec();
         if (formNomPatient.isEmpty()){
          QMessageBox::critical(nullptr, "INVALID", "Nom a remplir");
         }else{  query.prepare("INSERT into patient(n_patient, nom, adresse) VALUES(:numeroPat ,:nom ,:adresse) ");
                 query.bindValue(":numeroPat",formNumeroPatient);
                 query.bindValue(":nom",formNomPatient);
                 query.bindValue(":adresse",formAddressePatient);

                 query.exec();
                 QMessageBox::information(nullptr,"RÉUSSI","Ajout réussi");
                 this->close();
     }




     }
//    if (!query.exec()) {
//        qDebug() << "Erreur d'insertion:" << query.lastError().text();
//    } else {
//        qDebug() << "Insertion réussie!";
//    }

}





void patient::on_AnulerPat_clicked()
{
    this->close();
}

