#include "traitement.h"
#include "ui_traitement.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>

traitement::traitement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::traitement)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout de traitement");
}

traitement::~traitement()
{
    delete ui;
}

void traitement::on_AjoutTraitement_clicked()
{
    QString formNumTraitement = ui->formTraitement->text();
    QString formNumMedTraitement = ui->formNumMedTraitement->text();
    QString formNumPatTraitement = ui->formNumPatientTraitement->text();
    int jrs = ui->formNombreDeJours->value();
    QDate formDateDeDebutTraitement = ui->formDateDeDebutTraitement->date();



     QSqlQuery query;
      query.prepare("SELECT n_traitement FROM traitement where n_traitement= :Ntrait");
      query.bindValue(":Ntrait", formNumTraitement);
      query.exec();
    if (formNumTraitement.isEmpty()){
        QMessageBox::critical(nullptr,"INVALIDe", "l'id NUMERO DOIT ETRE REMPLI!!");
    }
    else if(query.next()){
          QMessageBox::critical(nullptr,"INVALIDE","Le numéro traitement existe déjà");
      }

      else
      {
          query.prepare("SELECT n_medecin FROM medecin where n_medecin= :NMed");
          query.bindValue(":NMed",formNumMedTraitement);
          query.exec();
            if(!query.next())
                 {
                      QMessageBox::critical(nullptr,"INVILADE","Numéro médecin inéxistant");
                  }else
                         {
                            query.prepare("SELECT n_patient FROM patient where n_patient= :NPat");
                            query.bindValue(":NPat",formNumPatTraitement);
                            query.exec();
                                  if(!query.next()){
                                                         QMessageBox::critical(nullptr,"INVILADE","Numéro patient inéxistant");
                                                   }else
                                                         {
                                                           query.prepare("INSERT INTO traitement (n_traitement, n_medecin, n_patient, nbjour, date_consultation) "
                                                                         "VALUES (:Ntrait, :NMed, :NPat, :NJour, :NDate)");

                                                           query.bindValue(":Ntrait", formNumTraitement);
                                                           query.bindValue(":NMed", formNumMedTraitement);
                                                            query.bindValue(":NPat", formNumPatTraitement);
                                                            query.bindValue(":NJour", jrs);
                                                            query.bindValue(":NDate", formDateDeDebutTraitement);


                                                            query.exec();
                                                            QMessageBox::information(nullptr,"RÉUSSI","Ajout réussi");
                                                               this->close();
                                                          }

                           }
            }

//         if (!query.exec()) {
//             qDebug() << "Erreur d'insertion:" << query.lastError().text();
//         } else {
//             qDebug() << "Insertion réussie!";
//         }

}


void traitement::on_pushButton_3_clicked()
{
    this->close();
}

