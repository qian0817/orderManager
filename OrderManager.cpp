//
// Created by qianlei on 2020/4/28.
//

#include "OrderManager.hpp"


OrderManager::OrderManager() {
    std::ifstream stream(filename);
    //从文件中读取信息
    while (stream && !stream.eof()) {
        Order order;
        stream >> order;
        if (order.getId() == 0) {
            return;
        }
        orderList.add(order);
    }
    stream.close();
}

OrderManager::~OrderManager() {
    std::ofstream stream(filename);
    int i = 0;
    int size = orderList.size();
    if (size != 0) {
        //向文件中保存信息
        for (Order &order :orderList) {
            stream << order;
            if (i != size - 1) {
                stream << std::endl;
            }
            i++;
        }
    }
    stream.close();
}

std::string OrderManager::updateOrder(Order &newOrder) {
    std::string check = checkOrder(newOrder);
    if (!check.empty()) {
        return check;
    }
    for (Order &order : orderList) {
        if (order.getId() == newOrder.getId()) {
            order = newOrder;
            return "";
        }
    }
    return "该商品不存在";
}

std::string OrderManager::addOrder(const Order &order) {
    std::string check = checkOrder(order);
    if (!check.empty()) {
        return check;
    }
    for (Order &o : orderList) {
        if (o.getId() == order.getId()) {
            return "该订单已存在";
        }
    }
    orderList.add(order);
    return "";
}

void OrderManager::deleteOrder(int orderId) {
    for (auto iter = orderList.begin(); iter != orderList.end(); ++iter) {
        if (iter->getId() == orderId) {
            iter.remove();
            return;
        }
    }
}

std::string OrderManager::checkOrder(const Order &order) {
    if (order.getId() <= 0) {
        return "错误的编号";
    }
    if (order.getCompanyName().empty()) {
        return "错误的公司名称";
    }
    if (order.getProductName().empty()) {
        return "错误的商品名称";
    }
    if (order.getNum() <= 0) {
        return "错误的商品数量";
    }
    if (order.getPrice() <= 0) {
        return "错误的商品价格";
    }
    return "";
}

List<Order> OrderManager::searchOrder(const std::string &orderId,
                                      const std::string &companyName, const std::string &productName) {
    List<Order> ret;
    try {
        std::regex idRegex(orderId.empty() ? ".*" : orderId);
        std::regex productNameRegex(productName.empty() ? ".*" : productName);
        std::regex companyNameRegex(companyName.empty() ? ".*" : companyName);
        for (const Order &order:orderList) {
            const std::string id = std::to_string(order.getId());
            const std::string &product = order.getProductName();
            const std::string &company = order.getCompanyName();
            if (std::regex_match(id, idRegex)
                && std::regex_match(product, productNameRegex)
                && std::regex_match(company, companyNameRegex)) {
                ret.add(order);
            }
        }
    } catch (std::regex_error &e) {
    }
    return ret;
}

Order OrderManager::searchOrder(int orderId) {
    for (Order &order:orderList) {
        if (order.getId() == orderId) {
            return order;
        }
    }
    return Order();
}

OrderManager *OrderManager::getInstance() {
    static std::shared_ptr <OrderManager> instance(new OrderManager());
    return instance.get();
}

