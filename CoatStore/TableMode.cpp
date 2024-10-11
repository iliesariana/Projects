//
// Created by vostro on 5/20/2024.
//

#include "TableMode.h"
#include "QFont"
#include "QBrush"
#include <QPixmap>
#include <QPainter>
TableMode::TableMode(Repository *repository, QObject *parent) :repository{repository}, QAbstractTableModel{parent}{
     this->coatsCount=this->repository->getSize();

}
TableMode::~TableMode() {

}
int TableMode::rowCount(const QModelIndex &parent) const {
    int coatsNumber = this->repository->getSize();
    return coatsNumber;
//    return coatsNumber + 1;
}
int TableMode::columnCount(const QModelIndex &parent) const {
    return 5;
}
QVariant TableMode::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();

//    vector<Coat> coats = this->repository.GetDynArr();

    /// Allow adding in the table
    /// this is to show an empty row at the end of the table - to allow adding new coats
//    if(row == coats.size())
//    {
//        return QVariant();
//    }

    ///Get the coat from the current row
//    Coat c = coats[row];

    if( role == Qt::DisplayRole || role == Qt::EditRole)
    {
        std::vector<Coat> coats = this->repository->getCoats();
        Coat c = coats[row];
        switch(column)
        {
            case 0:
                return QString::fromStdString(std::to_string(c.getSize()));

            case 1:
                return QString::fromStdString(c.getColour());

            case 2:
                return QString::fromStdString(std::to_string(c.getPrice()));

            case 3:
                return QString::fromStdString(std::to_string(c.getQuantity()));

            case 4:
                return QString::fromStdString(c.getPhoto());

            default:
                break;

        }
    }

    if(role == Qt::FontRole){

        QFont font("Times", 15, 10, true);
        font.setItalic(false);
        return font;
    }
//    if(role == Qt::BackgroundRole)
//    {
//        if(row % 2 == 1){
//            return QBrush{ QColor{0, 250, 154} };
//        }
//    }

    return QVariant{};

};
QVariant TableMode::headerData(int section, Qt::Orientation orientation, int role) const {

    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section){
                case 0:
                    return QString{"Size"};

                case 1:
                    return QString{"Color"};

                case 2:
                    return QString{"Price"};

                case 3:
                    return QString{"Quantity"};

                case 4:
                    return QString{"Photograph"};

                default:
                    break;
            }
        }
    }

    if(role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}
Qt::ItemFlags TableMode::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void TableMode::updateInternalData() {
//    this->coatsCount = this->repository.GetDynArr().size();
    endResetModel();

}
