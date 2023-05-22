#include "card.h"
#include "game.h"
#include <string>

Card::Card(Game *game) {
    this->game = game;
    connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    std::string iconPath = projectPath + "/icon.png";
    QPixmap pixmap(iconPath.c_str());
    QIcon ButtonIcon(pixmap);
    this->setIcon(ButtonIcon);
    this->setIconSize(pixmap.rect().size());
}

void Card::buttonClicked(){
    game->score--;
    game->updateLabels();
}
