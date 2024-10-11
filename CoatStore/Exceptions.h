//
// Created by vostro on 5/6/2024.
//

#ifndef UNTITLED14_EXCEPTIONS_H
#define UNTITLED14_EXCEPTIONS_H


#pragma once
#include <vector>
#include <exception>
#include <string>
#include <regex>

class FileException {
private:
    std::string message;
public:
    FileException(const std::string &message) ;
    virtual const char *what();

};
class RepositoryException :public std::exception
{
protected:
    std::string message;
public:
    RepositoryException();
    RepositoryException(const std::string &message);
    virtual ~RepositoryException(){};
    virtual const char *what();
};

class DuplicateCoatException:public RepositoryException {
public:
    const char *what();
};
class InvalidPositionException:public RepositoryException {
public:
    const char *what();

};
class CoatExceptions:public std::exception
{
private:
    std::vector<std::invalid_argument> errors;
public:
    CoatExceptions(std::vector<std::invalid_argument> errors);
    CoatExceptions(std::string error);
    std::vector<std::invalid_argument> returnErrors();

};
class ServiceException :public std::exception
{
private:
    std::string message;

public:
    ServiceException();
    ServiceException(const std::string &message);
    const char *what();

};
class CoatValidator
{
public:
    static void validateSize(const std::string &size);
    static void validateColour(const std::string &colour);
    static void validatePrice(const std::string &price);
    static void validateQuantity(const std::string &quantity);
    static void validatePhoto(const std::string &photo);
    static void validateCoat(const std::string &size,const std::string &colour,const std::string &price,const std::string &quantity,const std::string &photo);
};

#endif //UNTITLED14_EXCEPTIONS_H
