#include "DriverGateway.h"
#include <iostream>

void DriverGateway::signup(const string &name, const string &login, const string &password) {
    int users_with_same_login = DB::storage.count<Driver>(where(c(&Driver::login) == login));
    if (users_with_same_login != 0) {
        throw LoginBusy();
    }

    Driver drv{-1, name, 0, 0, login, password};
    DB::storage.insert(drv);
}

Driver DriverGateway::login(const string &login, const string &password) {
    auto vec = DB::storage.get_all<Driver>(where(c(&Driver::login) == login and c(&Driver::password) == password));
    if (vec.empty()) {
        throw LoginOrPasswordIncorrect();
    }

    cout << "Welcome " << vec[0].name << ". Your rating is " << vec[0].rating << "." << endl;

    return vec[0];
}

void DriverGateway::on_line(Driver &driver) {
    driver.status = 1;
    DB::storage.update(driver);
}

void DriverGateway::get_order(Driver& driver, Order& order) {
    if (driver.status != 1) {
        throw DriverIsOfflineOrBusy();
    }
    if (order.status != 0) {
        throw OrderAlreadyInProgress();
    }

    driver.status = 2;
    DB::storage.update(driver);

    order.status = 1;
    DB::storage.update(order);
}

vector<Order> DriverGateway::available_orders() {
    return DB::storage.get_all<Order>(where(c(&Order::status) == 0));
}

vector<Order> DriverGateway::order_history(const Driver &driver) {
    return DB::storage.get_all<Order>(where(c(&Order::driver) == driver.id));
}

Order DriverGateway::current_order(const Driver &driver) {
    vector<Order> vec = DB::storage.get_all<Order>(where(c(&Order::driver) == driver.id));
    if (vec.empty()) throw NoOrders();
    return vec[0];
}

void DriverGateway::arrived(Order& order) {
    order.status = 2;
    DB::storage.update(order);
}

