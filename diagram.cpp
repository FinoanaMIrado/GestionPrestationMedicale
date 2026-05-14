#include "diagram.h"
#include "ui_diagram.h"
#include <QPaintEvent>
#include <QPainter> // Assurez-vous d'inclure QPainter·

diagram::diagram(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diagram)
{
    ui->setupUi(this);
}

diagram::~diagram()
{
    delete ui;
}
