//
// Created by vostro on 5/6/2024.
//

#include "AdminGui.h"
#include"qformlayout.h"
#include"qgridlayout.h"
#include<qlabel.h>
#include <QMessageBox>
#include"Exceptions.h"

AdminGui::AdminGui(Service &service, QWidget *parent) : service{service}, QDialog{parent}{
    this->initAdminModeGUI();
    this->connectSignalsAndSlots();
    this->populateList();
}
void AdminGui::initAdminModeGUI() {
    QFont buttonsFont("Arial", 12,true);
    this->coatsListWidget=new QListWidget{};
    this->coatsListWidget->setFont(buttonsFont);
    this->sizeComboBox=new QComboBox{};
    this->sizeComboBox->setFont(buttonsFont);

    this->sizeComboBox->addItem("34");
    this->sizeComboBox->addItem("35");
    this->sizeComboBox->addItem("36");
    this->sizeComboBox->addItem("37");
    this->sizeComboBox->addItem("38");
    this->sizeComboBox->addItem("39");
    this->sizeComboBox->addItem("40");


    this->colorLineEdit = new QLineEdit{};
    this->colorLineEdit->setFont(buttonsFont);

    this->priceLineEdit = new QLineEdit{};
    this->priceLineEdit->setFont(buttonsFont);

    this->quantityLineEdit = new QLineEdit{};
    this->quantityLineEdit->setFont(buttonsFont);

    this->linkLineEdit= new QLineEdit{};
    this->linkLineEdit ->setFont(buttonsFont);

    this->addButton = new QPushButton{"Add"};
    this->addButton->setFont(buttonsFont);



    this->deleteButton = new QPushButton{"Delete"};
    this->deleteButton->setFont(buttonsFont);

    this->updatePriceButton=new QPushButton{"Update"};
    this->displayButton=new QPushButton{"Display"};
    this->updatePriceButton->setFont(buttonsFont);
    this->displayButton->setFont(buttonsFont);

    this->updateQuantityButton=new QPushButton{"Update Quantity"};
    this->updateQuantityButton->setFont(buttonsFont);

    this->undoButton=new QPushButton{"Undo"};
    this->redoButton=new QPushButton{"Redo"};
    this->undoButton->setFont(buttonsFont);
    this->redoButton->setFont(buttonsFont);

    QLabel *space=new QLabel();
    space->setText("");

    QLabel *coatsText=new QLabel();
    coatsText->setText("The list of coats");

    QFont coatsFont("Consolas", 15, true);
    coatsText->setFont(coatsFont);
    QLabel *size = new QLabel();
    size->setText("Size");
    size->setFont(buttonsFont);

    QLabel *color = new QLabel();
    color->setText("Color");
    color->setFont(buttonsFont);

    QLabel *price = new QLabel();
    price->setText("Price");
    price->setFont(buttonsFont);

    QLabel *quantity = new QLabel();
    quantity->setText("Quantity");
    quantity->setFont(buttonsFont);

    QLabel *photograph = new QLabel();
    photograph->setText("Photograph");
    photograph->setFont(buttonsFont);

    QVBoxLayout* adminLayout=new QVBoxLayout();
    adminLayout->addWidget(coatsText);
    adminLayout->addWidget(this->coatsListWidget);

    QFormLayout* coatsDetails=new QFormLayout();
    coatsDetails->addRow(size,this->sizeComboBox);
    coatsDetails->addRow(color,this->colorLineEdit);
    coatsDetails->addRow(price,this->priceLineEdit);
    coatsDetails->addRow(quantity,this->quantityLineEdit);
    coatsDetails->addRow(photograph,this->linkLineEdit);
    adminLayout->addLayout(coatsDetails);


    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);

    buttonsLayout->addWidget(this->updatePriceButton, 1, 0);

    buttonsLayout->addWidget(this->displayButton, 1, 1);
    buttonsLayout->addWidget(this->updateQuantityButton, 2, 0);
    buttonsLayout->addWidget(this->undoButton, 2, 1);
    buttonsLayout->addWidget(this->redoButton, 3, 0);
    //this->undoShortcut=new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Z),admi);
   // this->redoShortcut=new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y),this);

  //  connect(undoShortcut,&QShortcut::activated,AdminGui,&AdminGui::undoAdminMode);

    adminLayout->addLayout(buttonsLayout);
    QWidget* adminDisplayWindow=new QWidget();

    this->undoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Z), adminDisplayWindow);

    this->redoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Y), adminDisplayWindow);

    adminDisplayWindow->setLayout(adminLayout);
    adminDisplayWindow->show();

}

