
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

using namespace std;

class Game : public QObject{
public:
    int score;
    int triesLeft;
    QLabel *scoreLabel;
    QLabel *triesLabel;

    Game(QLabel *scoreLabel, QLabel *triesLabel) {
        this->scoreLabel = scoreLabel;
        this->triesLabel = triesLabel;
        reset();
    }

    void reset() {
        score = 0;
        triesLeft = 50;
        updateLabels();
    }

    void updateLabels() {
        scoreLabel->setText("Score: " + QString::number(score));
        triesLabel->setText("Tries Left: " + QString::number(triesLeft));
    }
};

class Card : public QPushButton{

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

    Card *card1 = new Card();
    string iconPath = projectPath + "/icon.png";
    QPixmap pixmap(iconPath.c_str());
    QIcon ButtonIcon(pixmap);
    card1->setIcon(ButtonIcon);
    card1->setIconSize(pixmap.rect().size());

    QLabel *scoreLabel = new QLabel("Hey");
    QLabel *triesLabel = new QLabel("Ho");

    QGridLayout *layout = new QGridLayout(window);
    layout->addWidget(scoreLabel, 0, 0);
    layout->addWidget(triesLabel, 0, 1);
    layout->addWidget(card1, 1, 0);

    Game *game = new Game(scoreLabel, triesLabel);

    window->show();


    return a.exec();
}
