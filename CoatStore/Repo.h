//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_REPO_H
#define UNTITLED14_REPO_H



#pragma once
#include <vector>
#include "Domain.h"
#include <algorithm>
#include "Exceptions.h"
class Repository {

protected:
    std::vector<Coat> coats;
public:
    Repository();
    virtual ~Repository();

    virtual void addCoat(const Coat &coat);
    virtual void removeCoat(Coat &coat);
    virtual void removeCoatByPosition(int position);
    virtual void updateCoat(int position, const Coat &coat);
    bool validatePosition(int position) const;
    //DynamicVector<Coat> getCoats() const;
    std::vector<Coat> getCoats() const;
    int getCoatsCount() const;
    Coat getCoatByPosition(int position) const;
    int returnPosition(const Coat &coat) const;
    bool findCoat(Coat &coat);
    int getSize(){return coats.size();}

    virtual void writeToFile() = 0;//pure virtual function
    virtual void readFromFile() = 0;
    virtual void display()=0;

    int getPosPriceUpdate(int size,std::string colour,std::string photo);
    int getPosQuantityUpdate(int size,std::string colour,std::string photo);
    Coat getCoatToUpdate(int size,std::string colour,std::string photo);
    //void updatePrice(std::string size,std::string colour,std::string photo,int quantity);
};



#endif //UNTITLED14_REPO_H
