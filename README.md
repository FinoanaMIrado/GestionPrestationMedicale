# 🏥 Gestion des prestations des médecins

## 📌 Description du projet

**Gestion des prestations des médecins** est une application de gestion permettant de suivre les médecins, les patients, les traitements et les consultations médicales.

L'application permet de centraliser les informations médicales, de gérer les opérations CRUD (ajout, modification, suppression, recherche) et de calculer automatiquement les prestations des médecins selon les consultations effectuées.

Le projet a été développé avec une interface graphique réalisée sous **Qt Creator**, une logique métier en **C++** et une gestion des données avec le SGBD **MySQL**.

---

## 🎯 Objectifs du projet

Les objectifs principaux sont :

- Gérer les informations des médecins
- Gérer les informations des patients
- Enregistrer les traitements et consultations
- Calculer les prestations médicales
- Effectuer des recherches avancées
- Générer des états et statistiques

---

## ✨ Fonctionnalités

## 👨‍⚕️ Gestion des médecins

- Ajouter un médecin
- Modifier les informations d'un médecin
- Supprimer un médecin
- Rechercher un médecin
- Afficher la liste des médecins

Informations gérées :

- Numéro médecin
- Nom
- Taux journalier

---

## 👤 Gestion des patients

- Ajouter un patient
- Modifier un patient
- Supprimer un patient
- Rechercher un patient par nom ou adresse
- Afficher la liste des patients

Informations gérées :

- Numéro patient
- Nom
- Adresse

---

## 💊 Gestion des traitements

L'application permet :

- D'enregistrer un traitement
- D'associer un patient à un médecin
- De gérer les dates de consultation
- De calculer le nombre de jours de traitement
- De calculer le montant de la prestation

Calcul utilisé :
Prestation = Taux journalier × Nombre de jours

## 📊 Rapports et statistiques

L'application permet de générer :

- La liste des patients traités par un médecin entre deux dates
- La liste des médecins consultés par un patient
- L'état annuel des prestations par médecin
- Le montant total des prestations
- Des graphiques statistiques (histogramme / camembert)
- Des rapports PDF

---

# 🗄️ Base de données

Le projet utilise **MySQL** pour stocker les données.

Tables principales :

### Table Médecin

| Champ | Description |
|-|-|
| id_medecin | Identifiant du médecin |
| nom | Nom du médecin |
| taux | Tarif journalier |

### Table Patient

| Champ | Description |
|-|-|
| id_patient | Identifiant patient |
| nom | Nom du patient |
| adresse | Adresse |

### Table Traitement

| Champ | Description |
|-|-|
| id_traitement | Identifiant traitement |
| id_medecin | Médecin associé |
| id_patient | Patient associé |
| date_consultation | Date de consultation |
| nombre_jours | Durée du traitement |

---

# 🛠️ Technologies utilisées

- **Langage de programmation : C++**
- **Interface graphique : Qt Creator / Qt Framework**
- **Base de données : MySQL**
- **IDE : Qt Creator**
- **Gestion des données : SQL**

