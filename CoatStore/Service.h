//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_SERVICE_H
#define UNTITLED14_SERVICE_H

#pragma once
#include "Repo.h"
#include "FileRepo.h"
#include <iostream>
#include"Action.h"
class Service {
private:
    std::vector<Action *> undoStackAdmin;
    std::vector<Action *> redoStackAdmin;
    std::vector<Action *> redoStackUser;
    std::vector<Action *> undoStackUser;
    Repository *repo;
    bool admin;
    int sum;
    Repository *basket;
    std::vector<int> indexes;
public:

    void undoLastAction(std::vector<Action *> &undoStack,std::vector<Action *> &redoStack);
    void redoLastAction(std::vector<Action *> &undoStack,std::vector<Action *> &redoStack);
    void undoAdminMode();
    void redoAdminMode();
    void undoUserMode();
    void redoUserMode();

    Service();
    ~Service();
    int getSum();
    void setSum(int new_sum);
    void addToBasket(const Coat &c);
    void generateEntities();
    bool addCoat(const Coat &coat);
    //std::vector<Coat> filterCoatsBySize(int size);
    //Repository getRepo() const;
    bool removeCoatPosition(int pos);
    void setAdmin(bool value);
    std::vector<Coat> getCoats() const;
    int getNrElems() const;
    bool getAdmin() const;
    bool updateCoat(int pos,const Coat& coat);
    Coat getCoatByPosition(int pos);
    bool findCoatService(Coat coat);
    void addIndexToVector(int pos);
    //DynamicVector<int> getIndexVector() const ;
    std::vector<int> getIndexVector() const;
    std::vector<Coat> filterCoatsBySize(int size);
    void setTypeOfRepo(Repository *r);
    void displayFile();
    void setBasket(Repository *r);
    std::vector<Coat> getBasket();
    int returnPosition(const Coat &c);
    Repository *getRepo() const;
    void updatePrice(int size,const std::string& colour,const std::string& photo,int quantity,int price);
    void updateQuantity(int size,const std::string& colour,const std::string& photo,int price,int quantity);
    Repository *getBasketRepo() const{ return this->basket;}
};

#endif //UNTITLED14_SERVICE_H
