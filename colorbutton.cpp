#include "colorbutton.h"

ColorButton::ColorButton(const QString& color,
                         const QString& text,
                         QWidget* parent):
    QPushButton(text, parent)
{
    this->color = color;
    QPalette pal = palette();
    if(color == "blue"){
        pal.setColor(QPalette::Button, QColor(Qt::blue));
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
