//
// Created by vostro on 5/6/2024.
//



#include "UI.h"
#include "Exceptions.h"

UI::UI()
{
    this->service=Service();
    //this->service.generateEntities();
    // this->service.setTypeOfRepo(new FileRepo("coats.txt"));
    //this->service.setTypeOfRepo(new HTMLRepo("coats.html"));
    this->chooseRepo();
}
UI::~UI()
{

}
void UI::printUserMenu() {
    std::cout<<"1.Get coats by size"<<std::endl;
    std::cout<<"2.See the basket"<<std::endl;
    std::cout<<"3.Display the basket"<<std::endl;
}
void UI::printMenu()
{
    std::cout << "1. Admin" << std::endl;
    std::cout << "2. User" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Please enter your choice: ";
}
void UI::printAdminMenu()
{
    std::cout << "1. Add coat" << std::endl;
    std::cout << "2. Remove coat" << std::endl;
    std::cout << "3. Update coat" << std::endl;
    std::cout << "4. Print all coats" << std::endl;
    std::cout << "5. Exit" << std::endl;
}
void UI::printAllCoats() {
    for(const auto &coat: this->service.getCoats())
    {

        std::cout << "Size: " << coat.getSize() << ", Color: " << coat.getColour() << ", Price: " << coat.getPrice() << ", Quantity: " << coat.getQuantity() << ", Photo: " << coat.getPhoto() << std::endl;

    }

}
void UI::addCoat()
{
    std::string colour,photo;
    std::string size_str, quantity_str, price_str; // Input as strings
    int size, quantity, price;
    std::cout<<"Enter the size:";
    std::cin >> size_str;
    try {
        CoatValidator::validateSize(size_str);
        size=stoi(size_str);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout<<e.what()<<"\n";
        return;
    }

    std::cout<<"Enter the colour:";
    std::cin>>colour;
    try{
        CoatValidator::validateColour(colour);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout<<e.what();
        return;
    }


    std::cout<<"Enter the price";
    std::cin>>price_str;
    try {
        CoatValidator::validatePrice(price_str);
        price=std::stoi(price_str);
    }
    catch (std::invalid_argument &e)
    {
        std::cout<<e.what();
        return;
    }
    std::cout <<"Enter the quantity";
    std::cin>>quantity_str;
    try {
        CoatValidator::validateQuantity(quantity_str);
        quantity=stoi(quantity_str);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout<<e.what();
        return;

    }
    std::cout <<"Enter the photo";
    std::cin>>photo;
    Coat c(size,colour,price,quantity,photo);
//    if(this->service.addCoat(c))
//        std::cout<<"Coat added!"<<std::endl;
//    else
//        std::cout<<"Coat already exists"<<std::endl;
    try {
        this->service.addCoat(c);
        std::cout<<"Coat added!"<<std::endl;
    }
    catch(DuplicateCoatException &ex)
    {
        std::cout<<ex.what()<<"\n";
        return;
    }
    catch(RepositoryException &ex1)
    {
        std::cout<<ex1.what()<<std::endl;
        return;
    }
}
void UI::removeCoatUi() {
    this->printAllCoats();
    std::cout << "Enter the position:";
    int pos;
    std::cin >> pos;
    // if (this->service.removeCoatPosition(pos))
    try{
        this->service.removeCoatPosition(pos);
        std::cout<<"Coat removed!"<<std::endl;
    }
    catch (RepositoryException &ex)
    {
        std::cout<<ex.what()<<std::endl;
        return;
    }
}
void UI::updateCoatUI() {
    this->printAllCoats();
    int pos;
    std::cout << "Which coat do you want to update?: ";
    std::cin >> pos;
    std::cin.ignore();

    Coat coat;
    try {
        coat = this->service.getCoatByPosition(pos);
    } catch(const std::exception &ex) {
        std::cout << "Invalid position" << std::endl;
        return;
    }

    // Store old values
    int oldPrice = coat.getPrice();
    int oldQuantity = coat.getQuantity();
    std::string oldColour = coat.getColour();
    int oldSize = coat.getSize();
    std::string oldPhoto = coat.getPhoto();

    int newSize, newPrice, newQuantity;
    std::string newColour, newPhoto;

    std::cout << "Enter the new size (press Enter to keep old value): ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        newSize = oldSize;
    } else {
        try {
            CoatValidator::validateSize(input);
            newSize=std::stoi(input);
        }
        catch (std::invalid_argument &e)
        {
            std::cout<<e.what()<<"\n";
            return ;
        }
        //newSize = std::stoi(input);
    }

    std::cout << "Enter the new colour (press Enter to keep old value): ";
    std::getline(std::cin, newColour);
    if (newColour.empty()) {
        newColour = oldColour;
    }

    std::cout << "Enter the new price (press Enter to keep old value): ";
    std::getline(std::cin, input);
    if (input.empty()) {
        newPrice = oldPrice;
    } else {
        newPrice = std::stoi(input);
    }

    std::cout << "Enter the new quantity (press Enter to keep old value): ";
    std::getline(std::cin, input);
    if (input.empty()) {
        newQuantity = oldQuantity;
    } else {
        newQuantity = std::stoi(input);
    }

    std::cout << "Enter the new photo (press Enter to keep old value): ";
    std::getline(std::cin, newPhoto);
    if (newPhoto.empty()) {
        newPhoto = oldPhoto;
    }

    Coat newCoat(newSize, newColour, newPrice, newQuantity, newPhoto);

    // Check if any changes were made
    if (coat == newCoat) {
        std::cout << "No changes made." << std::endl;
        return;
    }

    // Update the coat
