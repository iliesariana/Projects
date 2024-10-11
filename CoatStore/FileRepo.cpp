//
// Created by vostro on 5/6/2024.
//

//
// Created by vostro on 4/11/2024.
//

#include "FileRepo.h"
#include <fstream>
#include "Exceptions.h"
FileRepo::~FileRepo() {
    this->writeToFile();
}
FileRepo::FileRepo(const std::string &filename) {
    this->filename=filename;
    //this->readFromFile();
}
void FileRepo::writeToFile() {
    std::ofstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");
    for(auto &coat:this->coats)
    {
        file<<coat<<"\n";
    }
    file.close();

}
void FileRepo::removeCoat(Coat &coat) {
    Repository::removeCoat(coat);
    this->writeToFile();
}
//void FileRepo::loadIntoRepo() {
//    std::ifstream file(this->filename);
//    Coat readCoat;
//    if (!file.is_open())
//        throw FileException("The file could not be opened!");
//    int size,price,quantity;
//    std::string colour,photograph;
//    while(file>>size>>colour>>price>>quantity>>photograph)
//    {
//        std::cout<<("aaa");
//        readCoat=Coat(size,colour,price,quantity,photograph);
//        this->addCoat(readCoat);
//
//    }
//}
//void FileRepo::saveCoats() {
//    std::ofstream file(this->filename);
//    if (!file.is_open())
//        throw FileException("The file could not be opened!");
//
//    for(auto &coat:this->coats)
//    {
//        file<<coat<<"\n";
//    }
//    file.close();
//}

void FileRepo::readFromFile() {
    std::ifstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");
    Coat coat;
    while(file>>coat)
    {
        this->addCoat(coat);
    }
}
void FileRepo::addCoat(const Coat &coat) {
    Repository::addCoat(coat);
    this->writeToFile();
}
void FileRepo::removeCoatByPosition(int position) {
    Repository::removeCoatByPosition(position);
    this->writeToFile();
}
void FileRepo::updateCoat(int position, const Coat &coat) {
    Repository::updateCoat(position,coat);
    this->writeToFile();
}

void FileRepo::display() {
    std::string display_notepad = "notepad \"" + this->filename + "\"";
    system(display_notepad.c_str());
}

