//
// Created by vostro on 6/25/2024.
//

#include "StarFilterModel.h"

//bool StarFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
//    QModelIndex index=this->sourceModel()->index(source_row,1,source_parent);
//    QString c=this->data(index).toString();
//    if(this->filter=="")
//        return true;
//    if(QString::fromStdString(this->filter)==c)
//        return true;
//    return false;
//
//}
bool StarFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    QModelIndex index=this->sourceModel()->index(source_row,1,source_parent);
    if(this->filter=="")
        return true;
    QString data=this->data(index).toString();
    if(data==QString::fromStdString(this->filter))
        return true;
    return false;
}
