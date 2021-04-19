//
// Created by Artem Batalov on 10.04.2021.
//

#ifndef HOMEWORK_4_PASSENGERGATEWAY_H
#define HOMEWORK_4_PASSENGERGATEWAY_H

#include <string>
#include <vector>
#include "../exceptions.h"
#include "../DB.h"

using namespace std;


class PassengerGateway {
public:
    void signup(const string& name, const string& login, const string& password, const string& paymentMethod);

    Passenger login(const string& login, const string& password);

    int calculate_sum(coord from, coord to, int carType);

    Order order_taxi(const Passenger& passenger, const string& from, const string& to, int carType);

    Order current_order(const Passenger& passenger);
    vector<Order> order_history(const Passenger& passenger);
};


#endif //HOMEWORK_4_PASSENGERGATEWAY_H
