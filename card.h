#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <string>
#include "game.h"

class Card : public QPushButton{
Q_OBJECT
public:
    std::string projectPath = "C:/Users/arinc/Documents/memory_game";
    Game *game;
    Card(Game *game);
public slots:
    void buttonClicked();
};


#endif // CARD_H
