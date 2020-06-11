//
// Created by qian on 2020/6/11.
//

#ifndef ORDERMANAGER_ORDERMANAGERMAINVIEW_H
#define ORDERMANAGER_ORDERMANAGERMAINVIEW_H

#include <QMainWindow>
#include <QPushButton>
#include "./AddOrderFormDialog.h"
#include "./ShowOrderTable.h"

class OrderManagerMainView : public QMainWindow {
    Q_OBJECT
public:
    explicit OrderManagerMainView(QWidget *parent = nullptr);
    ~OrderManagerMainView() override;
    void showAddOrderView();
    void searchOrder();
private:
    OrderManager *orderManager = OrderManager::getInstance();

    ShowOrderTable *showOrderListView = new ShowOrderTable(this);
    QPushButton *addOrderButton = new QPushButton("添加订单", this);
    QPushButton *searchOrderButton = new QPushButton("搜索订单", this);

    QLineEdit *idLineEdit = new QLineEdit(this);
    QLineEdit *companyNameLineEdit = new QLineEdit(this);
    QLineEdit *productNameLineEdit = new QLineEdit(this);
};


#endif //ORDERMANAGER_ORDERMANAGERMAINVIEW_H
