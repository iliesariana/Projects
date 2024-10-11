//
// Created by vostro on 6/15/2024.
//

#ifndef STARS_ASTRONAUT_H
#define STARS_ASTRONAUT_H
#pragma once
#include <iostream>
#include <string>


class Astronaut {
private:
    std::string name;
    std::string constellation;
public:
    Astronaut(std::string name="",std::string constelation=""):name{name},constellation{constelation}{};
    ~Astronaut()=default;
    std::string getName(){return this->name;}
    std::string getConstellation(){return this->constellation;}



};


#endif //STARS_ASTRONAUT_H
