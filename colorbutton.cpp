#include "colorbutton.h"
#include "mygrid.h"
#include <QtDebug>

ColorButton::ColorButton(MyGrid *grid, int identifier, QWidget* parent): QPushButton(parent){
    // get the data fields from the constructor
    this->identifier = identifier;
    this->grid = grid;
    open = false;
}

// enter this function when button is pressed
void ColorButton::pressed() {
    qDebug() << "Button Pressed";
    if(!open) {
        if(grid->state == zeroShown) {
            showColor();
            open = true;
            grid->firstShownIdentifier = identifier;
            grid->state = oneShown;
        }
        else if (grid->state == oneShown) {
            open = true;
            showColor();
            grid->secondShownIdentifier = identifier;
            grid->state = twoShown;
            grid->tries--;
            grid->processTwoShown();

        }
        else if (grid->state == twoShown) {

        }
    }
}

// show the default color, which is black when button is not pressed
void ColorButton::showDefaultColor(){
    QColor theColor = QColor(0, 0, 0);
    QPalette pal = palette();
    pal.setColor(QPalette::Button, theColor);
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}

// show the distinguished color of the button depending on its id
void ColorButton::showColor() {
    QColor theColor;
    if (id==0) {
        theColor = QColor(128, 0, 0);
    } else if (id == 1) {
        theColor = QColor(170, 110, 40);
    } else if (id == 2) {
        theColor = QColor(128, 128, 0);
    } else if (id == 3) {
        theColor = QColor(0, 128, 128);
    } else if (id == 4) {
        theColor = QColor(0, 0, 128);
    } else if (id == 5) {
        theColor = QColor(230, 25, 75);
    } else if (id == 6) {
        theColor = QColor(245, 130, 48);
    } else if (id == 7) {
        theColor = QColor(255, 225, 25);
    } else if (id == 8) {
        theColor = QColor(210, 245, 60);
    } else if (id == 9) {
        theColor = QColor(60, 180, 75);
    } else if (id == 10) {
        theColor = QColor(70, 240, 240);
    } else if (id == 11) {
        theColor = QColor(0, 130, 200);
    } else if (id == 12) {
        theColor = QColor(145, 30, 180);
    } else if (id == 13) {
        theColor = QColor(240, 50, 230);
    } else if (id == 14) {
        theColor = QColor(220, 190, 255);
    }

    QPalette pal = palette();
    pal.setColor(QPalette::Button, theColor);
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}
