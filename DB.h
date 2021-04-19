#ifndef HOMEWORK_4_DB_H
#define HOMEWORK_4_DB_H

#include <sqlite_orm/sqlite_orm.h>

using namespace std;
using namespace sqlite_orm;

struct coord{
    int x;
    int y;
};

class Driver{
public:
    int id;
    string name;
    int rating;
    int status; // 0 - offline, 1 - free, 2 - on order;
    string login;
    string password;
};

class Car{
public:
    int id;
    int driver;
    string coordinates;
    int carType;  // 1 - Economy, 2 - Comfort, 3 - ComfortPlus, 4 - Business
};

class Passenger{
public:
    int id;
    string name;
    int rating;
    string login;
    string password;
    string paymentMethod;
};

class Order{
public:
    int id;
    string point;
    coord from;
    string destination;
    coord to;
    int passenger;
    int driver;
    int sum;
    int status; // 0 - car not assigned; 1 - car is en route; 2 - waiting; -1 - car not found
};

inline auto init_storage() {
    return make_storage("db.sqlite",
                        make_table("passengers",
                                   make_column("id", &Passenger::id, autoincrement(), primary_key()),
                                   make_column("name", &Passenger::name),
                                   make_column("rating", &Passenger::rating),
                                   make_column("login", &Passenger::login),
                                   make_column("password", &Passenger::password),
                                   make_column("paymentMethod", &Passenger::paymentMethod)),
                        make_table("drivers",
                                   make_column("id", &Driver::id, autoincrement(), primary_key()),
                                   make_column("name", &Driver::name),
                                   make_column("rating", &Driver::rating),
                                   make_column("status", &Driver::status),
                                   make_column("login", &Driver::login),
                                   make_column("password", &Driver::password)),
                        make_table("orders",
                                   make_column("id", &Order::id, autoincrement(), primary_key()),
                                   make_column("point", &Order::point),
                                   make_column("coord-from", &Order::from),
                                   make_column("destination", &Order::destination),
                                   make_column("coord-to", &Order::to),
                                   make_column("passenger", &Order::passenger),
                                   make_column("driver", &Order::driver),
                                   make_column("sum", &Order::sum),
                                   make_column("status", &Order::status)),
                        make_table("cars",
                                   make_column("id", &Car::id, autoincrement(), primary_key()),
                                   make_column("driver", &Car::driver),
                                   make_column("coordinates", &Car::coordinates),
                                   make_column("cartype", &Car::carType)));
}
using Storage = decltype(init_storage());

class DB {
public:
    static Storage storage;
};


#endif //HOMEWORK_4_DB_H
