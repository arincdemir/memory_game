#include "mygrid.h"
#include "colorbutton.h"
#include <vector>
#include <QtDebug>
#include <QMessageBox>

using namespace std;

MyGrid::MyGrid(QLabel *scoreLabel, QLabel *triesLabel): QGridLayout(){
    this->scoreLabel = scoreLabel;
    this->triesLabel = triesLabel;
    this->state = zeroShown;
}


void MyGrid::reset(){
    vector<int> vect{ 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14};
    for(int i = 0; i < this->count(); ++i){
        int index = rand() % vect.size();
        ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());
        widget->id = vect.at(index);
        widget->open = false;
        widget->showDefaultColor();
        vect.erase(vect.begin() + index);
    }

    score = 0;
    scoreLabel->setText("Score: " + QString::number(score));
    tries = 50;
    triesLabel->setText("Tries Left: " + QString::number(tries));
}

void MyGrid::processTwoShown(){
    qDebug() << "Processing Two Shown";

    ColorButton *first;
    ColorButton *second;
    for(int i = 0; i < this->count(); ++i){
        ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());
        if(widget->identifier == firstShownIdentifier) {
            first = widget;
            qDebug() << "Found First";
        }
        else if(widget->identifier == secondShownIdentifier) {
            second = widget;
            qDebug() << "Found Second";
        }
    }
    qDebug() << first->id;
    qDebug() << second->id;
    if(first->id == second->id) {
        score += 1;
        scoreLabel->setText("Score: " + QString::number(score));
        state = zeroShown;
    }
    else {
        this->timerId = startTimer(1000);
    }

    triesLabel->setText("Tries Left: " + QString::number(tries));

    if(score == 15) {
        winGame();
    }
    else if (tries == 49) {
        loseGame();
    }

}

void MyGrid::loseGame(){
    qDebug() << "Lose";
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setWindowTitle("You lose!");
    msgBox->setText("Nice try though. Your score was: " + QString::number(score));
    msgBox->setStandardButtons(QMessageBox::Close);
    msgBox->show();
    reset();
}

void MyGrid::winGame(){
    qDebug() << "Win";
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setWindowTitle("You win!");
    msgBox->setText("Yuppiii! You still had " + QString::number(tries) + " tries left. My god!");
    msgBox->setStandardButtons(QMessageBox::Close);
    msgBox->show();
    reset();
}

void MyGrid::timerEvent(QTimerEvent *event){
    qDebug() << "timer event";
    killTimer(timerId);
    ColorButton *first;
    ColorButton *second;
    for(int i = 0; i < this->count(); ++i){
        ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());
        if(widget->identifier == firstShownIdentifier) {
            first = widget;
            qDebug() << "Found First";
        }
        else if(widget->identifier == secondShownIdentifier) {
            second = widget;
            qDebug() << "Found Second";
        }
    }

    first->showDefaultColor();
    second->showDefaultColor();
    first->open = false;
    second->open = false;
    state = zeroShown;

}
