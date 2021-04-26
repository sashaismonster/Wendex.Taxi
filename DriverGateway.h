#ifndef HOMEWORK_4_DRIVERGATEWAY_H
#define HOMEWORK_4_DRIVERGATEWAY_H

#include <string>
#include "../exceptions.h"
#include "../DB.h"

class DriverGateway {
public:
    void signup(const string& name, const string& login, const string& password);

    Driver login(const string& login, const string& password);

    void on_line(Driver& driver);

    void get_order(Driver& driver, Order& order);
    void arrived(Order& order);

    Order current_order(const Driver& driver);
    vector<Order> available_orders();
    vector<Order> order_history(const Driver& driver);
};


#endif //HOMEWORK_4_DRIVERGATEWAY_H