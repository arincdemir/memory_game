
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
#include <vector>
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

    vector<Card*> *cards = new vector<Card *>();
    Game *game = new Game(scoreLabel, triesLabel);
    for(int i = 0; i < 30; i++) {
        cards->push_back(new Card(game));
    }

    QGridLayout *layout = new QGridLayout(window);

    layout->addWidget(scoreLabel, 0, 0);
    layout->addWidget(triesLabel, 0, 1);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            layout->addWidget(cards->at(i * 5 + j), i + 1, j);
        }
    }

    window->show();


    return a.exec();
}