//    if (this->service.updateCoat(pos, newCoat)) {
//        std::cout << "Update successful." << std::endl;
//    } else {
//        std::cout << "Could not update the coat." << std::endl;
//    }
    try
    {
        this->service.updateCoat(pos,newCoat);
    }
    catch(RepositoryException &ex)
    {
        std::cout<<ex.what()<<std::endl;
        return;
    }
}

//
//void UI::updateCoatUI() {
//    this->printAllCoats();
//    int pos;
//    std::cout << "Which coat do you want to remove?: ";
//    std::cin >> pos;
//    std::cin.ignore();
//    Coat coat;
//    try
//    {
//        coat=this->service.getCoatByPosition(pos);
//    }
//    catch(const std::exception &ex)
//    {
//        std::cout<<"Invalid position";
//        return;
//    }
//    int price=coat.getPrice();
//    int quant=coat.getQuantity();
//    std::string colour=coat.getColour();
//    int size=coat.getSize();
//    std::string input;
//    int int_input;
//    std::string photo=coat.getPhoto();
//
//    std::cout<<"Enter the new size";
//    if (!(std::cin >> int_input)) {
//        std::cout << "Invalid input! Size must be an integer." << std::endl;
//        std::cin.clear();
//        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
//        return; // Exit the function
//    }
//    size=int_input;
//
//    std::cout<<"Enter the new colour";
//    std::cin>>input;
//    if(input!="")
//        colour=input;
//
//    std::cout<<"Enter the new price";
//   if(!( std::cin>>int_input)) {
//       std::cout << "invalid input";
//       std::cin.clear();
//       return;
//   }
//   if (int_input <=0)
//   {
//       std::cout<<"Price must be positive";
//       return ;
//   }
//   price = int_input;
//
//    std::cout<<"Enter the new quantity,or write nothing";
//    std::cin>>int_input;
//    if(int_input!=0)
//        quant=int_input;
//
//    std::cout<<"Enter the new photo";
//    std::cin>>input;
//    if(input!="")
//        photo=input;
//    std::cin.ignore();
//    Coat new_coat=Coat(size,colour,price,quant,photo);
//    if(coat==new_coat){
//        std::cout<<"nothing to update";
//        return;
//    }
//    if(this->service.findCoatService(new_coat))
//    {
//        std::cout<<"This coat already exists!";
//        return ;
//    }
//    if(this->service.updateCoat(pos,new_coat))
//        std::cout<<"update succefull";
//    else
//        std::cout<<"could not update the movie";
//
//}
void UI::filterCoatsUI() {
    int size;
    std::cin.ignore();
    std::cout << "Enter the size (press Enter to keep old value): ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        size = -1;
    } else {
        size = std::stoi(input);
    }
    std::vector<Coat> result;
    if (size == -1)
        result = this->service.getCoats();
    else
        result = this->service.filterCoatsBySize(size);
    int index = 0;
    int index2=0;
    while (1) {
        const Coat &coat = result[index];
        std::cout << "Size: " << coat.getSize() << ", Color: " << coat.getColour() << ", Price: " << coat.getPrice()
                  << ", Quantity: " << coat.getQuantity() << ", Photo: " << coat.getPhoto() << std::endl;
        std::cout << "Do you want to add this coat to the cart? 1-yes 2-no";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            int old_sum = this->service.getSum();
            this->service.addToBasket(coat);
            old_sum += coat.getPrice();
            this->service.setSum(old_sum);
            index2=this->service.returnPosition(coat);
            this->service.addIndexToVector(index2);
            std::cout << "Current price:" << this->service.getSum() << std::endl;
        }
        std::cout<<"Do you want to continue? 1-yes 2-no";
        std::cin>>choice;
        if(choice==2)
        {
            std::cout<<"Bye!";
            break;
        }
        else
        {
            if(index==result.size())
                index=0;
            else
                index++;
        }

    }
