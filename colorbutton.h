#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include <QPushButton>
#include <QPalette>
#include "mygrid.h"

class ColorButton : public QPushButton
{
    Q_OBJECT
public:
    MyGrid *grid;
    ColorButton(const QString& color,
                const QString& text, MyGrid *grid,
                QWidget* parent = 0);
    QString color;
    int id;
    void showColor();
    void showDefaultColor();
public slots:
    void change_color();
    void pressed();
};


#endif // COLORBUTTON_H
