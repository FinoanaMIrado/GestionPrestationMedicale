#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QtSql/QSqlError>
#include <QtSql/QSql>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_btnrecherchemed_clicked();

    void on_btnrecherchepat_clicked();

    void on_btnrecherchetrait_clicked();

    void on_supprMed_clicked();

    void on_supprPat_clicked();

    void on_supprTrait_clicked();

    void on_modifTraitButton_clicked();

    void on_modifMedButon_clicked();

    void on_modifPatButton_clicked();

    void on_butonPatTrait_clicked();

    void on_butonMedCons_clicked();

private:
    int date_pre;
    QString num_med, num_pat, num_trait;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
