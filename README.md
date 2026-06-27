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
