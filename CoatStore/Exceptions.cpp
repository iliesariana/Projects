//
// Created by vostro on 4/11/2024.
//

#include "Exceptions.h"
FileException::FileException(const std::string &message) {
    this->message=message;
}
const char * FileException::what() {
    return this->message.c_str();
}

ServiceException::ServiceException() {
    this->message="";
}
ServiceException::ServiceException(const std::string &message) {
    this->message=message;
}
const char *ServiceException::what() {
    return this->message.c_str();
}

RepositoryException::RepositoryException() :std::exception()
{
    this->message="";
}
RepositoryException::RepositoryException(const std::string &message) {
    this->message=message;
}
const char * RepositoryException::what() {
    return this->message.c_str();
}
CoatExceptions::CoatExceptions(std::vector<std::invalid_argument> errors) {
    this->errors=errors;
}
CoatExceptions::CoatExceptions(std::string error) {
    std::invalid_argument error1(error);
    this->errors.push_back(error1);
}

void CoatValidator::validateSize(const std::string &size) {
    if(size.empty())
        throw std::invalid_argument("The size cannot be empty!");
    try{
        std::stoi(size);
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("The size must be an integer");
    }
    if(stoi(size)<0)
        throw std::invalid_argument("the size must be positive");

}
void CoatValidator::validateColour(const std::string &colour) {
    if(colour.empty())
        throw std::invalid_argument("The colour cannot be empty!");
}

void CoatValidator::validatePhoto(const std::string &photo) {
    if(photo.empty())
        throw std::invalid_argument("The photo cannot be empty!");
}
void CoatValidator::validatePrice(const std::string &price) {
    if(price.empty())
        throw std::invalid_argument("The price cannot be empty!");
    try {
        std::stoi(price);
    }
    catch(const std::exception &e)
    {
        throw std::invalid_argument("The price must be an integer!");
    }
    if(std::stoi(price)<0)
        throw std::invalid_argument("The price must be a positive integer!");
}
void CoatValidator::validateQuantity(const std::string &quantity) {
    if(quantity.empty())
        throw std::invalid_argument("The quantity cannot be empty!");
    try {
        std::stoi(quantity);
    }
    catch(const std::exception &e)
    {
        throw std::invalid_argument("The quantity must be an integer!");
    }
    if(std::stoi(quantity)<0)
        throw std::invalid_argument("The quantity must be a positive integer!");
}
void CoatValidator::validateCoat(const std::string &size, const std::string &colour, const std::string &price, const std::string &quantity, const std::string &photo) {
    std::vector<std::invalid_argument> errors;
    try {
        validateSize(size);
    }
    catch(const std::exception &e)
    {
        errors.push_back(std::invalid_argument(e.what()));
    }
    try {
        validateColour(colour);
    }
    catch(const std::exception &e)
    {
        errors.push_back(std::invalid_argument(e.what()));
    }
    try {
        validatePrice(price);
    }
    catch(const std::exception &e)
    {
        errors.push_back(std::invalid_argument(e.what()));
    }
    try {
        validateQuantity(quantity);
    }
    catch(const std::exception &e)
    {
        errors.push_back(std::invalid_argument(e.what()));
    }
    try {
        validatePhoto(photo);
    }
    catch(const std::exception &e)
    {
        errors.push_back(std::invalid_argument(e.what()));
    }
    if(!errors.empty())
        throw CoatExceptions(errors);
}
std::vector<std::invalid_argument> CoatExceptions::returnErrors() {
    return this->errors;
}
const char* InvalidPositionException::what() {
    return "The position is invalid!";
}
const char *DuplicateCoatException::what() {
    return "The coat already exists!";
}