//
// Created by qian on 2020/6/11.
//

#include <QtWidgets/QMessageBox>
#include "DeleteAndUpdateDialog.h"

DeleteAndUpdateDialog::DeleteAndUpdateDialog(int orderId, QDialog *parent) : QDialog(parent) {
    Order order = orderManager->searchOrder(orderId);
    if (order.getId() == 0) {
        this->close();
        return;
    }
    idLineEdit->setFocusPolicy(Qt::NoFocus);

    this->setWindowTitle("修改商品");
    this->setFixedSize(400, 400);
    this->setModal(true);

    idLabel->move(30, 50);
    idLabel->setFixedWidth(100);
    idLineEdit->move(150, 50);
    idLineEdit->setFixedWidth(200);
    idLineEdit->setPlaceholderText("请输入订单编号");
    idLineEdit->setText(std::to_string(order.getId()).c_str());

    companyNameLabel->move(30, 100);
    companyNameLabel->setFixedWidth(100);
    companyNameLineEdit->move(150, 100);
    companyNameLineEdit->setFixedWidth(200);
    companyNameLineEdit->setPlaceholderText("请输入公司名称");
    companyNameLineEdit->setText(order.getCompanyName().c_str());

    productNameLabel->move(30, 150);
    productNameLabel->setFixedWidth(100);
    productNameLineEdit->move(150, 150);
    productNameLineEdit->setFixedWidth(200);
    productNameLineEdit->setPlaceholderText("请输入商品名称");
    productNameLineEdit->setText(order.getProductName().c_str());

    priceLabel->move(30, 200);
    priceLabel->setFixedWidth(100);
    priceLineEdit->move(150, 200);
    priceLineEdit->setFixedWidth(200);
    priceLineEdit->setPlaceholderText("请输入商品价格");
    priceLineEdit->setText(std::to_string(order.getPrice()).c_str());

    numLabel->move(30, 250);
    numLabel->setFixedWidth(100);
    numLineEdit->move(150, 250);
    numLineEdit->setFixedWidth(200);
    numLineEdit->setPlaceholderText("请输入商品数量");
    numLineEdit->setText(std::to_string(order.getNum()).c_str());

    deleteButton->move(100, 300);
    deleteButton->setFixedWidth(80);
    updateButton->move(220, 300);
    updateButton->setFixedWidth(80);

    connect(deleteButton, &QPushButton::clicked, this, &DeleteAndUpdateDialog::deleteOrder);
    connect(updateButton, &QPushButton::clicked, this, &DeleteAndUpdateDialog::updateOrder);
}

DeleteAndUpdateDialog::~DeleteAndUpdateDialog() {
    delete deleteButton;
    delete updateButton;

    delete idLineEdit;
    delete companyNameLineEdit;
    delete productNameLineEdit;
    delete priceLineEdit;
    delete numLineEdit;

    delete priceLabel;
    delete companyNameLabel;
    delete productNameLabel;
    delete idLabel;
    delete numLabel;
}
void DeleteAndUpdateDialog::deleteOrder() {
    int orderId = idLineEdit->text().toInt();
    orderManager->deleteOrder(orderId);
    QMessageBox::information(this, "", "删除成功", QMessageBox::Yes);
    this->close();
}
void DeleteAndUpdateDialog::updateOrder() {
    int id = idLineEdit->text().toInt();
    std::string companyName = companyNameLineEdit->text().toStdString();
    std::string productName = productNameLineEdit->text().toStdString();
    double price = priceLineEdit->text().toDouble();
    int num = numLineEdit->text().toInt();

    Order order(id, companyName, productName, price, num);
    std::string message = orderManager->updateOrder(order);
    if (message.empty()) {
        QMessageBox::information(this, "", "修改成功", QMessageBox::Yes);
    } else {
        QMessageBox::warning(this, "", message.c_str(), QMessageBox::Yes);
    }
}