//        for(int i=0;i<result.getSize();i++)
//        {
//            const Coat &coat=result.getElement(i);
//            //const Coat &coat=coats.getElement(i);
//            std::cout << "Size: " << coat.getSize() << ", Color: " << coat.getColour() << ", Price: " << coat.getPrice() << ", Quantity: " << coat.getQuantity() << ", Photo: " << coat.getPhoto() << std::endl;
//
//        }

}

void UI::runApp() {
    this->printMenu();
    int choice;
    std::cout<<"Chose an option";
    std::cin>>choice;
    if (choice == 1)
        this->service.setAdmin(true);
    else if (choice == 2)
        this->service.setAdmin(false);
    else if (choice == 3)
    {
        std::cout << "Exiting..." << std::endl;
        return;
    }
    while(true)
    {
        if(this->service.getNrElems()==0)
            std::cout<<"there are no coats";
        if(this->service.getAdmin())
        {
            this->printAdminMenu();
            this->printAllCoats();
            //this->displayFile();
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (choice == 1)
                this->addCoat();
            else if(choice==2)
                this->removeCoatUi();
            else if(choice==3)
                this->updateCoatUI();
            else if(choice==5)
                break;

        }
        else {
            this->printUserMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if(choice==1)
                this->filterCoatsUI();
            else if(choice==2)
                this->getCart();
            else if(choice==3)
                this->displayFile();
            else if(choice==0)
                break;


        }
    }
}
void UI::getCart() {
    // DynamicVector<int> indexes=this->service.getIndexVector();
//    std::vector<int> indexes=this->service.getIndexVector();
//    for(auto i:indexes)
//        std::cout<<i<<" ";
//    int len=indexes.size();
//    if(len==0) {
//        std::cout<<"There are no elements in the cart";
//        return;
//    }
//
//   for(int i=0;i<len;i++)
//    {
//        int value=indexes[i];
//        std::cout<<value;
//        const Coat &coat=this->service.getCoatByPosition(value);
//        //std::cout << "Size: " << coat.getSize() << ", Color: " << coat.getColour() << ", Price: " << coat.getPrice() << ", Quantity: " << coat.getQuantity() << ", Photo: " << coat.getPhoto() << std::endl;
//
//    }
    for(auto c:this->service.getBasket())
    {
        std::cout<<"Size: "<<c.getSize()<<", Colour: "<<c.getColour()<<", Price: "<<c.getPrice()<<", Quantity: "<<c.getQuantity()<<", Photo: "<<c.getPhoto()<<std::endl;
    }

}

void UI::displayFile() {
    this->service.displayFile();
}

void UI::chooseRepo() {
    std::cout<<"1.File repo\n";
    std::cout<<"2.HTML repo\n";
    int choice;
    this->service.setTypeOfRepo(new FileRepo("coats.txt"));
    std::cin>>choice;
    if(choice==1) {
        //this->service.setTypeOfRepo(new FileRepo("coats.txt"));
        this->service.setBasket(new FileRepo("basket.txt"));
    }
    else if(choice==2) {
        //this->service.setTypeOfRepo(new HTMLRepo("coats.html"));
        this->service.setBasket(new HTMLRepo("basket.html"));
    }
    else
        std::cout<<"Invalid choice";
}