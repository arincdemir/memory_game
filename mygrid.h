#ifndef MYGRID_H
#define MYGRID_H
#include <QGridLayout>
#include <QMessageBox>
#include <QTimer>
#include <QTimerEvent>

enum State {zeroShown, oneShown, twoShown};

class MyGrid: public QGridLayout
{
    Q_OBJECT
public:
    State state;
    int score;
    int tries;
    MyGrid(QTimer* timer);
    QTimer* timer;
    void reset();
    int firstShownIdentifier;
    int secondShownIdentifier;
    void processTwoShown();
    int timerId;
    void timerEvent(QTimerEvent *event);
public slots:
    void check_colors();
};


#endif // MYGRID_H
