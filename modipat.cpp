#include "modipat.h"
#include "ui_modipat.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQueryModel>

modiPat::modiPat(QWidget *parent, const QString &num_pat) :
    QWidget(parent),
    ui(new Ui::modiPat)
{
    ui->setupUi(this);
    this->setWindowTitle("Modification Patient");

    ui->nomPatMod->setText(num_pat);
    QString nPat=ui->nomPatMod->text();


    QSqlQuery query;
    query.prepare("SELECT n_patient, nom, adresse FROM patient where nom=:nPatient");
    query.bindValue(":nPatient", nPat);
    query.exec();

    if(query.next()){
        ui->numPatMod->setText(query.value("n_patient"
                                           "").toString());
        ui->addressMod->setText(query.value("adresse").toString());

                    }else{
                            QMessageBox::critical(nullptr,"INVALIDE", "LE NUMERO EST ABSENT DE LA LISTE");
                         }
}

modiPat::~modiPat()
{
    delete ui;
}

void modiPat::on_modPat_clicked()
{
    QString num=ui->numPatMod->text();
    QString name=ui->nomPatMod->text();
    QString add =ui->addressMod->text();

    if(num.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR", "LE NUMERO NE PEUT PAS ETRE VIDE!!");
    }
    if(name.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR", "LE NOM NE PEUT PAS ETRE VIDE!!");
    }

    if(add.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR", "L'ADRESSE NE PEUT PAS ETRE VIDE!!");
    }




   else{ QSqlQuery query;
    query.prepare("UPDATE patient SET nom =:name, adresse =:add WHERE n_patient =:num");
    query.bindValue(":name", name);
    query.bindValue(":add", add);
    query.bindValue(":num", num);
    query.exec();

    QMessageBox::information(nullptr,"REUSSI", "La mise a jours est finie");}
}


void modiPat::on_annModPat_clicked()
{
    this->close();
}

