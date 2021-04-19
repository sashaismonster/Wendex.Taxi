#include <iostream>
#include "Gateways/PassengerGateway.h"
#include "Gateways/DriverGateway.h"
#include "DB.h"

using namespace std;
using namespace sqlite_orm;

Storage DB::storage = init_storage();

int main() {
    // DB init
    DB::storage.sync_schema();

    // Gateways init
    PassengerGateway pg;
    DriverGateway dg;

    pg.signup("Aleksandr", "agolovin", "qwerty", "Cash");
    dg.signup("Emil", "emil01", "123456");

    // Actions
    Passenger p = pg.login("agolovin", "qwerty");
    Driver d = dg.login("emil01", "123456");

    Order order = pg.order_taxi(p, "kalachevskaya", "rogonina", 0);
    dg.on_line(d);

    auto hist = pg.order_history(p);

    std::cout << order.id << std::endl;
    return 0;
}
