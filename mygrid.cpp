#include "mygrid.h"
#include "colorbutton.h"
#include <vector>
#include <QtDebug>
#include <QMessageBox>

using namespace std;

MyGrid::MyGrid(QLabel *scoreLabel, QLabel *triesLabel): QGridLayout(){
    //get the data fields from constructor
    this->scoreLabel = scoreLabel;
    this->triesLabel = triesLabel;
    this->state = zeroShown;
}


void MyGrid::reset(){
    // randomly assign id's that determines color to buttons, in pairs
    vector<int> vect{ 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14};
    for(int i = 0; i < this->count(); ++i){
        int index = rand() % vect.size();
        ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());
        widget->id = vect.at(index);
        widget->open = false;
        widget->showDefaultColor();
        vect.erase(vect.begin() + index);
    }

    // reset the score and tries
    score = 0;
    scoreLabel->setText("Score: " + QString::number(score));
    tries = 50;
    triesLabel->setText("Tries Left: " + QString::number(tries));
}

//function is called when two buttons are opened on the screen
void MyGrid::processTwoShown(){
    // get the two buttons that were opened
    ColorButton *first;
    ColorButton *second;
    for(int i = 0; i < this->count(); ++i){
        ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());
        if(widget->identifier == firstShownIdentifier) {
            first = widget;
        }
        else if(widget->identifier == secondShownIdentifier) {
            second = widget;
        }
    }

    // if the id which determines color are same, increase score, and return back to zero opened state
    if(first->id == second->id) {
        score += 1;
        scoreLabel->setText("Score: " + QString::number(score));
        state = zeroShown;
    }
    // if they are different, call the timer to go into the timerEvent function
    else {
        this->timerId = startTimer(1000);
    }

    // update trieslabel
    triesLabel->setText("Tries Left: " + QString::number(tries));

    // check if the conditions to end the game are met
    if(score == 15) {
        winGame();
    }
    else if (tries == 0) {
        loseGame();
    }

}

// if the number of tries is depleted enter here
// open up a message box that displays your end score, then reset the game
void MyGrid::loseGame(){
    qDebug() << "Lose";
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setWindowTitle("You lose!");
    msgBox->setText("Nice try though. Your score was: " + QString::number(score));
    msgBox->setStandardButtons(QMessageBox::Close);
    msgBox->show();
    reset();
}

// if the score reaches the perfect number, enter here
// open up a message box that displays your tries left, then reset the game
void MyGrid::winGame(){
    qDebug() << "Win";
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setWindowTitle("You win!");
    msgBox->setText("Yuppiii! You still had " + QString::number(tries) + " tries left. My god!");
    msgBox->setStandardButtons(QMessageBox::Close);
    msgBox->show();
    reset();
}

// this function procs when the timer finishes, which was set after two buttons are opened that are not the same id.
void MyGrid::timerEvent(QTimerEvent *event){
    qDebug() << "timer event";
    killTimer(timerId);
    // get the first and second buttons that were pressed
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

    // close the buttons and set the state back to zero
    first->showDefaultColor();
    second->showDefaultColor();
    first->open = false;
    second->open = false;
    state = zeroShown;

}
