//
// Created by qian on 2020/6/10.
//

#include "AddOrderFormDialog.h"

AddOrderFormDialog::AddOrderFormDialog(QDialog *parent) : QDialog(parent) {
    this->setWindowTitle("添加商品");
    this->setModal(true);
    this->setFixedSize(400, 400);

    idLabel->move(30, 50);
    idLabel->setFixedWidth(100);
    idLineEdit->move(150, 50);
    idLineEdit->setFixedWidth(200);
    idLineEdit->setPlaceholderText("请输入订单编号");

    companyNameLabel->move(30, 100);
    companyNameLabel->setFixedWidth(100);
    companyNameLineEdit->move(150, 100);
    companyNameLineEdit->setFixedWidth(200);
    companyNameLineEdit->setPlaceholderText("请输入公司名称");

    productNameLabel->move(30, 150);
    productNameLabel->setFixedWidth(100);
    productNameLineEdit->move(150, 150);
    productNameLineEdit->setFixedWidth(200);
    productNameLineEdit->setPlaceholderText("请输入商品名称");

    priceLabel->move(30, 200);
    priceLabel->setFixedWidth(100);
    priceLineEdit->move(150, 200);
    priceLineEdit->setFixedWidth(200);
    priceLineEdit->setPlaceholderText("请输入商品价格");

    numLabel->move(30, 250);
    numLabel->setFixedWidth(100);
    numLineEdit->move(150, 250);
    numLineEdit->setFixedWidth(200);
    numLineEdit->setPlaceholderText("请输入商品数量");

    button->move(150, 300);
    button->setFixedWidth(100);

    connect(button, &QPushButton::clicked, this, &AddOrderFormDialog::addOrder);
}
void AddOrderFormDialog::addOrder() {
    int id = idLineEdit->text().toInt();
    std::string companyName = companyNameLineEdit->text().toStdString();
    std::string productName = productNameLineEdit->text().toStdString();
    double price = priceLineEdit->text().toDouble();
    int num = numLineEdit->text().toInt();

    Order order(id, companyName, productName, price, num);
    std::string message = orderManager->addOrder(order);
    if (message.empty()) {
        QMessageBox::information(this, "", "添加成功", QMessageBox::Yes);
        // 清空输入框内容
        idLineEdit->clear();
        companyNameLineEdit->clear();
        productNameLineEdit->clear();
        priceLineEdit->clear();
        numLineEdit->clear();
    } else {
        QMessageBox::warning(this, "", QString(message.c_str()), QMessageBox::Yes);
    }

}
AddOrderFormDialog::~AddOrderFormDialog() {
    delete idLineEdit;
    delete companyNameLineEdit;
    delete productNameLineEdit;
    delete priceLineEdit;
    delete numLineEdit;

    delete button;

    delete idLabel;
    delete companyNameLabel;
    delete productNameLabel;
    delete priceLabel;
    delete numLabel;
}