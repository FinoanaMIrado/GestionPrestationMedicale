#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QWidget>

namespace Ui {
class diagram;
}

class diagram : public QWidget
{
    Q_OBJECT

public:
    explicit diagram(QWidget *parent = nullptr);
    void setData(const QVector<QPointF> &points);
    ~diagram();
protected:
     void paintEvent(QPaintEvent *event) override;

private:
    Ui::diagram *ui;
    QVector<QPointF> m_points;
};

#endif // DIAGRAM_H
