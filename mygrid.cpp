#include "mygrid.h"
#include "colorbutton.h"
#include <vector>

using namespace std;

MyGrid::MyGrid(QTimer *timer): QGridLayout(){
    this->timer = timer;
    this->state = zeroShown;
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

void MyGrid::reset(){
    vector<int> vect{ 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15};
    for(int i = 0; i < this->count(); ++i){
        int index = rand() % vect.size();
        ColorButton *widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());
        widget->id = vect.at(index);
        widget->showDefaultColor();
        vect.erase(vect.begin() + index);
    }
}
