#include "login.h"
#include "ui_login.h"
#include"mainwindow.h"
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include"ajoutuser.h"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Fenêtre de Login");
}

login::~login()
{
    delete ui;
}

void login::on_btnconnexion_clicked()
{   QString user=ui->utilisateur->text();
    QString mdp=ui->motdepasse->text();

    if(user.isEmpty()||mdp.isEmpty()){
        QMessageBox::critical(nullptr,"ERREUR","Saisissez le nom d'utilisateur et mots de passe ");

    }
    else{
    QSqlQuery query;
    query.prepare("SELECT nom_utilisateur,mot_de_passe FROM utilisateurs where nom_utilisateur=:user and mot_de_passe=:mdp");
    query.bindValue(":user",user);
    query.bindValue(":mdp",mdp);
    query.exec();

   if(query.next()){



       MainWindow *wh= new MainWindow(nullptr);
     wh -> setAttribute(Qt::WA_DeleteOnClose);
     wh->show();
     this->close();
   }
   else{
       QMessageBox::critical(nullptr,"INCORECTE","Nom d'utilisateur ou mots de passe incorrecte");
    }
}
}

void login::on_linkadduser_clicked()
{
    ajoutuser *wh= new ajoutuser(nullptr);
    wh->setAttribute(Qt::WA_DeleteOnClose);
    wh->show();
}

