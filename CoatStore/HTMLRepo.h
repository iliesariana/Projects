//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_HTMLREPO_H
#define UNTITLED14_HTMLREPO_H


#pragma once
#include "Repo.h"

class HTMLRepo : public Repository{
public:
    HTMLRepo(const std::string &filename);
    //~HTMLRepo() override;
    void writeToFile() override;
    void readFromFile() override{};
    void display();
private:
    std::string filename;
};



#endif //UNTITLED14_HTMLREPO_H
