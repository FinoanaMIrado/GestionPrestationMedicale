#include "diagrammewidget.h"
#include "ui_diagrammewidget.h"

#include <QPainter>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFontMetrics>
#include <algorithm>
#include <QDebug>

DiagrammeWidget::DiagrammeWidget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::DiagrammeWidget)
{
    ui->setupUi(this);

//    this->setWindowTitle("État des prestations de l'année"+QString::number(date_pre));

//    ui->anneepre->setText(QString::number(date_pre));



    setStyleSheet("background-color: white; border: 1px solid lightgray;");
    setMinimumSize(700, 400);

    chargerDonneesDepuisBD();
}

DiagrammeWidget::~DiagrammeWidget()
{
    delete ui;
}

void DiagrammeWidget::chargerDonneesDepuisBD()
{
    prestations.clear();

    QSqlQuery query;
    query.prepare("SELECT medecin.n_medecin, medecin.nom, medecin.taux_journalier, traitement.nbjour "
                  "FROM medecin "
                  "INNER JOIN traitement ON traitement.n_medecin = medecin.n_medecin ");


    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    QMap<QString, int> prestationsParMedecin;
    while (query.next()) {
        QString idMedecin = query.value("n_medecin").toString();
        int nbJours = query.value("nbjour").toInt();
        int tauxJour = query.value("taux_journalier").toInt();
        int prestation = nbJours * tauxJour;
        prestationsParMedecin[idMedecin] += prestation;
    }


    for (auto it = prestationsParMedecin.constBegin(); it != prestationsParMedecin.constEnd(); ++it) {
        QString id = it.key();
        int totalPrestation = it.value();
        QString nomMedecin = "";

        query.prepare("SELECT nom FROM medecin WHERE n_medecin = :id");
        query.bindValue(":id", id);
        if (query.exec() && query.next()) {
            nomMedecin = query.value("nom").toString();
            prestations[nomMedecin] = totalPrestation;
        } else {
            qDebug() << "Erreur récupération nom médecin:" << query.lastError();
        }
    }

    if (prestations.isEmpty()) {
        QMessageBox::information(this, "Aucune donnée", "Aucun médecin trouvé dans la base.");
    }

    update();
}

void DiagrammeWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (prestations.isEmpty()) {
        painter.drawText(rect(), Qt::AlignCenter, "Aucune donnée à afficher");
        return;
    }

    // Marges et zone de dessin
    const int marginLeft = 80;
    const int marginBottom = 70;
    const int marginTop = 30;
    const int marginRight = 20;

    int graphWidth = width() - marginLeft - marginRight;
    int graphHeight = height() - marginTop - marginBottom;

    // Trouver la valeur max pour l’échelle
    int maxVal = *std::max_element(prestations.begin(), prestations.end());
    if (maxVal <= 0) return;

    // Tracer les axes
    painter.setPen(Qt::black);
    painter.drawLine(marginLeft, height() - marginBottom, width() - marginRight, height() - marginBottom); // Axe X
    painter.drawLine(marginLeft, marginTop, marginLeft, height() - marginBottom); // Axe Y

    // Dessiner les barres
    int n = prestations.size();
    int barWidth = graphWidth / n;
    int i = 0;
    QFontMetrics fm(painter.font());

    for (auto it = prestations.constBegin(); it != prestations.constEnd(); ++it, ++i) {
        QString nom = it.key();
        int val = it.value();

        int barHeight = static_cast<int>((val / static_cast<double>(maxVal)) * graphHeight);
        int x = marginLeft + i * barWidth + 10;
        int y = height() - marginBottom - barHeight;

        QColor barColor = QColor::fromHsv((i * 40) % 360, 200, 230);
        painter.setBrush(barColor);
        painter.setPen(Qt::NoPen);
        painter.drawRect(x, y, barWidth - 20, barHeight);

        // Nom du médecin (axe X)
        painter.setPen(Qt::black);
        QString nomTronque = fm.elidedText(nom, Qt::ElideRight, barWidth - 20);
        painter.drawText(x + (barWidth - 20 - fm.horizontalAdvance(nomTronque)) / 2,
                         height() - marginBottom + 20, nomTronque);

        // Valeur de la prestation au-dessus de la barre
        QString valStr = QString::number(val);
        painter.drawText(x + (barWidth - 20 - fm.horizontalAdvance(valStr)) / 2,
                         y - 5, valStr);
    }

    // Tracer les graduations Y
    painter.setPen(Qt::gray);
    int step = maxVal / 5;
    if (step < 1) step = 1;

    for (int v = 0; v <= maxVal; v += step) {
        int y = height() - marginBottom - static_cast<int>((v / static_cast<double>(maxVal)) * graphHeight);
        painter.drawLine(marginLeft - 5, y, marginLeft, y);
        painter.drawText(10, y + 5, QString::number(v));
    }

    // Titre du graphique
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.drawText(width() / 2 - 120, marginTop - 5, "Prestations totales par Médecin");
}
