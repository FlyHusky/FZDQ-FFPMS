#include "mybutton.h"

MyButton::MyButton(QWidget *parent) :
    QPushButton(parent)
{

}


void MyButton::focusInEvent(QFocusEvent *e){
    QPalette pal=this->palette();
    if(pal.color(QPalette::Button)==Qt::black){
        return;
    }
    pal.setColor(QPalette::Button,Qt::yellow);
    setPalette(pal);
//    setText("in");
}

 void MyButton:: focusOutEvent(QFocusEvent *e){
    QPalette pa=this->palette();

    if(pa.color(QPalette::Button)==Qt::black){
        return;
    }
    pa.setColor(QPalette::Button,Qt::white);
    setPalette(pa);
//    setText("out");


 }
