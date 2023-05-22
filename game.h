#include <QObject>
#include <QWidget>
#include <QLabel>
#include "card.h"

#ifndef GAME_H
#define GAME_H


class Game : public QObject{
public:
    int score;
    int triesLeft;
    QLabel *scoreLabel;
    QLabel *triesLabel;

    Game(QLabel *scoreLabel, QLabel *triesLabel);

    void reset();

    void updateLabels();
};

#endif // GAME_H
