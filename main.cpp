
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QDir>
#include <string>
#include <iostream>

using namespace std;

class Card:QPushButton{
public:
    Card(){
        connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    }
public slots:
    void buttonClicked(){
    }
};

int main(int argc, char *argv[])
{
    string projectPath = "C:/Users/arinc/Documents/memory_game";
    QApplication a(argc, argv);

    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton;
    string iconPath = projectPath + "/icon.png";
    QPixmap pixmap(iconPath.c_str());
    QIcon ButtonIcon(pixmap);
    button1->setIcon(ButtonIcon);
    button1->setIconSize(pixmap.rect().size());
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    QGridLayout *layout = new QGridLayout(window);
    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 0, 1);
    layout->addWidget(button3, 1, 0, 1, 2);
    layout->addWidget(button4, 2, 0);
    layout->addWidget(button5, 2, 1);


    window->show();


    return a.exec();
}
