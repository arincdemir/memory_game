#include "mygrid.h"
#include "colorbutton.h"

MyGrid::MyGrid(QTimer *timer): QGridLayout(){
    this->timer = timer;
}


void MyGrid::check_colors(){
    bool all_same = true;
    QString prev = "";

    for(int i = 0; i < this->count(); ++i){
        ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());
        if(prev == ""){
            prev = widget->color;
        }else if(prev!= widget->color){
            all_same = false;
        }
    }
    if(all_same){
        this->timer->stop();
        QMessageBox msgBox;
        msgBox.setText("You won!");
        msgBox.exec();
        msgBox.setStandardButtons(QMessageBox::Cancel);
    }
}
