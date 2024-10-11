#include "Service.h"
//
// Created by vostro on 4/9/2024.
//

#include "Service.h"
Service::Service() {
    this->repo= nullptr;
    this->basket= nullptr;
    this->admin=false;
    this->sum=0;
    this->indexes=std::vector<int>();
}
Service::~Service(){

}

bool Service::addCoat(const Coat& coat) {

    if(this->repo->validatePosition(this->repo->returnPosition(coat)))
        throw DuplicateCoatException();

    this->repo->addCoat(coat);
    Action *currentAction=new AddAction(this->repo,coat);
    this->undoStackAdmin.push_back(currentAction);
    this->redoStackAdmin.clear();

    return true;
}

void Service::generateEntities() {
    Coat coat1(36, "Red", 150, 10, "red_coat.jpg");
    Coat coat2(36, "Blue", 200, 5, "blue_coat.jpg");
    Coat coat3(36, "Black", 250, 8, "black_coat.jpg");
    Coat coat4(42, "Green", 180, 12, "green_coat.jpg");
    Coat coat5(44, "Yellow", 160, 6, "yellow_coat.jpg");
    Coat coat6(46, "Pink", 220, 9, "pink_coat.jpg");
    Coat coat7(48, "Gray", 190, 11, "gray_coat.jpg");
    Coat coat8(50, "White", 170, 4, "white_coat.jpg");
    Coat coat9(52, "Purple", 210, 7, "purple_coat.jpg");
    Coat coat10(54, "Orange", 230, 3, "orange_coat.jpg");
    this->addCoat(coat1);
    this->addCoat(coat2);
    this->addCoat(coat3);
    this->addCoat(coat4);
    this->addCoat(coat5);
    this->addCoat(coat6);
    this->addCoat(coat7);
    this->addCoat(coat8);
    this->addCoat(coat9);
    this->addCoat(coat10);

}
std::vector<Coat> Service::getCoats() const  {
    return this->repo->getCoats();
}

bool Service::removeCoatPosition(int pos) {
    if(!this->repo->validatePosition(pos))
        throw InvalidPositionException();
    Action *currentAction=new DeleteAction(this->repo,this->repo->getCoatByPosition(pos));
    this->undoStackAdmin.push_back(currentAction);
    this->redoStackAdmin.clear();
    this->repo->removeCoatByPosition(pos);
    return true;
}
void Service::setAdmin(bool value) {
    this->admin=value;
}
int Service::getNrElems() const {
    return this->repo->getCoatsCount();
}
bool Service::getAdmin() const {
    return this->admin;
}

bool Service::updateCoat(int pos, const Coat& coat) {
    if(!this->repo->validatePosition(pos))
        throw InvalidPositionException();
    this->repo->updateCoat(pos,coat);
    return true;
}

Coat Service::getCoatByPosition(int pos) {
    if(this->repo->validatePosition(pos))
        throw InvalidPositionException();
    return this->repo->getCoatByPosition(pos);
}

bool Service::findCoatService(Coat coat) {
    return this->repo->findCoat(coat);
}
void Service::addToBasket(const Coat &c) {
    this->basket->addCoat(c);
    this->basket->writeToFile();
}
std::vector<Coat> Service::filterCoatsBySize(int size) {
    int found=0;
    std::vector<Coat> result=std::vector<Coat>();

    for(const auto& coat:this->getCoats())
    {
        int new_size=coat.getSize();
        if(new_size==size) {
            result.push_back(coat);
            found = 1;
        }
    }
    if(!found)
        return this->getCoats();
    else
        return result;
}

int Service::getSum() {
    return this->sum;
}

void Service::setSum(int new_sum) {
    this->sum=new_sum;

}

std::vector<int> Service::getIndexVector() const {
    return this->indexes;
}

void Service::addIndexToVector(int pos) {
    this->indexes.push_back(pos);
}
void Service::setTypeOfRepo(Repository *r) {
    this->repo=r;
    this->repo->readFromFile();
}


void Service::displayFile() {
    this->basket->display();
}

void Service::setBasket(Repository *r) {
    this->basket=r;
    this->basket->readFromFile();
}
int Service::returnPosition(const Coat &c) {
    return this->repo->returnPosition(c);
}

std::vector<Coat> Service::getBasket() {
    return this->basket->getCoats();
}

Repository *Service::getRepo() const {
    return this->repo;
}

void Service::updatePrice(int size, const std::string& colour, const std::string& photo, int quantity,int price) {
    int pos=this->repo->getPosPriceUpdate(size,colour,photo);
    Coat c1=Coat(size,colour,price,quantity,photo);//new coat
   // Coat::Coat(int size, const std::string& colour, int price, int quantity, const std::string& photo)
   Coat oldCoat=this->repo->getCoatByPosition(pos);

    this->updateCoat(pos,c1);

    Action *currentAction=new UpdatePriceAction(this->repo,oldCoat,c1);


    this->undoStackAdmin.push_back(currentAction);
    this->redoStackAdmin.clear();
}
void Service::updateQuantity(int size, const std::string &colour, const std::string &photo, int price, int quantity) {
    int pos=this->repo->getPosQuantityUpdate(size,colour,photo);
    Coat c1=Coat(size,colour,price,quantity,photo);
    Coat oldCoat=this->repo->getCoatByPosition(pos);
    Action *currentAction=new UpdateQuantityAction(this->repo,oldCoat,c1);

    this->undoStackAdmin.push_back(currentAction);
    this->redoStackAdmin.clear();
    this->redoStackAdmin.clear();
    this->updateCoat(pos,c1);

}


void Service::undoLastAction(std::vector<Action *> &undoStack, std::vector<Action *> &redoStack) {
    if(undoStack.empty())
        throw ServiceException("No more undos!");
    Action *currentAction=undoStack.back();
    currentAction->executeUndo();
    redoStack.push_back(currentAction);
    undoStack.pop_back();
}

void Service::redoLastAction(std::vector<Action *> &undoStack, std::vector<Action *> &redoStack) {
    if(redoStack.size()==0)
        throw ServiceException("No more redos!");
    Action *currentAction=redoStack.back();
    undoStack.push_back(currentAction);
    currentAction->executeRedo();
    redoStack.pop_back();
}
void Service::undoAdminMode() {
    this->undoLastAction(this->undoStackAdmin,this->redoStackAdmin);
}
void Service::redoAdminMode() {
    this->redoLastAction(this->undoStackAdmin,this->redoStackAdmin);
}
void Service::undoUserMode() {
    this->undoLastAction(this->undoStackUser,this->redoStackUser);
}
void Service::redoUserMode() {
    this->redoLastAction(this->undoStackUser,this->redoStackUser);
}