#include "medecin.h"
#include "ui_medecin.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>
medecin::medecin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medecin)
{
    ui->setupUi(this);
    this->setWindowTitle("Fenêtre Médecin");
}

medecin::~medecin()
{
    delete ui;
}

void medecin::on_Ajouter_clicked()
{
   QString formNumeroMed = ui->formNumeroMed->text();
   QString formNomMed = ui->formNomMed->text();
   QString formTauxMed = ui->formTauxMed->text();



    QSqlQuery query;
   query.prepare("SELECT n_medecin FROM medecin where n_medecin= :numeroMed");
    query.bindValue(":numeroMed", formNumeroMed);
    query.exec();
    if(formNumeroMed.isEmpty()){
        QMessageBox::critical(nullptr,"INVALIDE","LE CHAMP NUMERO EST A REMPLIR!!");
    }
    else if(query.next()){
        QMessageBox::critical(nullptr,"INVALIDE","Le numéro existe déjà");
    }
    else if (formNomMed.isEmpty()){
         QMessageBox::critical(nullptr, "INVALID", "Nom a remplir");
        }else if(formTauxMed.isEmpty()){
                QMessageBox::critical(nullptr,"INVALID", "TAUX ABSENT");
            }else
                {    query.prepare("INSERT into medecin (n_medecin, nom, taux_journalier)VALUES(:numeroMed, :nom, :taux) ");
                     query.bindValue(":numeroMed",formNumeroMed);
                     query.bindValue(":nom",formNomMed);
                     query.bindValue(":taux",formTauxMed);

                    query.exec();

                QMessageBox::information(nullptr,"RÉUSSI","Ajout réussi");
                this->close();
                  }
 }



void medecin::on_AnulerMed_clicked()
{
    this->close();
}

