#include "colorbutton.h"
#include "mygrid.h"
#include <QtDebug>

ColorButton::ColorButton(const QString& color,
                         const QString& text, MyGrid *grid,
                         QWidget* parent):
    QPushButton(text, parent)
{
    this->grid = grid;
    this->color = color;
    QPalette pal = palette();
    if(color == "blue"){
        pal.setColor(QPalette::Button, QColor(222,222,222));
    }else if(color == "red"){
        pal.setColor(QPalette::Button, QColor(Qt::red));
    }else{
        pal.setColor(QPalette::Button, QColor(Qt::green));
    }
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}

void ColorButton::change_color(){
    QPalette pal = palette();
    int color = rand() % 3;
    if(color == 0){
        this->color = "blue";
        pal.setColor(QPalette::Button, QColor(Qt::blue));
    }else if(color == 1){
        this->color = "red";
        pal.setColor(QPalette::Button, QColor(Qt::red));
    }else{
        this->color = "green";
        pal.setColor(QPalette::Button, QColor(Qt::green));
    }
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}

void ColorButton::pressed() {
    qDebug() << "Hey";
    if(grid->state == zeroShown) {
        showColor();
        grid->state = oneShown;
    }
    else if (grid->state == oneShown) {
        showColor();
        grid->state = twoShown;
    }
    else if (grid->state == twoShown) {

    }
}

void ColorButton::showDefaultColor(){
    QColor theColor = QColor(0, 0, 0);
    QPalette pal = palette();
    pal.setColor(QPalette::Button, theColor);
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}

void ColorButton::showColor() {
    QColor theColor = QColor(30 + id * 15, 30 + id * 15, 30 + id * 15);
    QPalette pal = palette();
    pal.setColor(QPalette::Button, theColor);
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}
