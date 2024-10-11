//
// Created by vostro on 5/6/2024.
//

#include "HTMLRepo.h"

#include "HTMLRepo.h"
#include <fstream>
HTMLRepo::HTMLRepo(const std::string &filename) {
    this->filename=filename;
}
void HTMLRepo::writeToFile() {
    std::ofstream file(this->filename);
    file<<"<html>"<<std::endl;
    file<<"<head>"<<std::endl;
    file<<"<title>Coats</title>"<<std::endl;
    file<<"</head>"<<std::endl;
    file<<"<body>"<<std::endl;
    for(auto &coat:this->coats)
    {
        file<<"<p>"<<coat.toString()<<"</p>"<<std::endl;
    }
    file<<"</body>"<<std::endl;
    file<<"</html>"<<std::endl;
    file.close();
}
void HTMLRepo::display() {
    std::string display_site = "start \"\" \"" + this->filename + "\"";
    system(display_site.c_str());
}