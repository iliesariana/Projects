//
// Created by vostro on 5/20/2024.
//

#ifndef UNTITLED14_TABLEMODE_H
#define UNTITLED14_TABLEMODE_H
#pragma once
#include <QAbstractTableModel>
#include "Repo.h"
#include<QStyledItemDelegate>


class TableMode :public QAbstractTableModel,QStyledItemDelegate {
private:
    Repository *repository;
    int coatsCount;
public:
    TableMode(Repository* repository, QObject* parent = NULL);
    ~TableMode();
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    // number of columns
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    // Value at a given position
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // add header data
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // will be called when a cell is edited
//    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

    // used to set certain properties of a cell
    Qt::ItemFlags flags(const QModelIndex & index) const override;

//    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
//    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const override;

    void updateInternalData();

};


#endif //UNTITLED14_TABLEMODE_H
