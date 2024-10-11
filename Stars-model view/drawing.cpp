//
// Created by vostro on 6/25/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Drawing.h" resolved

#include "drawing.h"
#include "ui_Drawing.h"


Drawing::Drawing(std::string name,std::vector<Star> stars,QWidget *parent) :stars{stars},name{name},
        QWidget(parent), ui(new Ui::Drawing) {
    ui->setupUi(this);
}

Drawing::~Drawing() {
    delete ui;
}

void Drawing::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    this->drawMap(painter);

}

void Drawing::drawMap(QPainter &p) {
    int x=40;
    int y=40;
    for(auto s:this->stars)
    {
        int ra=s.getRa();
        int dec=s.getDec();
        int diam=rand()%10+5;
        diam*=10;
        int TopLeftX=x+ra-diam/2;
        int TopLeftY=y+dec-diam/2;
        if(s.getName()==this->name)
            p.setBrush(Qt::red);
        else
            p.setBrush(Qt::black);
        p.drawEllipse(TopLeftX,TopLeftY,diam,diam);

    }

}
