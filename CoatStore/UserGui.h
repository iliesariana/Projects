//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_USERGUI_H
#define UNTITLED14_USERGUI_H



#endif //UNTITLED14_USERGUI_H

#pragma once
#include"Service.h"
#include <QVBoxLayout>
#include <qwidget.h>
#include <qlistwidget.h>
//#include "AbstractShoppingBasket.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QDialog>
#include <QTableView>
#include "TableMode.h"
class UserModeGUI: public QDialog {

private:
  //  UserModeGUI(Service &service, QWidget *parent);

    int size;
    int position;
    //AbstractShoppingBasket* ASB;
    Service& service;
    QListWidget* coatsListWidget;
    QListWidget* shoppingBasketListWidget;
    QComboBox *sizeComboBox;
    QPushButton* displayProductsButton, * openApplicationButton, * displayShoppingBasketButton;
    QPushButton* nextButton, * buyButton, *payButton;
    QPushButton* tableButton;

    QTableView* shoppingBasketTableView;
    TableMode* tableMode;
    int columnCount = 4;
    int rowCount = 0;

public:
    UserModeGUI(Service& service, QWidget* parent = nullptr);

    ~UserModeGUI();
    void connectSignalsAndSlots();
    int getSelectedIndex();
    void initUserModeGUI();

    void connectSignalsAndSlotsDisplayFunction();

    void populateShoppingBag();
    void openApplication();
    void openTableView();

    void populateDisplayProducts(int position, std::vector<Coat> coats);
    void displayUserProducts();
    void nextProduct();
    void buyProduct();
    void initDisplayProducts();
    void displayProducts();
    void clearPopulatedList();

};