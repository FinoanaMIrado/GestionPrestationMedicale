#include "listemedecinconsulter.h"
#include "ui_listemedecinconsulter.h"
#include <QtSql>
#include <QSqlDatabase>

listemedecinconsulter::listemedecinconsulter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listemedecinconsulter)
{
    ui->setupUi(this);
    this->setWindowTitle("Liste de Médecins");
}

listemedecinconsulter::~listemedecinconsulter()
{
    delete ui;
}

void listemedecinconsulter::on_recherche_clicked()
{
    QString recherche = ui->searchM->text().trimmed().toUpper();
    QString valeurRecherche = "%" + recherche + "%";
    QString dateDebut = ui->dateDeb->date().toString("yyyy-MM-dd");
    QString dateFin = ui->dateFin->date().toString("yyyy-MM-dd");
    QSqlQuery query;
    QString req = "SELECT "
                  "medecin.taux_journalier, medecin.n_medecin AS MedecinID, medecin.nom AS MedecinNom, " // <-- DÉBUT IMMÉDIAT
                  "patient.n_patient AS PatientID, patient.adresse, patient.nom AS PatientNom, "
                  "traitement.n_traitement, traitement.n_medecin, traitement.n_patient, "
                  "traitement.nbjour, traitement.date_consultation "
                  "FROM traitement "
                  "INNER JOIN medecin ON medecin.n_medecin = traitement.n_medecin "
                  "INNER JOIN patient ON patient.n_patient = traitement.n_patient "
                  "WHERE ("
                  "    UPPER(patient.n_patient) LIKE :recherche OR "
                  "    UPPER(patient.nom) LIKE :recherche"
                  ") AND "
                  "    traitement.date_consultation BETWEEN :dateDebut AND :dateFin";

    query.prepare(req);
    query.bindValue(":recherche", valeurRecherche);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFin", dateFin);
    if(query.exec()){
        ui-> listM->setRowCount(0);
        int row = 0;

        while (query.next()) {
            ui-> listM->insertRow(row);
            ui-> listM->setItem(row, 0, new QTableWidgetItem(query.value("MedecinID").toString()));
            ui-> listM->setItem(row, 1, new QTableWidgetItem(query.value("MedecinNom").toString()));
            ui-> listM->setItem(row, 2, new QTableWidgetItem(query.value("taux_journalier").toString()));
            ui->  listM->setItem(row, 3, new QTableWidgetItem(query.value("date_consultation").toString()));


            row++;
        }

        //afficher un message si rien n'est found


    }
    else{
        qDebug() << query.lastError().text();
    }

}

