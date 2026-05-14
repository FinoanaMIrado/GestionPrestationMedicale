#include "modifmed.h"
#include "ui_modifmed.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQueryModel>

ModifMed::ModifMed(QWidget *parent,const QString &num_med) :
    QWidget(parent),
    ui(new Ui::ModifMed)
{
    ui->setupUi(this);
    this->setWindowTitle("Modification Médecin");

    ui->numero1->setText(num_med);
    QString nMed=ui->numero1->text();


    QSqlQuery query;
    query.prepare("SELECT n_medecin, nom, taux_journalier FROM medecin where n_medecin=:nMed");
    query.bindValue(":nMed", nMed);
    query.exec();

    if(query.next()){
        ui->nomMedMod->setText(query.value("nom").toString());
        ui->tauxMod->setText(query.value("taux_journalier").toString());
    }


}

ModifMed::~ModifMed()
{
    delete ui;
}

void ModifMed::on_modMed_clicked()
{
    QString num=ui->numero1->text();
    QString name=ui->nomMedMod->text();
    QString tx =ui->tauxMod->text();

    if(num.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR", "LE NUMERO NE PEUT PAS ETRE VIDE!!");
    }
    if(name.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR", "LE NOM NE PEUT PAS ETRE VIDE!!");
    }

    if(tx.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR", "LE TAUX NE PEUT PAS ETRE VIDE!!");
    }




   else{ QSqlQuery query;
    query.prepare("UPDATE medecin SET nom =:name, taux_journalier =:tx WHERE n_medecin =:num");
    query.bindValue(":name", name);
    query.bindValue(":tx", tx);
    query.bindValue(":num", num);
    query.exec();

    QMessageBox::information(nullptr,"REUSSI", "La mise a jours est finie");
    this->close();
    }
}


void ModifMed::on_annMod_clicked()
{
    this->close();
}

