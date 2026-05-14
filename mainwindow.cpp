#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>

#include"medecin.h"
#include"patient.h"
#include"traitement.h"
#include"etatdeprestation.h"
#include"listepatient.h"
#include"listemedecinconsulter.h"
#include"modifmed.h"
#include"modipat.h"
#include"modiftrait.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setWindowTitle("Fenêtre principale");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    medecin *wh = new medecin(nullptr);

    wh -> setAttribute(Qt::WA_DeleteOnClose);
    wh -> show();
}

void MainWindow::on_pushButton_15_clicked()
{
    patient *wh = new patient(nullptr);

    wh -> setAttribute(Qt::WA_DeleteOnClose);
    wh -> show();
}


void MainWindow::on_pushButton_16_clicked()
{
    traitement *wh = new traitement(nullptr);

    wh -> setAttribute(Qt::WA_DeleteOnClose);
    wh -> show();
}


void MainWindow::on_pushButton_5_clicked()
{
    QSqlQuery query("SELECT n_medecin, nom, taux_journalier FROM medecin");

   ui-> affichelistmedecin->setRowCount(0);
    int row = 0;

    while (query.next()) {
       ui-> affichelistmedecin->insertRow(row);

       ui-> affichelistmedecin->setItem(row, 0, new QTableWidgetItem(query.value("n_medecin").toString()));
        ui-> affichelistmedecin->setItem(row, 1, new QTableWidgetItem(query.value("nom").toString()));
      ui->  affichelistmedecin->setItem(row, 2, new QTableWidgetItem(query.value("taux_journalier").toString()));

        row++;
    }




}


void MainWindow::on_pushButton_14_clicked()
{
    QSqlQuery query("SELECT n_patient, nom, adresse FROM patient");


   ui-> affichelistpatient->setRowCount(0);
    int row = 0;

    while (query.next()) {
       ui-> affichelistpatient->insertRow(row);

       ui-> affichelistpatient->setItem(row, 0, new QTableWidgetItem(query.value("n_patient").toString()));
        ui-> affichelistpatient->setItem(row, 1, new QTableWidgetItem(query.value("nom").toString()));
      ui->  affichelistpatient->setItem(row, 2, new QTableWidgetItem(query.value("adresse").toString()));

        row++;
    }

}


void MainWindow::on_pushButton_17_clicked()
{
    QSqlQuery query("SELECT n_traitement, n_medecin, n_patient, nbjour, date_consultation FROM traitement");

    ui->affichelisttraitement->setRowCount(0);
    int row = 0;

    while (query.next()) {
        ui->affichelisttraitement->insertRow(row);
        ui->affichelisttraitement->setItem(row, 0, new QTableWidgetItem(query.value("n_traitement").toString()));
        ui->affichelisttraitement->setItem(row, 1, new QTableWidgetItem(query.value("n_medecin").toString()));
        ui->affichelisttraitement->setItem(row, 2, new QTableWidgetItem(query.value("n_patient").toString()));
        ui->affichelisttraitement->setItem(row, 3, new QTableWidgetItem(query.value("nbjour").toString()));
        ui->affichelisttraitement->setItem(row, 4, new QTableWidgetItem(query.value("date_consultation").toString()));
        row++;
    }

}


void MainWindow::on_pushButton_7_clicked()
{
    int date_pre=ui->annebox->value()    ;


    etatdeprestation *wh = new etatdeprestation(nullptr, date_pre);

    wh -> setAttribute(Qt::WA_DeleteOnClose);
    wh -> show();



}


void MainWindow::on_pushButton_8_clicked()
{
    listepatient *wh = new listepatient(nullptr);

    wh -> setAttribute(Qt::WA_DeleteOnClose);
    wh -> show();
}


void MainWindow::on_pushButton_11_clicked()
{
    listemedecinconsulter *wh = new listemedecinconsulter(nullptr);

    wh -> setAttribute(Qt::WA_DeleteOnClose);
    wh -> show();
}


void MainWindow::on_btnrecherchemed_clicked()
{
    QString numMed=ui->recherchemedecin->text();
    if(numMed.isEmpty()){
        QMessageBox::critical(nullptr,"VIDE","Le champ de recherche est vide");
    }

    else{
        QSqlQuery query;
        query.prepare("SELECT n_medecin,nom,taux_journalier FROM medecin where n_medecin =:numMed");
        query.bindValue(":numMed",numMed);
        query.exec();
        if(query.next()){
            ui->affichelistmedecin->setRowCount(0);
            int row = 0;
            ui->affichelistmedecin->insertRow(row);
            ui->affichelistmedecin->setItem(row,0, new QTableWidgetItem(query.value("n_medecin").toString()));
            ui->affichelistmedecin->setItem(row,1, new QTableWidgetItem(query.value("nom").toString()));
            ui->affichelistmedecin->setItem(row,2, new QTableWidgetItem(query.value("taux_journalier").toString()));

        }
        else{
            QMessageBox::critical(nullptr,"INVALIDE","Le numéro médecin est absent de la liste");
        }


    }
}


