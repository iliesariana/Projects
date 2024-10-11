//
// Created by vostro on 5/31/2024.
//

#ifndef STARS_GUI_H
#define STARS_GUI_H
#pragma once
#include "StarFilterModel.h"
#include "QSortFilterProxyModel"
#include <QWidget>
#include "Repository.h"
#include "starsModel.h"
#include "Astronaut.h"
#include "Service.h"
QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
Q_OBJECT

public:
    explicit gui(starsModel *model,Astronaut aust,Service &service,QWidget *parent = nullptr);

    ~gui() override;
public slots:
    void showConstellationsFiltered();
    void addStar();
    void populateFilteredList();
    void drawConst();
    void filterConstellations();

private:
    Ui::gui *ui;
    starsModel *stars;
    void populateList();
    Service &service;
    Astronaut aust;
    StarFilterModel *model;

};


#endif //STARS_GUI_H