void AdminGui::populateList() {
    this->coatsListWidget->clear();
    std::vector<Coat> coats = this->service.getCoats();
    for(auto &c:coats)
    {
        this->coatsListWidget->addItem(QString::fromStdString(std::to_string(c.getSize()) + " - " + c.getColour() + " - " + std::to_string(c.getPrice()) + " - " + std::to_string(c.getQuantity())
                                                              + " - " + c.getPhoto()));
    }
}

void AdminGui::connectSignalsAndSlots() {
    QObject::connect(this->coatsListWidget,&QListWidget::itemSelectionChanged,[this](){
        int selectedIndex=this->getSelectedIndex();
        if(selectedIndex<0)
            return;
        Coat c=this->service.getCoats()[selectedIndex];
        this->sizeComboBox->setCurrentText(QString::fromStdString(std::to_string(c.getSize())));
        this->colorLineEdit->setText(QString::fromStdString(c.getColour()));
        this->priceLineEdit->setText(QString::fromStdString(std::to_string(c.getPrice())));
        this->quantityLineEdit->setText(QString::fromStdString(std::to_string(c.getQuantity())));
        this->linkLineEdit->setText(QString::fromStdString(c.getPhoto()));
    });
    QObject::connect(this->addButton,&QPushButton::clicked,this,&AdminGui::addCoat);
    QObject::connect(this->deleteButton,&QPushButton::clicked,this,&AdminGui::removeCoat);
    QObject::connect(this->updatePriceButton,&QPushButton::clicked,this,&AdminGui::updateCoat);
    QObject::connect(this->updateQuantityButton,&QPushButton::clicked,this,&AdminGui::updateQuantity);
   // QObject::connect(this->updateQuantityButton,&QPushButton::clicked,&AdminGui::updateQuantity);
    QObject::connect(this->displayButton,&QPushButton::clicked,[this](){
        this->populateList();
    });
    QObject::connect(this->redoButton,&QPushButton::clicked,this,&AdminGui::redoAdminMode);
    QObject::connect(this->undoButton,&QPushButton::clicked,this,&AdminGui::undoAdminMode);
    QObject::connect(this->undoShortcut,&QShortcut::activated,this,&AdminGui::undoAdminMode);
    QObject::connect(this->redoShortcut,&QShortcut::activated,this,&AdminGui::redoAdminMode);


}
int AdminGui::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->coatsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.size()==0)
    {
        this->sizeComboBox->setCurrentText("");
        this->colorLineEdit->setText("");
        this->priceLineEdit->setText("");
        this->quantityLineEdit->setText("");
        this->linkLineEdit->setText("");
        return -1;

    }
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}
void AdminGui::addCoat()
{
    std::string size = this->sizeComboBox->currentText().toStdString();
    std::string color = this->colorLineEdit->text().toStdString();
   std:: string price = this->priceLineEdit->text().toStdString();
    std::string quantity = this->quantityLineEdit->text().toStdString();
   std:: string photograph = this->linkLineEdit->text().toStdString();
    try {
        CoatValidator::validateSize(size);
        int size1=stoi(size);
    }
    catch (const std::invalid_argument& e)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try {
        CoatValidator::validateQuantity(quantity);
        int quantity1=stoi(quantity);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try {
        CoatValidator::validatePrice(price);
        int price1=stoi(price);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try {
        CoatValidator::validateColour(color);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try {
        CoatValidator::validatePhoto(photograph);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }

//    int validate_price = Validator::validate_price_product(price);
//    int validate_quantity = Validator::validate_quantity_product(quantity);
    int price1=stoi(price);
    int quantity1=stoi(quantity);
    Coat c=Coat(stoi(size),color,price1,quantity1,photograph);

//    if(!Validator::validate_color_product(color) || validate_price == -1
//       || validate_quantity == -1 || !Validator::validate_photograph_product(photograph))
//    {
//        QMessageBox::critical(this, "Error", "Invalid input!");
//        return;
//    }
//    else
//    {
//        try{
//            this->service.AddService(size, color, stoi(price), stoi(quantity), photograph);
//        }
//        catch (...)
//        {
//            QMessageBox::critical(this, "Error", "Couldn't add the product!");
//            return;
//        }
//    }
try {
    this->service.addCoat(c);
    this->populateList();

}catch(...)
{
    QMessageBox::critical(this, "Error", "Couldn't add the product!");
            return;
}


    int lastElement = this->service.getRepo()->getSize()-1;
    this->coatsListWidget->setCurrentRow(lastElement);
}
void AdminGui::removeCoat() {
    std::string size = this->sizeComboBox->currentText().toStdString();
    std::string color = this->colorLineEdit->text().toStdString();
    std::string photograph = this->linkLineEdit->text().toStdString();
    std::string price = this->priceLineEdit->text().toStdString();
    std::string quantity = this->quantityLineEdit->text().toStdString();
    int pos=this->service.returnPosition(Coat(stoi(size),color,stoi(price),stoi(quantity),photograph));

//    if(!Validator::validate_color_product(color) || !Validator::validate_photograph_product(photograph))
//    {
//        QMessageBox::critical(this, "Error", "Invalid input!");
//        return;
//    }
//    else
//    {
//        try{
//            this->service.DeleteService(size, color, photograph, 1);
//        }
//        catch (...)
//        {
//            QMessageBox::critical(this, "Error", "Couldn't delete the product!");
//            return;
//        }
//    }
    try {
        CoatValidator::validateSize(size);
        int size1=stoi(size);
    }
    catch (const std::invalid_argument& e)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try {
        CoatValidator::validateQuantity(quantity);
        int quantity1=stoi(quantity);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try {
        CoatValidator::validatePrice(price);
        int price1=stoi(price);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try {
        CoatValidator::validateColour(color);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try {
        CoatValidator::validatePhoto(photograph);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    try{
            this->service.removeCoatPosition(pos);
        }
        catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't delete the product!");
            return;
        }
    this->populateList();
    int lastElement = this->service.getRepo()->getSize()-1;
    this->coatsListWidget->setCurrentRow(lastElement);

}
void AdminGui::updateQuantity() {
    std::string size = this->sizeComboBox->currentText().toStdString();
    std::string color = this->colorLineEdit->text().toStdString();
    std::string price = this->priceLineEdit->text().toStdString();
    std::string quantity = this->quantityLineEdit->text().toStdString();
    std::string photograph = this->linkLineEdit->text().toStdString();
    try {
        this->service.updateQuantity(stoi(size), color, photograph, stoi(quantity), stoi(price));

    }
    catch(...) {
    QMessageBox::critical(this,"Error","Couldn't update the product!");
    return;
    }
    this->populateList();
    int lastElement = this->service.getRepo()->getSize() - 1;
    this->coatsListWidget->setCurrentRow(lastElement);


}
void AdminGui::updateCoat() {
    std::string size = this->sizeComboBox->currentText().toStdString();
    std::string color = this->colorLineEdit->text().toStdString();
    std::string price = this->priceLineEdit->text().toStdString();
    std::string quantity = this->quantityLineEdit->text().toStdString();
    std::string photograph = this->linkLineEdit->text().toStdString();
    int price1 = stoi(price);
    int quantity1 = stoi(quantity);
    Coat c = Coat(stoi(size), color, price1, quantity1, photograph);
    try {
        //this->service.updateCoat(pos, c);
        this->service.updatePrice(stoi(size), color, photograph, stoi(quantity), stoi(price));

    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Couldn't update the product!");
        return;
    }
    this->populateList();
    int lastElement = this->service.getRepo()->getSize() - 1;
    this->coatsListWidget->setCurrentRow(lastElement);

}

void AdminGui::undoAdminMode() {
    try{
        this->service.undoAdminMode();
        this->populateList();
    }
    catch(...)
    {
        QMessageBox::critical(this,"Error","Couldn't undo the last action!");
        return ;
    }

}
void AdminGui::redoAdminMode() {
    try{
        this->service.redoAdminMode();
        this->populateList();
    }
    catch(...)
    {
        QMessageBox::critical(this,"Error","Couldn't redo the last action!");
        return ;
    }
}