#ifndef AJOUTUSER_H
#define AJOUTUSER_H

#include <QWidget>

namespace Ui {
class ajoutuser;
}

class ajoutuser : public QWidget
{
    Q_OBJECT

public:
    explicit ajoutuser(QWidget *parent = nullptr);
    ~ajoutuser();

private slots:
    void on_btnajouter_clicked();

private:
    Ui::ajoutuser *ui;
};

#endif // AJOUTUSER_H
