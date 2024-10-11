//
// Created by vostro on 5/31/2024.
//

#ifndef STARS_STARSMODEL_H
#define STARS_STARSMODEL_H

#pragma once
#include "Repository.h"
#include <QAbstractTableModel>
class starsModel :public QAbstractTableModel{
private:
    Repository &repository;
public:
    starsModel(Repository &repo):repository{repo}{}
    ~starsModel(){}
    [[nodiscard]] int rowCount(const QModelIndex &parent=QModelIndex()) const override;
    int columnCount(const QModelIndex &parent=QModelIndex()) const override;
    QVariant data(const QModelIndex &index,int role=Qt::DisplayRole) const override;
    QVariant headerData(int section,Qt::Orientation orientation,int role=Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    void updateData();
    bool setData(const QModelIndex &index,const QVariant &value,int role=Qt::EditRole) override;
};


#endif //STARS_STARSMODEL_H
