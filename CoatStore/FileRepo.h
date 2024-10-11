//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_FILEREPO_H
#define UNTITLED14_FILEREPO_H


#pragma once
#include "Repo.h"

class FileRepo :public Repository {
private:
    std::string filename;
public:
    FileRepo(const std::string &filename);
    virtual ~FileRepo();
    void writeToFile();
    void readFromFile();
    void addCoat(const Coat &coat) ;
    void removeCoat(Coat &coat);
    void removeCoatByPosition(int position);
    void updateCoat(int position, const Coat &coat);

    void display() override;

};

#endif //UNTITLED14_FILEREPO_H
