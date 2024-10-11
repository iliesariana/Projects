//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_DOMAIN_H
#define UNTITLED14_DOMAIN_H



#pragma once
#include <string>
#include<iostream>
//size, a colour, a price, a quantity and a photograph
class Coat{
private:
    std::string photograph;
    std::string colour;
    int price,quantity,size;
public:
    //constructor
    std::string toString();
    Coat(int size=0, const std::string& colour="", int price=0, int quantity=0, const std::string& photo="");
    Coat(const Coat &coat);
    int getSize() const{return this->size;}
    std::string getColour() const{return this->colour;}
    int getPrice() const{return this->price;}
    int getQuantity() const {return this->quantity;}
    std::string getPhoto() const {return this->photograph;}
    bool operator==(const Coat &coat) const;

    ~Coat();
    friend std::ostream& operator<<(std::ostream& os, const Coat& coat);
    friend std::istream &operator>>(std::istream &is, Coat &coat);

};

#endif //UNTITLED14_DOMAIN_H
