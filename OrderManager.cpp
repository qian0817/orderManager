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
        orderList.add(order);
    }
    stream.close();
}

OrderManager::~OrderManager() {
    std::ofstream stream(filename);
    int i = 0;
    int size = orderList.size();
    //向文件中保存信息
    for (Order &order :orderList) {
        stream << order;
        if (i != size - 1) {
            stream << std::endl;
        }
        i++;
    }
    stream.close();
}

void OrderManager::mainMenu() {
    while (true) {
        welcomeMessage();
        std::string n = readLine();
        clear();
        if (!isUnsignedInt(n)) {
            std::cout << "输入的不是数字" << std::endl;
            continue;
        }
        switch (std::stoi(n)) {
            case 1: {
                std::cout << "请依次输入订单号,公司名称,商品名称,单价,数量。空格进行分隔" << std::endl;
                Order order;
                std::cin >> order;
                addOrder(order);
            }
                break;
            case 2: {
                std::cout << "请输入订单编号:";
                std::string orderId = readLine();
                if (!isUnsignedInt(orderId)) {
                    std::cout << "订单号必须为正整数" << std::endl;
                    break;
                }
                updateOrder(std::stoi(orderId));
            }
                break;
            case 3: {
                std::cout << "请输入订单编号:";
                std::string orderId = readLine();
                if (!isUnsignedInt(orderId)) {
                    std::cout << "订单号必须为正整数" << std::endl;
                    break;
                }
                deleteOrder(std::stoi(orderId));
            }
                break;
            case 4: {
                std::cout << "1.按订单号查询" << std::endl;
                std::cout << "2.按产品名称查询" << std::endl;
                std::cout << "3.按公司名称查询" << std::endl;
                n = readLine();
                if (!isUnsignedInt(n)) {
                    std::cout << "输入的不是数字" << std::endl;
                    break;
                }
                clear();
                switch (std::stoi(n)) {
                    case 1: {
                        std::cout << "请输入订单编号:";
                        std::string orderId = readLine();
                        if (!isUnsignedInt(orderId)) {
                            std::cout << "输入的不是数字" << std::endl;
                            break;
                        }
                        searchOrderByOrderId(std::stoi(orderId));
                    }
                        break;
                    case 2: {
                        std::cout << "请输入产品名称:";
                        std::string productName;
                        std::cin >> productName;
                        searchOrderByProductName(productName);
                    }
                        break;
                    case 3: {
                        std::cout << "请输入公司名称:";
                        std::string name;
                        std::cin >> name;
                        searchOrderByCompanyName(name);
                        break;
                    }
                    default:
                        std::cout << "输入了错误的编号" << std::endl;
                }
            }
                break;
            case 5:
                return;
            default:
                std::cout << "输入了错误的编号" << std::endl;
        }
    }
}

void OrderManager::welcomeMessage() {
    std::cout << std::endl << std::endl;
    std::cout << "订单信息管理系统" << std::endl;
    std::cout << "1.添加订单" << std::endl;
    std::cout << "2.修改订单" << std::endl;
    std::cout << "3.删除订单" << std::endl;
    std::cout << "4.查询订单" << std::endl;
    std::cout << "5.退出系统" << std::endl;
}

void OrderManager::updateOrder(int orderId) {
    for (Order &order : orderList) {
        if (order.getId() == orderId) {
            std::cout << "1.修改公司名称" << std::endl;
            std::cout << "2.修改商品名称" << std::endl;
            std::cout << "3.修改数量" << std::endl;
            std::cout << "4.修改价格" << std::endl;
            std::string n = readLine();
            clear();
            if (!isUnsignedInt(n)) {
                std::cout << "输入的不是数字" << std::endl;
                return;
            }
            switch (std::stoi(n)) {
                case 1: {
                    std::cout << "修改后的公司名称:" << std::endl;
                    std::string companyName;
                    std::cin >> companyName;
                    order.setCompanyName(companyName);
                    return;
                }
                case 2: {
                    std::cout << "修改后的商品名称:" << std::endl;
                    std::string productName;
                    std::cin >> productName;
                    order.setProductName(productName);
                    return;
                }
                case 3: {
                    std::cout << "修改后的数量:" << std::endl;
                    std::string num = readLine();
                    if (!isUnsignedInt(num)) {
                        std::cout << "数量必须为正整数" << std::endl;
                        return;
                    }
                    order.setNum(std::stoi(num));
                    return;
                }
                case 4: {
                    std::cout << "修改后的价格:" << std::endl;
                    std::string price = readLine();
                    if (!isDouble(price)) {
                        std::cout << "错误的价格输入" << std::endl;
                        return;
                    }
                    order.setPrice(std::stod(price));
                    return;
                }
                default:
                    std::cout << "输入了错误的编号";
                    return;
            }
        }
    }
}

void OrderManager::addOrder(const Order &order) {
    for (Order &o : orderList) {
        if (o.getId() == order.getId()) {
            std::cout << "该订单号已经存在" << std::endl;
            return;
        }
    }
    orderList.add(order);
}

void OrderManager::deleteOrder(int orderId) {
    for (auto iter = orderList.begin(); iter != orderList.end(); ++iter) {
        if (iter->getId() == orderId) {
            iter.remove();
            return;
        }
    }
    std::cout << "没有该订单" << std::endl;
}

void OrderManager::searchOrderByOrderId(int orderId) {
    std::cout << "编号\t公司名称\t产品名称\t价格\t数量" << std::endl;
    for (Order &order : orderList) {
        if (order.getId() == orderId) {
            std::cout << order << std::endl;
            return;
        }
    }
    std::cout << "没有该订单" << std::endl;
}

void OrderManager::searchOrderByCompanyName(const std::string &company_name) {
    double total = 0;
    std::cout << "编号\t公司名称\t产品名称\t价格\t数量" << std::endl;
    for (Order &order : orderList) {
        if (order.getCompanyName() == company_name) {
            std::cout << order << std::endl;
            total += order.totalPrice();
        }
    }
    std::cout << "总金额为:" << total << std::endl;
}

void OrderManager::searchOrderByProductName(const std::string &product_name) {
    std::cout << "编号\t公司名称\t产品名称\t价格\t数量" << std::endl;
    bool hasProduct = false;
    for (Order &order : orderList) {
        if (order.getProductName() == product_name) {
            std::cout << order << std::endl;
            hasProduct = true;
        }
    }
    if (!hasProduct) {
        std::cout << "没有符合条件的订单" << std::endl;
    }
}

void OrderManager::clear() {
#ifdef _WIN32
    system("cls");
#else
//    system("clear");
#endif
}

