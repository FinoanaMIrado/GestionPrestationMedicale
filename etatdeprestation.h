#ifndef ETATDEPRESTATION_H
#define ETATDEPRESTATION_H

#include <QWidget>
#include <QSqlQueryModel>

namespace Ui {
class etatdeprestation;
}

class etatdeprestation : public QWidget
{
    Q_OBJECT

public:
    explicit etatdeprestation(QWidget *parent = nullptr, const int &date_pre=0);
    ~etatdeprestation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::etatdeprestation *ui;
    QSqlQueryModel *model;
    void lister();
    int date_pre;
};

#endif // ETATDEPRESTATION_H
