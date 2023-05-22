#ifndef MYGRID_H
#define MYGRID_H
#include <QGridLayout>
#include <QMessageBox>
#include <QTimer>

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
public slots:
    void check_colors();
};


#endif // MYGRID_H
