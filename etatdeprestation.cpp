#include "etatdeprestation.h"
#include "ui_etatdeprestation.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQueryModel>
#include <QMap>
#include <QString>
#include "qcustomplot.h"
#include "diagrammewidget.h"

etatdeprestation::etatdeprestation(QWidget *parent, const int &date_pre) :
    QWidget(parent),
    ui(new Ui::etatdeprestation)
{

    ui->setupUi(this);

    this->setWindowTitle("État des prestations de l'année"+QString::number(date_pre));

    ui->anneepre->setText(QString::number(date_pre));


//    query.prepare("SELECT n_medecin, nom, taux_jornalier, traitement.nbjours FROM medecin JOIN traitement ON medecin.num_med = num_med ");

//    QString numero= query.value("n_medecin").toString();
//    QString nom= query.value("nom").toString();
//    int jours = query.value("nbjours").toInt();



    model = new QSqlQueryModel(this);
    model->setQuery("SELECT n_medecin,nom,prestation FROM medecin");

    QSqlQuery query;
    query.prepare("SELECT medecin.n_medecin, medecin.nom, medecin.taux_journalier,traitement.nbjour FROM medecin "
                  "INNER JOIN traitement ON traitement.n_medecin = medecin.n_medecin WHERE YEAR(date_consultation)=:date");
    query.bindValue(":date",date_pre);
    QMap<QString, int> medecin;

    ui-> affichelistprestmedecin->setRowCount(0);
    int total(0);
    if(query.exec()){
        while (query.next()) {
            int jrs=query.value("nbjour").toInt();
            int tjrs=query.value("taux_journalier").toInt();
            QString n_medecin = query.value("n_medecin").toString();
            int prestation=jrs*tjrs;

            // la verification de l'existence de la clé est automatique
            // grace a qMap
            // verifie si il n_medecin existe dans medecin
            // ajoute la valeur des prestations de celui ci
            medecin[n_medecin] += prestation;

            // afficher total des prestations
            total +=prestation;
        }

        ui->totalpre->setText(QString::number(total));

        //initialise la taille du tableau
        ui-> affichelistprestmedecin->setRowCount(medecin.size()/2);
        int row = 0;


        for (auto it = medecin.constBegin(); it != medecin.constEnd(); ++it)
        {
            QString id = it.key();    // La clé (id du médecin unique)
            int totalPrestation = it.value(); // La valeur (Total des prestations)
            QString nom_medecin = "";

            query.prepare("SELECT nom, n_medecin FROM medecin WHERE n_medecin = :id");
            query.bindValue(":id", id);

            if(query.exec()){
                query.next();
                nom_medecin = query.value("nom").toString();
            }
            else{
                qDebug() << query.lastError();
            }


            //afficher les prestations
            ui-> affichelistprestmedecin->insertRow(row);
            ui-> affichelistprestmedecin->setItem(row, 0, new QTableWidgetItem(id));
            ui-> affichelistprestmedecin->setItem(row, 1, new QTableWidgetItem(nom_medecin));
            ui-> affichelistprestmedecin->setItem(row, 2, new QTableWidgetItem(QString::number(totalPrestation)));

            row++;
        }
    }
    else{
        qDebug()<<query.lastError().text();

    }
}


void etatdeprestation::lister(){

}


etatdeprestation::~etatdeprestation()
{
    delete ui;
}



void etatdeprestation::on_pushButton_clicked()
{

       DiagrammeWidget *diag = new DiagrammeWidget(nullptr);

       diag->show();
}

