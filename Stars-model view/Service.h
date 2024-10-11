//
// Created by vostro on 6/15/2024.
//

#ifndef STARS_SERVICE_H
#define STARS_SERVICE_H

#pragma once
#include "Repository.h"
class Service {
private:
    Repository &repo;
public:
    Service(Repository &repo):repo{repo}{};
    ~Service()=default;
    std::vector<Star> &getStars(){return this->repo.getStars();}
    std::vector<Astronaut> & getAstronauts(){return this->repo.getAstronauts();}
    void addStar(const std::string &name, const std::string &constellation, const int &ra, const double &dec);
    std::vector<Star> getStarName(std::string name);
    std::vector<Star> getStarCOnstelation(std::string name);

};


#endif //STARS_SERVICE_H
