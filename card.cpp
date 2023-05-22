#include "card.h"
#include "game.h"

Card::Card(Game *game) {
    this->game = game;
    connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

void Card::buttonClicked(){
    game->score--;
    game->updateLabels();
}
