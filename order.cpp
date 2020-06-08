//
// Created by qianlei on 2020/4/28.
//

#include "order.hpp"

std::ostream &operator<<(std::ostream &stream, const order &o) {
    stream << o.m_id << "\t" << o.m_company_name << "\t"
           << o.m_product_name << "\t" << o.m_price << "\t"
           << o.m_num;
    return stream;
}

std::istream &operator>>(std::istream &stream, order &o) {
    stream >> o.m_id >> o.m_company_name >> o.m_product_name
           >> o.m_price >> o.m_num;
    return stream;
}

order::order(unsigned int id, std::string &companyName, std::string &productName, double price,
             unsigned int num)
        : m_id(id), m_company_name(companyName), m_product_name(productName), m_price(price),
          m_num(num) {}

double order::total_price() const {
    return getPrice() * getNum();
}

order::order() : m_id(0), m_company_name(""), m_product_name(""), m_price(0), m_num(0) {}

unsigned int order::getId() const {
    return m_id;
}

void order::setId(unsigned int id) {
    order::m_id = id;
}

const std::string &order::getCompanyName() const {
    return m_company_name;
}

void order::setCompanyName(const std::string &companyName) {
    m_company_name = companyName;
}

const std::string &order::getProductName() const {
    return m_product_name;
}

void order::setProductName(const std::string &productName) {
    m_product_name = productName;
}

double order::getPrice() const {
    return m_price;
}

void order::setPrice(double price) {
    m_price = price;
}

unsigned int order::getNum() const {
    return m_num;
}

void order::setNum(unsigned int num) {
    m_num = num;
}