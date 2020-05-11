//
// Created by qianlei on 2020/4/28.
//

#ifndef ORDERMANAGER_ORDER_HPP
#define ORDERMANAGER_ORDER_HPP

#include <iostream>
#include <string>

class order {
private:
    unsigned int m_id;
    std::string m_company_name;
    std::string m_product_name;
    double m_price;
    unsigned int m_num;
public:
    order(unsigned int id, std::string &companyName, std::string &productName, double price, unsigned int num);
    order();
    double total_price() const;
    friend std::ostream &operator<<(std::ostream &stream, const order &o);
    friend std::istream &operator>>(std::istream &stream, order &o);
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
