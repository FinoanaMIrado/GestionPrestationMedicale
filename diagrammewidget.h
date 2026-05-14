#ifndef DIAGRAMMEWIDGET_H
#define DIAGRAMMEWIDGET_H

#include <QWidget>
#include <QMap>

namespace Ui {
class DiagrammeWidget;
}

class DiagrammeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DiagrammeWidget(QWidget *parent = nullptr);
    ~DiagrammeWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::DiagrammeWidget *ui;
    QMap<QString, int> prestations;


    void chargerDonneesDepuisBD();
//         int date_pre;
};

#endif // DIAGRAMMEWIDGET_H
