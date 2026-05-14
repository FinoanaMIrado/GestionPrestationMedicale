#include "listepatient.h"
#include "ui_listepatient.h"
#include <QtSql>
#include <QSqlDatabase>

listepatient::listepatient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listepatient)
{
    ui->setupUi(this);
    this->setWindowTitle("Liste des patients");
}

listepatient::~listepatient()
{
    delete ui;
}

void listepatient::on_rechercherPatTr_clicked()
{
    QString recherche = ui->searchMed->text().trimmed().toUpper();
    QString valeurRecherche = "%" + recherche.toUpper() + "%";
    QString dateDebut = ui->debut->date().toString("yyyy-MM-dd");
    QString dateFin = ui->fin_date->date().toString("yyyy-MM-dd");
    QSqlQuery query;
    QString req = "SELECT "
                  // Colonnes de MEDECIN
                  "    medecin.taux_journalier, medecin.n_medecin AS MedecinID, "
                  // Colonnes de PATIENT
                  "    patient.n_patient AS PatientID, patient.adresse, patient.nom AS PatientNom, "
                  // Colonnes de TRAITEMENT
                  "    traitement.n_traitement, traitement.n_medecin, traitement.n_patient, "
                  "    traitement.nbjour, traitement.date_consultation "
                  "FROM traitement "
                  "INNER JOIN medecin ON medecin.n_medecin = traitement.n_medecin "
                  "INNER JOIN patient ON patient.n_patient = traitement.n_patient "
                  // --- Critères de FILTRE ---
                  "WHERE ("
                  "    UPPER(medecin.n_medecin) LIKE :recherche OR " // insensible à la casse
                  "    UPPER(medecin.nom) LIKE :recherche"          // dans n_medecin OU nom de medecin
                  ") AND "
                  "    traitement.date_consultation BETWEEN :dateDebut AND :dateFin";

    query.prepare(req);
    query.bindValue(":recherche", valeurRecherche);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFin", dateFin);
    if(query.exec()){
        ui-> listP->setRowCount(0);
        int row = 0;

        while (query.next()) {
            ui-> listP->insertRow(row);
            ui-> listP->setItem(row, 0, new QTableWidgetItem(query.value("n_patient").toString()));
            ui-> listP->setItem(row, 1, new QTableWidgetItem(query.value("PatientNom").toString()));
            ui-> listP->setItem(row, 2, new QTableWidgetItem(query.value("adresse").toString()));
            ui->  listP->setItem(row, 3, new QTableWidgetItem(query.value("nbjour").toString()));

            //calcul de montant
            int montant = (query.value("nbjour").toInt()*query.value("taux_journalier").toInt());
            ui->  listP->setItem(row, 4, new QTableWidgetItem(QString::number(montant)));


            row++;
        }

        //afficher un message si rien n'est found
        if(row == 0){
            ui-> listP->insertRow(row);
            QTableWidgetItem* messageItem = new QTableWidgetItem("Pas de résultat trouvé.");

            // Optionnel : Centrer le texte
            messageItem->setTextAlignment(Qt::AlignCenter);

            ui->listP->setItem(0, 0, messageItem);

            // Fusionner les cellules de la première ligne
            int nombreColonnes = ui->listP->columnCount();
            ui->listP->setSpan(0, 0, 1, nombreColonnes);
        }

    }
    else{
        qDebug() << query.lastError().text();
    }

}

