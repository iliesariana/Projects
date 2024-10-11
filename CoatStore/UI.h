//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_UI_H
#define UNTITLED14_UI_H


#pragma once
#include "Service.h"
#include "HTMLRepo.h"

class UI {
private:
    Service service;
public:
    UI();
    ~UI();
    void getCart();
    void printMenu();
    void printAdminMenu();
    void printUserMenu();
    void runApp();
    void printAllCoats();
    void addCoat();
    void removeCoatUi();
    void updateCoatUI();
    void filterCoatsUI();
    void displayFile();
    void chooseRepo();

};

#endif //UNTITLED14_UI_H
