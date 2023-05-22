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
                const QString& text, MyGrid *grid, int identifier,
                QWidget* parent = 0);
    QString color;
    int id;
    int identifier;
    void showColor();
    void showDefaultColor();
    bool open;
public slots:
    void change_color();
    void pressed();
};


#endif // COLORBUTTON_H
