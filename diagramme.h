#ifndef DIAGRAMME_H
#define DIAGRAMME_H

#include <QWidget>
#include <QWidget>
#include <QVector>
#include <QPointF>



namespace Ui {
class diagramme;
}

class diagramme : public QWidget
{
    Q_OBJECT
public:
    explicit diagramme(QWidget *parent = nullptr);
    void setData(const QVector<QPointF> &points);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<QPointF> m_points;
};

#endif // DIAGRAMME_H
