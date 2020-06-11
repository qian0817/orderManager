//
// Created by qian on 2020/6/11.
//

#include "ShowOrderTable.h"
#include "OrderManagerMainView.h"

ShowOrderTable::~ShowOrderTable() {
    delete model;
}

ShowOrderTable::ShowOrderTable(QWidget *parent) : QTableView(parent) {

    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);

    model->setHorizontalHeaderItem(0, new QStandardItem("订单编号"));
    model->setHorizontalHeaderItem(1, new QStandardItem("商品名称"));
    model->setHorizontalHeaderItem(2, new QStandardItem("公司名称"));
    model->setHorizontalHeaderItem(3, new QStandardItem("商品价格"));
    model->setHorizontalHeaderItem(4, new QStandardItem("商品数量"));
    model->setHorizontalHeaderItem(5, new QStandardItem("商品总价"));

//    connect(this, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(slotRowDoubleClicked(const QModelIndex &)));
}

void ShowOrderTable::setOrder(List <Order> &orderList) {
    int i = 0;
    for (const Order &order:orderList) {
        model->setItem(i, 0, new QStandardItem(std::to_string(order.getId()).c_str()));
        model->setItem(i, 1, new QStandardItem(order.getProductName().c_str()));
        model->setItem(i, 2, new QStandardItem(order.getCompanyName().c_str()));
        //价格保留小数点2位
        std::string price = std::to_string(order.getPrice());
        price = price.substr(0, price.size() - 4);
        model->setItem(i, 3, new QStandardItem(price.c_str()));
        model->setItem(i, 4, new QStandardItem(std::to_string(order.getNum()).c_str()));
        //保留小数点2位
        std::string totalPrice = std::to_string(order.totalPrice());
        totalPrice = totalPrice.substr(0, totalPrice.size() - 4);
        model->setItem(i, 5, new QStandardItem(totalPrice.c_str()));
        i++;
    }
    model->setRowCount(i);
    this->setModel(model);
}
void ShowOrderTable::mouseDoubleClickEvent(QMouseEvent *event) {
    int row = currentIndex().row();
    int orderId = model->item(row)->text().toInt();
    if (orderId == 0) {
        return;
    }
    DeleteAndUpdateDialog deleteAndUpdateView(orderId);
    deleteAndUpdateView.show();
    deleteAndUpdateView.exec();
    //刷新主界面的内容
    ((OrderManagerMainView *) parent())->searchOrder();
}
