//
// Created by qian on 2020/6/10.
//

#ifndef ORDERMANAGER_ADDORDERFORMDIALOG_H
#define ORDERMANAGER_ADDORDERFORMDIALOG_H

#include <QApplication>
#include <QMessageBox>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include "OrderManager.hpp"

class AddOrderFormDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddOrderFormDialog(QDialog *parent = nullptr);
    void addOrder();
    ~AddOrderFormDialog() override;
private:
    OrderManager *orderManager = OrderManager::getInstance();

    QLineEdit *idLineEdit = new QLineEdit(this);
    QLineEdit *companyNameLineEdit = new QLineEdit(this);
    QLineEdit *productNameLineEdit = new QLineEdit(this);
    QLineEdit *priceLineEdit = new QLineEdit(this);
    QLineEdit *numLineEdit = new QLineEdit(this);

    QLabel *idLabel = new QLabel("订单编号", this);
    QLabel *companyNameLabel = new QLabel("公司名称", this);
    QLabel *productNameLabel = new QLabel("商品名称", this);
    QLabel *priceLabel = new QLabel("商品价格", this);
    QLabel *numLabel = new QLabel("商品数量", this);

    QPushButton *button = new QPushButton("添加商品", this);
};


#endif //ORDERMANAGER_ADDORDERFORMDIALOG_H
