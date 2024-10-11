//
// Created by vostro on 5/31/2024.
//

#include "starsModel.h"

#include <QString>
int starsModel::rowCount(const QModelIndex &parent) const {
    return this->repository.getStars().size();
}

int starsModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant starsModel::data(const QModelIndex &index, int role) const {
    int row=index.row();
    int col=index.column();
    Star star=this->repository.getStars()[row];
    if(role==Qt::DisplayRole || role==Qt::EditRole)
        switch(col)
        {
            case 0:
                return QString::fromStdString(star.getName());
            case 1:
                return QString::fromStdString(star.getConstellation());
            case 2:
                return QString::fromStdString(std::to_string(star.getRa()));
            case 3:
                return QString::fromStdString(std::to_string(star.getDec()));
        }
    return QVariant();
}

QVariant starsModel::headerData(int section, Qt::Orientation orientation, int role) const {
   if(orientation==Qt::Horizontal && role==Qt::DisplayRole)
       switch(section)
       {
           case 0:
               return "NAME";
           case 1:
               return "Const";
           case 2:
               return "Ra";
           case 3:
               return "DEC";


       }
   return QVariant();
}

void starsModel::updateData() {

    beginResetModel();
    endResetModel();
    emit this->dataChanged(index(0,0),index(rowCount()-1, columnCount()-1));
}


bool starsModel::setData(const QModelIndex &index, const QVariant &value, int role) {

    int row = index.row();
    int col = index.column();
    Star& star = this->repository.getStars()[row];

    switch (col) {
        case 2:
            star.setRa(value.toInt());
            break;
        case 3:

            break;
        default:
            return false;
    }

    emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});
    return true;


}

Qt::ItemFlags starsModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

