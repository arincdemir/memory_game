#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include <QPushButton>
#include <QPalette>

class ColorButton : public QPushButton
{
    Q_OBJECT
public:
    ColorButton(const QString& color,
                const QString& text,
                QWidget* parent = 0);
    QString color;
public slots:
    void change_color();
};


#endif // COLORBUTTON_H