void MainWindow::on_btnrecherchepat_clicked()
{
    QString numPat=ui->recherchepatient->text();
    if(numPat.isEmpty()){
        QMessageBox::critical(nullptr,"VIDE","Le champ de recherche est vide");
    }

    else{
        QSqlQuery query;
        query.prepare("SELECT n_patient,nom,adresse FROM patient where nom =:nomPat");

        query.bindValue(":nomPat",numPat);



        query.exec();
        if(query.next()){
            ui->affichelistpatient->setRowCount(0);
            int row = 0;
            ui->affichelistpatient->insertRow(row);
            ui->affichelistpatient->setItem(row,0, new QTableWidgetItem(query.value("n_patient").toString()));
            ui->affichelistpatient->setItem(row,1, new QTableWidgetItem(query.value("nom").toString()));
            ui->affichelistpatient->setItem(row,2, new QTableWidgetItem(query.value("adresse").toString()));

        }
        else{
            QSqlQuery query;
            query.prepare("SELECT n_patient,nom,adresse FROM patient where adresse=:nomPat");

            query.bindValue(":nomPat",numPat);



            query.exec();
            if(query.next()){
                ui->affichelistpatient->setRowCount(0);
                int row = 0;
                ui->affichelistpatient->insertRow(row);
                ui->affichelistpatient->setItem(row,0, new QTableWidgetItem(query.value("n_patient").toString()));
                ui->affichelistpatient->setItem(row,1, new QTableWidgetItem(query.value("nom").toString()));
                ui->affichelistpatient->setItem(row,2, new QTableWidgetItem(query.value("adresse").toString()));

}
                else{
                    QMessageBox::critical(nullptr,"INVALIDE","Le nom ou adresse patient est absent de la liste");
                     }
            }


    }
}


void MainWindow::on_btnrecherchetrait_clicked()
{
    QString numTrait=ui->recherchetraitement->text();
    if(numTrait.isEmpty()){
        QMessageBox::critical(nullptr,"VIDE","Le champ de recherche est vide");
    }

    else{
        QSqlQuery query;
        query.prepare("SELECT n_traitement,n_medecin,n_patient,nbjour,date_consultation FROM traitement where n_traitement =:numTrait");
        query.bindValue(":numTrait",numTrait);
        query.exec();
        if(query.next()){
            ui->affichelisttraitement->setRowCount(0);
            int row = 0;
            ui->affichelisttraitement->insertRow(row);
            ui->affichelisttraitement->setItem(row,0, new QTableWidgetItem(query.value("n_traitement").toString()));
            ui->affichelisttraitement->setItem(row,1, new QTableWidgetItem(query.value("n_medecin").toString()));
            ui->affichelisttraitement->setItem(row,2, new QTableWidgetItem(query.value("n_patient").toString()));
            ui->affichelisttraitement->setItem(row,3, new QTableWidgetItem(query.value("nbjour").toString()));
            ui->affichelisttraitement->setItem(row,4, new QTableWidgetItem(query.value("date_consultation").toString()));

        }
        else{
            QMessageBox::critical(nullptr,"INVALIDE","Le numéro traitement est absent de la liste");
        }


    }
}


void MainWindow::on_supprMed_clicked()
{
    QString numeroSuppr=ui->recherchemedecin->text();

    if (numeroSuppr.isEmpty()){
        QMessageBox::critical(nullptr,"INVALID", "ENTREZ LE NUMERO DE MEDECIN A SUPRIMER");
    }else {
        QMessageBox::StandardButtons reply;
        reply = QMessageBox::question(nullptr,"Validation", "Supprimer le médecin numero "+numeroSuppr+"?", QMessageBox::Yes | QMessageBox::No);

        if (reply==QMessageBox::No){
            return;
        }else {

            QSqlQuery query;
            query.prepare("DELETE from medecin where n_medecin= :NumSupp");
            query.bindValue(":NumSupp",numeroSuppr);
            query.exec();

            if(query.numRowsAffected()){
                QMessageBox::information(nullptr,"REUSSI", "LA SUPPRESSION C'EST EXECUTER");
                ui->recherchemedecin->clear();
            }else{
                QMessageBox::critical(nullptr,"ERREUR","LE NUMERO SELECTIONNER EST ABSENT DE LA LISTE");
            }

        }

    }

}


