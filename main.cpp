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
    QVBoxLayout *vertical= new QVBoxLayout(mainWidget); // timer, grid and spaceritem
    QLabel *scoreLabel = new QLabel("test");
    scoreLabel->setStyleSheet("font: 18pt;");
    QLabel *triesLabel = new QLabel("test");
    triesLabel->setStyleSheet("font: 18pt;");

    MyGrid *grid = new MyGrid(scoreLabel, triesLabel);
    QPushButton *resetButton = new QPushButton("Reset");
    resetButton->setStyleSheet("font: 18pt;");
    QObject::connect(resetButton, SIGNAL(clicked()), grid, SLOT(reset()));
    QHBoxLayout *statsLayout = new QHBoxLayout();

    for(int row=0; row<5; row++){
        for(int col=0; col<6; col++){
            ColorButton *randButton = new ColorButton(grid, rand());
            randButton->setFixedHeight(100);
            randButton->setFixedWidth(100);
            QObject::connect(randButton, SIGNAL(clicked()), randButton, SLOT(pressed()));

            grid->addWidget(randButton, row, col, 1, 1);

        }
    }
    statsLayout->addWidget(scoreLabel);
    statsLayout->addWidget(triesLabel);
    statsLayout->addWidget(resetButton);
    vertical->addLayout(statsLayout);
    vertical->addLayout(grid);
    QSpacerItem *spacer = new QSpacerItem(0, 30, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vertical->addSpacerItem(spacer);

    //my codes
    grid->reset();

    mainWidget->setWindowTitle("Color Game");
    mainWidget->resize(640, 480);
    mainWidget->show();
    return app.exec();
}
