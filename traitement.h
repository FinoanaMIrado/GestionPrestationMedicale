#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <QWidget>

namespace Ui {
class traitement;
}

class traitement : public QWidget
{
    Q_OBJECT

public:
    explicit traitement(QWidget *parent = nullptr);
    ~traitement();

private slots:
    void on_AjoutTraitement_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::traitement *ui;
};

#endif // TRAITEMENT_H
