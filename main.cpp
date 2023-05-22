
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QString>
#include <string>
#include <iostream>
#include "card.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
    string projectPath = "C:/Users/arinc/Documents/memory_game";
    QApplication a(argc, argv);
    QWidget *window = new QWidget;



    QLabel *scoreLabel = new QLabel("Hey");
    QLabel *triesLabel = new QLabel("Ho");
    QGridLayout *layout = new QGridLayout(window);

    Game *game = new Game(scoreLabel, triesLabel);

    Card *card1 = new Card(game);
    string iconPath = projectPath + "/icon.png";
    QPixmap pixmap(iconPath.c_str());
    QIcon ButtonIcon(pixmap);
    card1->setIcon(ButtonIcon);
    card1->setIconSize(pixmap.rect().size());

    layout->addWidget(scoreLabel, 0, 0);
    layout->addWidget(triesLabel, 0, 1);
    layout->addWidget(card1, 1, 0);

    window->show();


    return a.exec();
}
