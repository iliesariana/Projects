//
// Created by vostro on 5/31/2024.
//

#ifndef STARS_STAR_H
#define STARS_STAR_H


#pragma once
#include <iostream>

class Star
{
private:
    std::string name, constellation;
    int ra;
    double dec;
public:
    explicit Star(std::string name = "", std::string constellation = "", int ra = 0, double dec = 0) : name{name},
                                                                                                       constellation{constellation},
                                                                                                       ra{ra},
                                                                                                       dec{dec} {};
    std::string getName() const { return this->name; }
    void setRa(int ra){ this->ra = ra; }
   std::string getConstellation() const { return this->constellation; }
     int getRa() const { return this->ra; }
     double getDec() const { return this->dec; }

   bool operator < (const Star &other) const
    {
        return this->constellation < other.constellation;
    }
    std::string  toString(){return this->name+" "+this->constellation;}
    void setConstelation(std::string constellation) { this->constellation = constellation; };
};

#endif //STARS_STAR_H
