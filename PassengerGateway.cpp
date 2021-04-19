#include <iostream>
#include "PassengerGateway.h"

void PassengerGateway::signup(const string &name, const string &login, const string &password, const string &paymentMethod) {
    int users_with_same_login = DB::storage.count<Passenger>(where(c(&Passenger::login) == login));
    if (users_with_same_login != 0) {
        throw LoginBusy();
    }

    Passenger pax{-1, name, 0, login, password, paymentMethod};
    DB::storage.insert(pax);
}

Passenger PassengerGateway::login(const string &login, const string &password) {
    auto vec = DB::storage.get_all<Passenger>(where(c(&Passenger::login) == login and c(&Passenger::password) == password));
    if (vec.empty()) {
        throw LoginOrPasswordIncorrect();
    }

    cout << "Welcome " << vec[0].name << ". Your rating is " << vec[0].rating << "." << endl;

    return vec[0];
}

int PassengerGateway::calculate_sum(coord from, coord to, int carType) {
    return carType * sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
}

Order PassengerGateway::order_taxi(const Passenger& passenger, const string &point, const string &destination, int carType) {
    auto available_drivers = DB::storage.get_all<Driver>(where(c(&Driver::status) == 1));
    if (available_drivers.empty()) {
        throw NoDrivers();
    }

    coord from;
    from.x = rand() % 1000;
    from.y = rand() % 1000;

    coord to;
    to.x = rand() % 1000;
    to.y = rand() % 1000;

    int sum = calculate_sum(from, to, carType);

    Order ord{-1, point, from, destination, to, passenger.id, -1, sum, 0};
    ord.id = DB::storage.insert(ord);

    return ord;
}

vector<Order> PassengerGateway::order_history(const Passenger &passenger) {
    return DB::storage.get_all<Order>(where(c(&Order::passenger) == passenger.id));
}

Order PassengerGateway::current_order(const Passenger& passenger) {
    vector<Order> vec = DB::storage.get_all<Order>(where(c(&Order::passenger) == passenger.id));
    if (vec.empty()) throw NoOrders();
    return vec[0];
}
