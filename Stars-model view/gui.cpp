//
// Created by vostro on 5/31/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include <QMessageBox>
#include "gui.h"
#include "ui_gui.h"
#include "drawing.h"
#include "StarFilterModel.h"

gui::gui(starsModel *model,Astronaut a,Service &service,QWidget *parent) :stars{model},service{service}, aust{a},
        QWidget(parent), ui(new Ui::gui) {
    ui->setupUi(this);
    this->model=new StarFilterModel();
    this->model->setSourceModel(this->stars);
    ui->tableView->setModel(this->model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

   // this->populateList();
    this->setWindowTitle(QString::fromStdString(a.getName()));
    connect(ui->checkBox,&QCheckBox::stateChanged,this,&gui::filterConstellations);
    connect(ui->pushButton,&QPushButton::clicked,this,&gui::addStar);
    connect(ui->starName,&QLineEdit::textChanged,this,&gui::populateFilteredList);
    connect(ui->viewButton,&QPushButton::clicked,this,&gui::drawConst);

}

gui::~gui() {
    delete ui;
}

void gui::populateList() {
    this->stars->updateData();
}

void gui::showConstellationsFiltered() {
    if(ui->checkBox->isChecked())
    {
        this->model->setFilterRegularExpression(QRegularExpression(QString::fromStdString(this->aust.getConstellation()),QRegularExpression::CaseInsensitiveOption));
        this->model->setFilterKeyColumn(1);
    }
    else
        this->model->setFilterRegularExpression(QString::fromStdString(""));

}

void gui::addStar() {
    std::string name,ras,decs;
    std::string constelaltaion=this->aust.getConstellation();
    name=ui->nameLineEdit->text().toStdString();
    ras=ui->raLine->text().toStdString();
    decs=ui->decLine->text().toStdString();
    int ra=stoi(ras);
    double dec=stod(decs);
    this->service.addStar(name,constelaltaion,ra,dec);
    this->stars->updateData();
}

void gui::populateFilteredList() {
  //  ui->filteredList->clear();
    ui->listWidget->clear();
    std::string name=ui->starName->text().toStdString();
    std::vector<Star> result=this->service.getStarName(name);
 //   ui->filteredList->addItem(QString::fromStdString("aa"));
    for(const auto& s:result)
        ui->listWidget->addItem(QString::fromStdString(s.getName()));
}

void gui::drawConst() {
    QModelIndexList indexes=ui->tableView->selectionModel()->selectedRows();
    if(indexes.empty())
    {
        QMessageBox::critical(this,"Error","No star selected");
        return;
    }
    auto index=indexes.first();
    int row=index.row();
    std::string constelation=this->service.getStars()[row].getConstellation();


    std::vector<Star> all=this->service.getStarCOnstelation(constelation);
    std::string name=this->service.getStars()[row].getName();
    Drawing *d=new Drawing(name,all);
    d->show();




}

void gui::filterConstellations() {
    if(ui->checkBox->isChecked())
        this->model->setFilter(this->aust.getConstellation());
    else
        this->model->setFilter("");

}
