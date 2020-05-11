//
// Created by qianlei on 2020/4/28.
//

#ifndef ORDERMANAGER_ORDER_MANAGER_HPP
#define ORDERMANAGER_ORDER_MANAGER_HPP

#include "order.hpp"
#include "list.hpp"
#include <fstream>

class order_manager {
private:
    list<order> m_list;
    static constexpr const char *filename = "order.txt";
public:
    /**
    * 主菜单
    */
    void main_menu();
    order_manager();
    ~order_manager();
private:
    /**
     * 输入各信息并计算订单金额
     */
    void add_order(order &o);
    /**
     * 删除不需要的订单
     * @param orderId 订单号
     */
    void delete_order(int orderId);
    /**
     * 修改订单信息
     * @param orderId 订单号
     */
    void update_order(int orderId);
    /**
     * 按条件查询订单
     * @param orderId 订单号
     * @return 该订单号的订单信息
     */
    void search_order_by_order_id(int orderId);
    /**
     * 输入某个公司名称，统计并输出所有订单总额
     * @param company_name 公司名称
     */
    void search_order_by_company_name(std::string &company_name);
    /**
     * 根据产品名称获取所有的订单
     * @param product_name 产品名称
     */
    void search_order_by_product_name(std::string &product_name);
    /**
     * 清屏
     */
    static void clear();
    static void welcome_message();
};

#endif //ORDERMANAGER_ORDER_MANAGER_HPP
