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
    QWidget *cw = new QWidget; // main widget
    QVBoxLayout *vb = new QVBoxLayout(cw); // timer, grid and spaceritem
    MyGrid *gl = new MyGrid();
    QLabel *scoreLabel = new QLabel("test");
    QLabel *triesLabel = new QLabel("test");
    QPushButton *resetButton = new QPushButton("test");
    QHBoxLayout *statsLayout = new QHBoxLayout();

    for(int row=0; row<5; row++){
        for(int col=0; col<6; col++){
            int color_code = rand()%3;
            QString color;
            if(color_code == 0){
                color = "red";
            }else if(color_code == 1){
                color = "blue";
            }else{
                color = "green";
            }
            ColorButton *randButton = new ColorButton(color, "X", gl, rand());
            //QObject::connect(randButton, SIGNAL(clicked()), randButton, SLOT(change_color()));
            //QObject::connect(randButton, SIGNAL(clicked()), gl, SLOT(check_colors()));
            QObject::connect(randButton, SIGNAL(clicked()), randButton, SLOT(pressed()));

            gl->addWidget(randButton, row, col, 1, 1);

        }
    }
    statsLayout->addWidget(scoreLabel);
    statsLayout->addWidget(triesLabel);
    statsLayout->addWidget(resetButton);
    vb->addLayout(statsLayout);
    vb->addLayout(gl);
    QSpacerItem *si = new QSpacerItem(0, 30, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vb->addSpacerItem(si);

    //my codes
    gl->reset();

    cw->setWindowTitle("Color Game");
    cw->resize(640, 480);
    cw->show();
    return app.exec();
}
