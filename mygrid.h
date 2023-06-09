#ifndef MYGRID_H
#define MYGRID_H
#include <QGridLayout>
#include <QMessageBox>
#include <QTimerEvent>
#include <QLabel>

enum State {zeroShown, oneShown, twoShown};

class MyGrid: public QGridLayout
{
    Q_OBJECT
public:
    State state;
    int score;
    int tries;
    MyGrid(QLabel *scoreLabel, QLabel *triesLabel);
    int firstShownIdentifier;
    int secondShownIdentifier;
    void processTwoShown();
    int timerId;
    void timerEvent(QTimerEvent *event);
    QLabel *scoreLabel;
    QLabel *triesLabel;
    void winGame();
    void loseGame();
public slots:
    void reset();
};


#endif // MYGRID_H
