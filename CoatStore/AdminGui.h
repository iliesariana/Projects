//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_ADMINGUI_H
#define UNTITLED14_ADMINGUI_H
#pragma once
#include<QWidget>
#include<qlistwidget.h>
#include<qlineedit.h>
#include<qpushbutton.h>
#include<QComboBox>
#include<QVBoxLayout>
#include"Service.h"
#include<QDialog>
#include "QShortcut"
class AdminGui : public QDialog{
private:
    Service &service;
    QListWidget* coatsListWidget;
    QLineEdit *colorLineEdit,*priceLineEdit,*quantityLineEdit,*sizeLineEdit,*linkLineEdit;
    QComboBox *sizeComboBox;
    QShortcut *undoShortcut,*redoShortcut;
    QPushButton *addButton,*removeButton,*deleteButton,*updatePriceButton,*displayButton,*updateQuantityButton,*undoButton,*redoButton;
public:
    AdminGui(Service &service, QWidget *parent = nullptr);
    ~AdminGui(){};
    void connectSignalsAndSlots();
    int getSelectedIndex() const;
    void populateList();
    void addCoat();
    void removeCoat();
    void updateCoat();
    void updateQuantity();
    void initAdminModeGUI();
    void undoAdminMode();
    void redoAdminMode();


};


#endif //UNTITLED14_ADMINGUI_H
