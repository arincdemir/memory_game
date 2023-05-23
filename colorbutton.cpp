#include "colorbutton.h"
#include "mygrid.h"
#include <QtDebug>

ColorButton::ColorButton(const QString& color,
                         const QString& text, MyGrid *grid, int identifier,
                         QWidget* parent):
    QPushButton(text, parent)
{
    this->identifier = identifier;
    this->grid = grid;
    open = false;
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
    qDebug() << "Button Pressed";
    if(!open) {
        if(grid->state == zeroShown) {
            showColor();
            open = true;
            grid->firstShownIdentifier = identifier;
            grid->state = oneShown;
            grid->tries--;
        }
        else if (grid->state == oneShown) {
            open = true;
            showColor();
            grid->secondShownIdentifier = identifier;
            grid->state = twoShown;
            grid->processTwoShown();
            grid->tries--;
        }
        else if (grid->state == twoShown) {

        }
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
    QColor theColor;
    if (id==0) {
        theColor = QColor(255, 0, 0);
    } else if (id == 1) {
        theColor = QColor(0, 255, 64);
    } else if (id == 1) {
        theColor = QColor(255, 0, 0);
    } else if (id == 1) {
        theColor = QColor(255, 0, 0);
    } else if (id == 1) {
        theColor = QColor(255, 0, 0);
    } else if (id == 1) {
        theColor = QColor(255, 0, 0);
    } else if (id == 1) {
        theColor = QColor(255, 0, 0);
    } else if (id == 1) {
        theColor = QColor(255, 0, 0);
    } else if (id == 1) {
        theColor = QColor(255, 0, 0);
    } else if (id == 1) {
        theColor = QColor(255, 0, 0);
    } else if (id == 1) {
        theColor = QColor(255, 0, 0);
    }
    QColor theColor = QColor(30 + id * 15, 30 + id * 15, 30 + id * 15);
    QPalette pal = palette();
    pal.setColor(QPalette::Button, theColor);
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}
