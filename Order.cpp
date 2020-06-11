//
// Created by qianlei on 2020/4/28.
//


#include "Order.hpp"

std::ostream &operator<<(std::ostream &stream, const Order &o) {
    stream << o.m_id << "\t" << o.m_company_name << "\t"
           << o.m_product_name << "\t" << o.m_price << "\t"
           << o.m_num;
    return stream;
}

std::istream &operator>>(std::istream &stream, Order &o) {
    std::string s;
    std::getline(stream, s);
    std::stringstream sstream(s);
    sstream >> o.m_id >> o.m_company_name >> o.m_product_name >> o.m_price >> o.m_num;
    return stream;
}

Order::Order(int id, std::string companyName, std::string productName, double price,
             int num)
        : m_id(id), m_company_name(std::move(companyName)), m_product_name(std::move(productName)), m_price(price),
          m_num(num) {}

double Order::totalPrice() const {
    return getPrice() * getNum();
}

int Order::getId() const {
    return m_id;
}

void Order::setId(int id) {
    Order::m_id = id;
}

const std::string &Order::getCompanyName() const {
    return m_company_name;
}

void Order::setCompanyName(const std::string &companyName) {
    m_company_name = companyName;
}

const std::string &Order::getProductName() const {
    return m_product_name;
}

void Order::setProductName(const std::string &productName) {
    m_product_name = productName;
}

double Order::getPrice() const {
    return m_price;
}

void Order::setPrice(double price) {
    m_price = price;
}

int Order::getNum() const {
    return m_num;
}

void Order::setNum(int num) {
    m_num = num;
}