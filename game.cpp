#include "game.h"
#include "card.h"

Game::Game(QLabel *scoreLabel, QLabel *triesLabel)
{
    this->scoreLabel = scoreLabel;
    this->triesLabel = triesLabel;
    reset();
}

void Game::reset() {
    score = 0;
    triesLeft = 50;
    updateLabels();
}

void Game::updateLabels() {
    scoreLabel->setText("Score: " + QString::number(score));
    triesLabel->setText("Tries Left: " + QString::number(triesLeft));
}
