//
// Created by qian on 2020/6/11.
//

#include "OrderManagerMainView.h"

OrderManagerMainView::OrderManagerMainView(QWidget *parent) : QMainWindow(parent) {
    this->setWindowTitle("订单管理");
    addOrderButton->move(10, 20);
    addOrderButton->setFixedSize(100, 50);

    idLineEdit->setPlaceholderText("订单编号");
    idLineEdit->move(150, 20);
    idLineEdit->setFixedSize(120, 50);

    companyNameLineEdit->setPlaceholderText("公司名称");
    companyNameLineEdit->move(300, 20);
    companyNameLineEdit->setFixedSize(120, 50);

    productNameLineEdit->setPlaceholderText("商品名称");
    productNameLineEdit->move(450, 20);
    productNameLineEdit->setFixedSize(120, 50);

    searchOrderButton->move(600, 20);
    searchOrderButton->setFixedSize(100, 50);
    //订单搜索订单按钮
    connect(searchOrderButton, &QPushButton::clicked, this, &OrderManagerMainView::searchOrder);
    //监听添加订单按钮
    connect(addOrderButton, &QPushButton::clicked, this, &OrderManagerMainView::showAddOrderView);

    showOrderListView->move(0, 100);
    this->setFixedSize(710, 800);
    showOrderListView->setFixedSize(710, 700);

    searchOrder();
}

OrderManagerMainView::~OrderManagerMainView() {
    delete showOrderListView;
    delete addOrderButton;
    delete searchOrderButton;
    delete idLineEdit;
    delete companyNameLineEdit;
    delete productNameLineEdit;
}

void OrderManagerMainView::showAddOrderView() {
    AddOrderFormDialog addOrderForm;
    addOrderForm.show();
    addOrderForm.exec();
    searchOrder();
}

void OrderManagerMainView::searchOrder() {
    std::string orderId = idLineEdit->text().toStdString();
    std::string companyName = companyNameLineEdit->text().toStdString();
    std::string productName = productNameLineEdit->text().toStdString();

    List <Order> orderList = orderManager->searchOrder(orderId, companyName, productName);
    showOrderListView->setOrder(orderList);
}
