#include "modiftrait.h"
#include "ui_modiftrait.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>

ModifTrait::ModifTrait(QWidget *parent, const QString num_trait) :
    QWidget(parent),
    ui(new Ui::ModifTrait)
{
    ui->setupUi(this);
    this->setWindowTitle("Modification de Traitements");

    ui->numeroTraitMod->setText(num_trait);
    QString nTrait= ui->numeroTraitMod->text();



    QSqlQuery query;
    query.prepare("SELECT n_traitement, n_medecin, n_patient, nbjour, date_consultation FROM traitement where n_traitement=:nTrait");
    query.bindValue(":nTrait",nTrait);
    query.exec();

    if(query.next()){
        ui->n_medTr->setText(query.value("n_medecin").toString());
        ui->n_patTrait->setText(query.value("n_patient").toString());
        ui->nbJoursTr->setValue(query.value("nbjour").toInt());
        ui->dateDebTr->setDate(query.value("date_consultation").toDate());
    }
}

ModifTrait::~ModifTrait()
{
    delete ui;
}

void ModifTrait::on_modTrait_clicked()
{
    QString num=ui->numeroTraitMod->text();
    QString nMedecinTraitMod=ui->n_medTr->text();
    QString nPatTraitMod =ui->n_patTrait->text();
    int nbJoursMod = ui->nbJoursTr->value();
    QDate dateMod =ui ->dateDebTr->date();

    if(num.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR", "LE NUMERO NE PEUT PAS ETRE VIDE!!");
    }else
    if(nMedecinTraitMod.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR", "LE NUMERO MEDECIN NE PEUT PAS ETRE VIDE!!");
    }else

    if(nPatTraitMod.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR", "LE NUMERO PATIENT NE PEUT PAS ETRE VIDE!!");
    }

    else{

           QSqlQuery query;

                 query.prepare("SELECT n_medecin FROM medecin where n_medecin=:med");
                 query.bindValue(":med",nMedecinTraitMod);
                 query.exec();
                 if(!query.next()){
                        QMessageBox::critical(nullptr,"INVALID", "LE NUMERO MEDECIN N'EXISTE PAS!");
                 }else {
                     query.prepare("SELECT n_patient FROM patient where n_patient=:pat");
                     query.bindValue(":pat",nPatTraitMod);
                     query.exec();
                     if(!query.next()){
                            QMessageBox::critical(nullptr,"INVALID", "LE NUMERO PATIENT N'EXISTE PAS!");
                     }else {
                         query.prepare("UPDATE traitement SET n_medecin =:med, n_patient =:pat,nbjour =:jour, date_consultation=:deb WHERE n_traitement =:num");
                         query.bindValue(":med", nMedecinTraitMod);
                         query.bindValue(":pat", nPatTraitMod);
                         query.bindValue(":jour", nbJoursMod);
                         query.bindValue(":deb", dateMod);
                         query.bindValue(":num", num);
                         query.exec();

             QMessageBox::information(nullptr,"REUSSI", "La mise a jours est finie");
             this->close();
                            }
                         }
                      }
            }


void ModifTrait::on_annModTr_clicked()
{
    this->close();
}




