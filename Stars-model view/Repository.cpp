//
// Created by vostro on 5/31/2024.
//

#include "Repository.h"
#include <sstream>
#include <algorithm>
void Repository::loadStars() {
    std::ifstream input("stars.txt");
    const char sep = '|';
    std::string line, name, constellation, ra, dec;
    while (std::getline(input, line))
    {
        std::istringstream iss(line);
        std::getline(iss, name, sep);
        std::getline(iss, constellation, sep);
        std::getline(iss, ra, sep);
        std::getline(iss, dec, sep);
        this->stars.emplace_back(name, constellation, std::stoi(ra), std::stod(dec));
    }
}

void Repository::loadAstronauts() {
    std::ifstream input{"astronauts.txt"};
    char sep='|';
    std::string  line,name,constelation;
    while(std::getline(input,line))
    {
        std::stringstream ss(line);
        std::getline(ss,name,sep);
        std::getline(ss,constelation,sep);
        Astronaut a= Astronaut(name,constelation);
        this->astronauts.push_back(a);
    }

}

std::vector<Star> Repository::getStarsName(std::string name) {
    std::vector<Star> result;
    for(auto s:this->getStars())
        if(s.getName().find(name)!=std::string::npos)
            result.push_back(s);
    return result;
}

std::vector<Star> Repository::getStarsCOnstellation(const std::string c) {
    std::vector<Star> res;
    for(auto s:this->stars)
        if(s.getConstellation()==c)
            res.push_back(s);
    return res;
}
