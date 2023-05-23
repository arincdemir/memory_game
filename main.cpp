#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QtDebug>
#include <QLabel>
#include "colorbutton.h"
#include "mygrid.h"

int main(int argc, char *argv[]){

    qDebug() << "Beginning";
    QApplication app(argc, argv);

    QWidget *mainWidget = new QWidget; // main widget
    QVBoxLayout *vertical= new QVBoxLayout(mainWidget); // grid and stats
    QLabel *scoreLabel = new QLabel("test");
    scoreLabel->setStyleSheet("font: 18pt;");
    QLabel *triesLabel = new QLabel("test");
    triesLabel->setStyleSheet("font: 18pt;");
    MyGrid *grid = new MyGrid(scoreLabel, triesLabel); // the grid that holds the buttons
    QPushButton *resetButton = new QPushButton("Reset");
    resetButton->setStyleSheet("font: 18pt;");
    QObject::connect(resetButton, SIGNAL(clicked()), grid, SLOT(reset()));
    QHBoxLayout *statsLayout = new QHBoxLayout(); // the horizontal layout that holds score, tries and the reset button.

    // initialize the buttons, and connect them
    for(int row=0; row<5; row++){
        for(int col=0; col<6; col++){
            ColorButton *randButton = new ColorButton(grid, rand());
            randButton->setFixedHeight(100);
            randButton->setFixedWidth(100);
            QObject::connect(randButton, SIGNAL(clicked()), randButton, SLOT(pressed()));
            grid->addWidget(randButton, row, col, 1, 1);

        }
    }

    // form the layouts
    statsLayout->addWidget(scoreLabel);
    statsLayout->addWidget(triesLabel);
    statsLayout->addWidget(resetButton);
    vertical->addLayout(statsLayout);
    vertical->addLayout(grid);
    QSpacerItem *spacer = new QSpacerItem(0, 30, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vertical->addSpacerItem(spacer);

    //reset the game in the beginning once
    grid->reset();

    mainWidget->setWindowTitle("Color Matching Game");
    mainWidget->resize(640, 480);
    mainWidget->show();
    return app.exec();
}
