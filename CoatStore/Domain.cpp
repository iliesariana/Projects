//
// Created by vostro on 5/6/2024.
//
//
// Created by vostro on 4/9/2024.
//


#include "domain.h"
#include "Utils.h"
#include "Exceptions.h"
#include <string>
// Constructor definition
Coat::Coat(int size, const std::string& colour, int price, int quantity, const std::string& photo)
        : size{size}, colour{colour}, price{price}, quantity{quantity}, photograph{photo}{

}
std::string Coat::toString() {
    return "Size: "+std::to_string(this->size)+" Colour: "+this->colour+" Price: "+std::to_string(this->price)+" Quantity: "+std::to_string(this->quantity)+" Photograph: "+this->photograph;
}
Coat ::Coat(const Coat &coat)
{
    this->quantity=coat.quantity;
    this->colour=coat.colour;
    this->size=coat.size;
    this->price=coat.price;
    this->photograph=coat.photograph;
}
Coat::~Coat(){}

bool Coat::operator==(const Coat &coat) const {
    return this->size==coat.size && this->photograph==coat.photograph && this->quantity==coat.quantity && this->colour==coat.colour && this->price==coat.price;
}
std::ostream &operator<<(std::ostream &os, const Coat &coat) {
    os<<coat.size<<","<<coat.colour<<","<<coat.price<<","<<coat.quantity<<","<<coat.photograph;
    return os;
}

std::istream &operator>>(std::istream &is, Coat &coat) {
    std::string line;
    getline(is,line);
    std::vector<std::string> tokens=tokenize(line,',');
    if(tokens.size()!=5)
        return is;
    coat.size=stoi(tokens[0]);
    coat.colour=tokens[1];
    coat.price=stoi(tokens[2]);
    coat.quantity=stoi(tokens[3]);
    coat.photograph=tokens[4];
    return is;


}


