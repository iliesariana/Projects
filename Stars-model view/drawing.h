//
// Created by vostro on 6/25/2024.
//

#ifndef STARS_DRAWING_H
#define STARS_DRAWING_H

#include <QWidget>
#include <QPainter>
#include "Star.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Drawing; }
QT_END_NAMESPACE

class Drawing : public QWidget {
Q_OBJECT

public:
    explicit Drawing(std::string name,std::vector<Star> stars,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void drawMap(QPainter &p);
    ~Drawing() override;

private:
    Ui::Drawing *ui;
    std::vector<Star> stars;
    std::string name;
};


#endif //STARS_DRAWING_H
