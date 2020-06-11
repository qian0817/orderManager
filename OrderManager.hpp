//
// Created by qianlei on 2020/4/28.
//

#ifndef ORDERMANAGER_ORDERMANAGER_HPP
#define ORDERMANAGER_ORDERMANAGER_HPP

#include "Order.hpp"
#include "List.hpp"
#include <fstream>
#include <regex>
#include <memory>

class OrderManager {
private:
    List<Order> orderList;
    static constexpr const char *filename = "order.txt";
    OrderManager();
public:
    static OrderManager *getInstance();
    ~OrderManager();
    /**
     * 输入各信息并计算订单金额
     */
    std::string addOrder(const Order &order);
    /**
     * 删除不需要的订单
     * @param orderId 订单号
     */
    void deleteOrder(int orderId);
    /**
     * 修改订单信息
     * @param orderId 订单号
     */
    std::string updateOrder(Order &newOrder);
    /**
     * 搜索指定编号的订单
     * @param orderId
     * @return
     */
    Order searchOrder(int orderId);
    /**
     * 按条件搜索订单
     * @param orderId
     * @param companyName
     * @param productName
     * @return
     */
    List<Order> searchOrder(const std::string &orderId, const std::string &companyName, const std::string &productName);
private:
    static std::string checkOrder(const Order &order);
};

#endif //ORDERMANAGER_ORDERMANAGER_HPP
