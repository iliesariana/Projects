//
// Created by vostro on 5/14/2024.
//

#include "Action.h"
void AddAction::executeUndo() {
    this->repo->removeCoat(this->addedCoat);
}
void AddAction::executeRedo() {
    this->repo->addCoat(this->addedCoat);
}
void DeleteAction::executeRedo() {
    this->repo->removeCoat(this->deletedCoat);
}
void DeleteAction::executeUndo() {
    this->repo->addCoat(this->deletedCoat);
}
AddAction::AddAction(Repository *r, Coat addedCoat)
{
    this->repo=r;
    this->addedCoat=addedCoat;
}

void UpdatePriceAction::executeUndo() {
   int pos= this->repo->getPosPriceUpdate(this->newCoat.getSize(),this->newCoat.getColour(),this->newCoat.getPhoto());
    this->repo->updateCoat(pos,this->oldCoat);

}
void UpdatePriceAction::executeRedo() {

    int pos=this->repo->getPosPriceUpdate(this->oldCoat.getSize(),this->oldCoat.getColour(),this->oldCoat.getPhoto());
    this->repo->updateCoat(pos,this->newCoat);
}

void UpdateQuantityAction::executeRedo() {
    int pos=this->repo->getPosQuantityUpdate(this->oldCoat.getSize(),this->oldCoat.getColour(),this->oldCoat.getPhoto());
    this->repo->updateCoat(pos,this->newCoat);

}
void UpdateQuantityAction::executeUndo()
{
    int pos=this->repo->getPosQuantityUpdate(this->newCoat.getSize(),this->newCoat.getColour(),this->newCoat.getPhoto());
    this->repo->updateCoat(pos,this->oldCoat);
}
