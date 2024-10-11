//
// Created by vostro on 6/15/2024.
//

#include "Service.h"
void Service::addStar(const std::string &name, const std::string &constellation, const int &ra, const double &dec) {
    Star s=Star(name,constellation,ra,dec);
    if(name=="" || dec<=0)
        throw std::exception();
    this->repo.addStar(s);
}


std::vector<Star> Service::getStarName(std::string name) {
    return this->repo.getStarsName(name);
}

std::vector<Star> Service::getStarCOnstelation(std::string name) {
    return this->repo.getStarsCOnstellation(name);
}

