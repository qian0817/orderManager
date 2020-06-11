//
// Created by qian on 2020/6/11.
//

#ifndef ORDERMANAGER_SHOWORDERTABLE_H
#define ORDERMANAGER_SHOWORDERTABLE_H

#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include "List.hpp"
#include "Order.hpp"
#include "DeleteAndUpdateDialog.h"

class ShowOrderTable : public QTableView {
    Q_OBJECT
public:
    explicit ShowOrderTable(QWidget *parent = nullptr);
    ~ShowOrderTable() override;
    void setOrder(List <Order> &orderList);
private:
    QStandardItemModel *model = new QStandardItemModel(0, 6, this);
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};


#endif //ORDERMANAGER_SHOWORDERTABLE_H
