//
// Created by qianlei on 2020/4/28.
//

#include "order_manager.hpp"

order_manager::order_manager() {
    std::ifstream stream(filename);
    //从文件中读取信息
    while (stream && !stream.eof()) {
        order o;
        stream >> o;
        m_list.add(o);
    }
    stream.close();
}

order_manager::~order_manager() {
    std::ofstream stream(filename);
    order o;
    int i = 0;
    int size = m_list.size();
    //向文件中保存信息
    for (auto &iter :m_list) {
        stream << iter;
        if (i != size - 1) {
            stream << std::endl;
        }
        i++;
    }
    stream.close();
}

void order_manager::main_menu() {
    while (true) {
        welcome_message();
        int n;
        std::cin >> n;
        switch (n) {
            case 1: {
                std::cout << "请依次输入订单号,公司名称,商品名称,单价,数量。空格进行分隔" << std::endl;
                order o;
                std::cin >> o;
                add_order(o);
            }
                break;
            case 2: {
                int orderId;
                clear();
                std::cout << "请输入订单编号:";
                std::cin >> orderId;
                update_order(orderId);
            }
                break;
            case 3: {
                int orderId;
                std::cout << "请输入订单编号:";
                std::cin >> orderId;
                delete_order(orderId);
            }
                break;
            case 4: {
                clear();
                std::cout << "1.按订单号查询" << std::endl;
                std::cout << "2.按产品名称查询" << std::endl;
                std::cout << "3.按公司名称查询" << std::endl;
                int m;
                std::cin >> m;
                switch (m) {
                    case 1: {
                        int orderId;
                        std::cout << "请输入订单编号:";
                        std::cin >> orderId;
                        search_order_by_order_id(orderId);
                    }
                        break;
                    case 2: {
                        std::string product_name;
                        std::cout << "请输入产品名称:";
                        std::cin >> product_name;
                        search_order_by_product_name(product_name);
                    }
                        break;
                    case 3: {
                        std::string name;
                        std::cout << "请输入公司名称:";
                        std::cin >> name;
                        search_order_by_company_name(name);
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

void order_manager::welcome_message() {
    clear();
    std::cout << std::endl << std::endl;
    std::cout << "订单信息管理系统" << std::endl;
    std::cout << "1.添加订单" << std::endl;
    std::cout << "2.修改订单" << std::endl;
    std::cout << "3.删除订单" << std::endl;
    std::cout << "4.查询订单" << std::endl;
    std::cout << "5.退出系统" << std::endl;
}

void order_manager::update_order(int orderId) {
    for (auto &iter : m_list) {
        if (iter.getId() == orderId) {
            clear();
            std::cout << "1.修改公司名称" << std::endl;
            std::cout << "2.修改商品名称" << std::endl;
            std::cout << "3.修改数量" << std::endl;
            std::cout << "4.修改价格" << std::endl;
            int m;
            std::cin >> m;
            switch (m) {
                case 1: {
                    std::cout << "修改后的公司名称:" << std::endl;
                    std::string companyName;
                    std::cin >> companyName;
                    iter.setCompanyName(companyName);
                }
                    break;
                case 2: {
                    std::cout << "修改后的商品名称:" << std::endl;
                    std::string productName;
                    std::cin >> productName;
                    iter.setProductName(productName);
                }
                    break;
                case 3: {
                    std::cout << "修改后的数量:" << std::endl;
                    int num;
                    std::cin >> num;
                    iter.setNum(num);
                }
                    break;
                case 4: {
                    std::cout << "修改后的价格:" << std::endl;
                    double price;
                    std::cin >> price;
                    iter.setPrice(price);
                }
                    break;
                default:
                    std::cout << "输入了错误的编号";
            }
        }
    }
}

void order_manager::add_order(order &o) {
    for (auto &iter : m_list) {
        if (iter.getId() == o.getId()) {
            std::cout << "该订单号已经存在" << std::endl;
            return;
        }
    }
    m_list.add(o);
}

void order_manager::delete_order(int orderId) {
    for (auto iter = m_list.begin(); iter != m_list.end(); ++iter) {
        if (iter->getId() == orderId) {
            iter.remove();
            return;
        }
    }
    std::cout << "没有该订单" << std::endl;
}

void order_manager::search_order_by_order_id(int orderId) {
    std::cout << "编号\t公司名称\t产品名称\t价格\t数量" << std::endl;
    for (auto &order : m_list) {
        if (order.getId() == orderId) {
            std::cout << order << std::endl;
            return;
        }
    }
    std::cout << "没有该订单" << std::endl;
}

void order_manager::search_order_by_company_name(std::string &company_name) {
    double total = 0;
    std::cout << "编号\t公司名称\t产品名称\t价格\t数量" << std::endl;
    for (auto &order : m_list) {
        if (order.getCompanyName() == company_name) {
            std::cout << order << std::endl;
            total += order.total_price();
        }
    }
    std::cout << "总金额为:" << total << std::endl;
}

void order_manager::search_order_by_product_name(std::string &product_name) {
    std::cout << "编号\t公司名称\t产品名称\t价格\t数量" << std::endl;
    bool hasProduct = false;
    for (auto &order : m_list) {
        if (order.getProductName() == product_name) {
            std::cout << order << std::endl;
            hasProduct = true;
        }
    }
    if (!hasProduct) {
        std::cout << "没有符合条件的订单" << std::endl;
    }
}

void order_manager::clear() {
#ifdef _WIN32
    system("cls");
#else
//    system("clear");
#endif
}

