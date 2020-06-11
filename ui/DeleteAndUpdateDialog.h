//
// Created by qian on 2020/6/11.
//

#ifndef ORDERMANAGER_DELETEANDUPDATEDIALOG_H
#define ORDERMANAGER_DELETEANDUPDATEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "OrderManager.hpp"

class DeleteAndUpdateDialog : public QDialog {
    Q_OBJECT
public:
    explicit DeleteAndUpdateDialog(int orderId, QDialog *parent = nullptr);
    ~DeleteAndUpdateDialog() override;
    void deleteOrder();
    void updateOrder();
private:
    OrderManager *orderManager = OrderManager::getInstance();

    QPushButton *updateButton = new QPushButton("更新商品", this);
    QPushButton *deleteButton = new QPushButton("删除商品", this);

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
};


#endif //ORDERMANAGER_DELETEANDUPDATEDIALOG_H
