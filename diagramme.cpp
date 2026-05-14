#ifndef DIAGRAMME_H
#define DIAGRAMME_H

#include <QWidget>
#include "ui_diagramme.h"
\
namespace Ui {
class diagramme;
}

class diagramme : public QWidget
{
    Q_OBJECT

public:
    explicit diagramme(QWidget *parent = nullptr);
    ~diagramme();
private:
    Ui::diagramme *ui;
};

#endif // DIAGRAMME_H
