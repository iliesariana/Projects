//
// Created by vostro on 5/31/2024.
//

#ifndef STARS_REPOSITORY_H
#define STARS_REPOSITORY_H

#pragma once
#include "Star.h"
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include "Astronaut.h"
class Repository {
private:
    std::vector<Astronaut> astronauts;
    std::vector <Star> stars;
public:
    void loadStars();
    void loadAstronauts();
    Repository(){this->loadStars();this->loadAstronauts();}
    ~Repository(){}
    std::vector <Star> &getStars() { return this->stars; }
    std::vector<Astronaut> & getAstronauts(){return this->astronauts;}
    void addStar(const Star &star) { this->stars.push_back(star); }
    std::vector<Star> getStarsName(std::string name);
    std::vector<Star> getStarsCOnstellation(std::string const);
};


#endif //STARS_REPOSITORY_H
