//
// Created by qianlei on 2020/4/28.
//

#ifndef ORDERMANAGER_ORDERMANAGER_HPP
#define ORDERMANAGER_ORDERMANAGER_HPP

#include "Order.hpp"
#include "List.hpp"
#include "utils.h"
#include <fstream>

class OrderManager {
private:
    List<Order> orderList;
    static constexpr const char *filename = "Order.txt";
public:
    /**
    * 主菜单
    */
    void mainMenu();
    OrderManager();
    ~OrderManager();
private:
    /**
     * 输入各信息并计算订单金额
     */
    void addOrder(Order &order);
    /**
     * 删除不需要的订单
     * @param orderId 订单号
     */
    void deleteOrder(int orderId);
    /**
     * 修改订单信息
     * @param orderId 订单号
     */
    void updateOrder(int orderId);
    /**
     * 按条件查询订单
     * @param orderId 订单号
     * @return 该订单号的订单信息
     */
    void searchOrderByOrderId(int orderId);
    /**
     * 输入某个公司名称，统计并输出所有订单总额
     * @param company_name 公司名称
     */
    void searchOrderByCompanyName(std::string &company_name);
    /**
     * 根据产品名称获取所有的订单
     * @param product_name 产品名称
     */
    void searchOrderByProductName(std::string &product_name);
    /**
     * 清屏
     */
    static void clear();

    static void welcomeMessage();
};

#endif //ORDERMANAGER_ORDERMANAGER_HPP
