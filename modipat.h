#ifndef MODIPAT_H
#define MODIPAT_H

#include <QWidget>

namespace Ui {
class modiPat;
}

class modiPat : public QWidget
{
    Q_OBJECT

public:
    explicit modiPat(QWidget *parent = nullptr, const QString &num_pat = 0);
    ~modiPat();

private slots:
    void on_modPat_clicked();

    void on_annModPat_clicked();

private:
    Ui::modiPat *ui;
};

#endif // MODIPAT_H
