#include "colorbutton.h"
#include "mygrid.h"

ColorButton::ColorButton(const QString& color,
                         const QString& text, MyGrid *grid,
                         QWidget* parent):
    QPushButton(text, parent)
{
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
