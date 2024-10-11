//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_GUI_H
#define UNTITLED14_GUI_H

#endif //UNTITLED14_GUI_H

#include "service.h"
#include "Exceptions.h"

#include <QVBoxLayout>
#include "AdminGui.h"
#include "UserGui.h"
#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QMainWindow>

class GUI: public QMainWindow
{
Q_OBJECT
private:
    std::string type = "empty";
    Service& service;
    //Repository *basket;
    //AbstractShoppingBasket* ASB;
    void initGUI();
    ///Graphical elements
    QComboBox *filetypeComboBox;
    QPushButton* adminModeButton, * userModeButton, *saveButton, *openChart;

public:
    GUI(Service& service, QWidget *parent = nullptr);
    ~GUI();
    void connectSignalsAndSlots();
    void startUserModeGUI();
    void startAdminModeGUI();
    void saveFileType();
    void createChart();

};