void MainWindow::on_supprPat_clicked()
{
    QString numeroSuppr=ui->recherchepatient->text();

    if (numeroSuppr.isEmpty()){
        QMessageBox::critical(nullptr,"INVALID", "ENTREZ PATIENT A SUPRIMER");
    }else {
        QMessageBox::StandardButtons reply;
        reply = QMessageBox::question(nullptr,"Validation", "Supprimer le patient "+numeroSuppr+"?", QMessageBox::Yes | QMessageBox::No);

        if (reply==QMessageBox::No){
            return;
        }else {

            QSqlQuery query;
            query.prepare("DELETE from patient where nom= :NumSupp");
            query.bindValue(":NumSupp",numeroSuppr);
            query.exec();

            if(query.numRowsAffected()){
                QMessageBox::information(nullptr,"REUSSI", "LA SUPPRESSION C'EST EXECUTER");
                ui->recherchepatient->clear();
            }else{
                QMessageBox::critical(nullptr,"ERREUR","LE NOM SELECTIONNER EST ABSENT DE LA LISTE");
            }

        }

    }
}


void MainWindow::on_supprTrait_clicked()
{
    QString numeroSuppr=ui->recherchetraitement->text();

    if (numeroSuppr.isEmpty()){
        QMessageBox::critical(nullptr,"INVALID", "ENTREZ LE NUMERO DE MEDECIN A SUPRIMER");
    }else {
        QMessageBox::StandardButtons reply;
        reply = QMessageBox::question(nullptr,"Validation", "Supprimer le médecin numero "+numeroSuppr+"?", QMessageBox::Yes | QMessageBox::No);

        if (reply==QMessageBox::No){
            return;
        }else {

            QSqlQuery query;
            query.prepare("DELETE from traitement where n_traitement= :NumSupp");
            query.bindValue(":NumSupp",numeroSuppr);
            query.exec();

            if(query.numRowsAffected()){
                QMessageBox::information(nullptr,"REUSSI", "LA SUPPRESSION C'EST EXECUTER");
                ui->recherchetraitement->clear();
            }else{
                QMessageBox::critical(nullptr,"ERREUR","LE NUMERO SELECTIONNER EST ABSENT DE LA LISTE");
            }

        }

    }
}


void MainWindow::on_modifTraitButton_clicked()
{
    QString num_trait= ui->recherchetraitement->text();
    if(num_trait.isEmpty()){
        QMessageBox::critical(nullptr,"INVALIDE", "VEUILLERZ ENTRER LE NUMERO DU TRAITEMENT A MODIFIER!");

    }else{
        QSqlQuery query;
        query.prepare("SELECT n_traitement FROM traitement where n_traitement=:Ntrait" );
        query.bindValue(":Ntrait",num_trait);
        query.exec();

              if(!query.next()){
                                 QMessageBox::critical(nullptr,"INVALIDE", "NUMERO INEXISTANT!");

                               }
                               else{
                                    ModifTrait *wh = new ModifTrait (nullptr, num_trait);

                                    wh->setAttribute(Qt::WA_DeleteOnClose);
                                    wh->show();
                                    }

           }
}


void MainWindow::on_modifMedButon_clicked()
{

    QString num_med= ui->recherchemedecin->text();
    if(num_med.isEmpty()){
        QMessageBox::critical(nullptr,"INVALIDE", "VEUILLEZ ENTRER LE NUMERO DU MEDECIN A MODIFIER!");

    }else{
              QSqlQuery query;
              query.prepare("SELECT n_medecin FROM medecin where n_medecin=:NMed" );
              query.bindValue(":NMed",num_med);
              query.exec();

                    if(!query.next()){
                                       QMessageBox::critical(nullptr,"INVALIDE", "NUMERO INEXISTANT!");

                                     }
                                     else{ModifMed *wh = new ModifMed (nullptr, num_med);

                                          wh->setAttribute(Qt::WA_DeleteOnClose);
                                          wh->show();
                                          }
         }

}


void MainWindow::on_modifPatButton_clicked()
{
    QString num_pat= ui->recherchepatient->text();
    if(num_pat.isEmpty()){
        QMessageBox::critical(nullptr,"INVALIDE", "VEUILLERZ ENTRER LE NOM DU PATIENT A MODIFIER!");

    }else{
        QSqlQuery query;
        query.prepare("SELECT nom FROM patient where nom=:Npat" );
        query.bindValue(":Npat",num_pat);
        query.exec();

              if(!query.next()){
                                 QMessageBox::critical(nullptr,"INVALIDE", "PATIENT INEXISTANT!");

                               }
                               else{    modiPat *wh = new modiPat (nullptr, num_pat);

                                        wh->setAttribute(Qt::WA_DeleteOnClose);
                                        wh->show();
                                    }

           }
}


void MainWindow::on_butonPatTrait_clicked()
{
    listepatient *wh = new listepatient(nullptr);

    wh -> setAttribute(Qt::WA_DeleteOnClose);
    wh -> show();
}


void MainWindow::on_butonMedCons_clicked()
{

    listemedecinconsulter *wh = new listemedecinconsulter(nullptr);

    wh -> setAttribute(Qt::WA_DeleteOnClose);
    wh -> show();

}

