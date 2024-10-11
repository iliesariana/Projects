//
// Created by vostro on 5/6/2024.
//

#include "Repo.h"

Repository::Repository()
{
    this->coats = std::vector<Coat>();
}

Repository::~Repository()
{

}

void Repository::addCoat(const Coat &coat)
{
    this->coats.push_back(coat);
}

void Repository::removeCoat(Coat &coat)
{
    std::vector<Coat>::iterator it=std::find(this->coats.begin(),this->coats.end(),coat);
    this->coats.erase(it);
}

void Repository::removeCoatByPosition(int positionOfCoatToBeRemoved)
{
    //this->coats.removeElement(positionOfCoatToBeRemoved);
    this->coats.erase(this->coats.begin()+positionOfCoatToBeRemoved);

}

void Repository::updateCoat(int positionOfCoatToBeUpdated, const Coat &coatWithUpdatedData)
{
    //this->coats.updateElement(positionOfCoatToBeUpdated, coatWithUpdatedData);
    this->coats[positionOfCoatToBeUpdated]=coatWithUpdatedData;
}

std::vector<Coat> Repository::getCoats() const
{
    return this->coats;
}

int Repository::getCoatsCount() const
{
    return this->coats.size();
}

Coat Repository::getCoatByPosition(int position) const
{
    if(position < 0 || position >=this->coats.size())
        throw InvalidPositionException();
    return this->coats[position];
}

bool Repository::validatePosition(int position) const
{
    return position >= 0 && position < this->coats.size();
}

int Repository::returnPosition(const Coat &coat) const
{
    auto iterator=std::find(this->coats.begin(),this->coats.end(),coat);
    if(iterator==this->coats.end())
        return -1;
    return std::distance(this->coats.begin(),iterator);
}
bool Repository::findCoat(Coat &coat) {
    for(const auto & i : this->coats)
        if(i==coat)
            return true;
    return false;
}
int Repository::getPosPriceUpdate(int size, std::string colour, std::string photo) {
    for(int i=0;i<this->coats.size();i++)
        if(this->coats[i].getSize()==size && this->coats[i].getColour()==colour && this->coats[i].getPhoto()==photo)
            return i;
    return -1;
}

int Repository::getPosQuantityUpdate(int size, std::string colour, std::string photo) {
    for (int i = 0; i < this->coats.size(); i++)
        if (this->coats[i].getSize() == size && this->coats[i].getColour() == colour &&
            this->coats[i].getPhoto() == photo)
            return i;
    return -1;
}

Coat Repository::getCoatToUpdate(int size,std::string colour,std::string photo) {
    int pos=this->getPosPriceUpdate(size,colour,photo);
    return this->coats[pos];
}
