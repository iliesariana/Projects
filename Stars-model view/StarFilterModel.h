//
// Created by vostro on 6/25/2024.
//

#ifndef STARS_STARFILTERMODEL_H
#define STARS_STARFILTERMODEL_H

#pragma once
#include<vector>
#include <string>
#include <QSortFilterProxyModel>
class StarFilterModel:public QSortFilterProxyModel {
private:
    std::string filter;
public:
    StarFilterModel(){};
    ~StarFilterModel()=default;
    void setFilter(const std::string filter)
    {
        this->filter=filter;
        invalidateFilter();
    }
protected:
    //bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;


};


#endif //STARS_STARFILTERMODEL_H
