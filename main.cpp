#include "mainwindow.h"
#include"login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.1");
    db.setUserName("root");
    db.setPort(3306);
    db.setPassword("");
    db.setDatabaseName("gestion_medicale");

    if(db.open()){
        QMessageBox::information(nullptr,"Connexion réussi","base de donnée connecté");

    }
    else{
        QMessageBox::critical(nullptr,"Non connecté", db.lastError().text());
    }


    login w;
    w.show();
    return a.exec();
}
