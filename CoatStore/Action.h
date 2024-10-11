//
// Created by vostro on 5/14/2024.
//

#ifndef UNTITLED14_ACTION_H
#define UNTITLED14_ACTION_H

#pragma once
#include "Repo.h"
class Action {
public:
    virtual void executeUndo()=0;
    virtual void executeRedo()=0;

};

class AddAction:public Action {
private:
    Repository *repo;
    Coat addedCoat;
public:
    AddAction(Repository *r, Coat addedCoat) ;
    void executeUndo() override;

    void executeRedo() override;
};
class DeleteAction:public Action {
private:
    Repository *repo;
    Coat deletedCoat;
public:
    DeleteAction(Repository *repo,Coat deletedCoat):repo{repo},deletedCoat{deletedCoat}{}
    void executeUndo() override;
    void executeRedo() override;

};
class UpdatePriceAction : public  Action{
private:
    Repository *repo;
    Coat oldCoat;
    Coat newCoat;
public:
    UpdatePriceAction(Repository *r,Coat oldCoat,Coat newCoat):repo{r}, oldCoat{oldCoat}, newCoat{newCoat}{}
    ~UpdatePriceAction(){}
    void executeUndo() override;
    void executeRedo() override;
};
class UpdateQuantityAction : public Action{
private:
    Repository *repo;
    Coat oldCoat;
    Coat newCoat;
public:
    UpdateQuantityAction(Repository *r,Coat oldCoat,Coat newCoat):repo{r}, oldCoat{oldCoat}, newCoat{newCoat}{}
    ~UpdateQuantityAction(){}
    void executeUndo() override;
    void executeRedo() override;

};


#endif //UNTITLED14_ACTION_H
