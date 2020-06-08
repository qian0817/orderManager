//
// Created by qianlei on 2020/4/28.
//

#ifndef ORDERMANAGER_ORDER_HPP
#define ORDERMANAGER_ORDER_HPP

#include <iostream>
#include <string>
#include <sstream>

class Order {
private:
    unsigned int m_id;
    std::string m_company_name;
    std::string m_product_name;
    double m_price;
    unsigned int m_num;
public:
    explicit Order(unsigned int id = 0, std::string companyName = "", std::string productName = "",
                   double price = 0, unsigned int num = 0);
    double totalPrice() const;
    friend std::ostream &operator<<(std::ostream &stream, const Order &o);
    friend std::istream &operator>>(std::istream &stream, Order &o);
    unsigned int getId() const;
    void setId(unsigned int id);
    const std::string &getCompanyName() const;
    void setCompanyName(const std::string &companyName);
    const std::string &getProductName() const;
    void setProductName(const std::string &productName);
    double getPrice() const;
    void setPrice(double price);
    unsigned int getNum() const;
    void setNum(unsigned int num);
};
#endif //ORDERMANAGER_ORDER_HPP
