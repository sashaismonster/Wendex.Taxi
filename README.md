# Home Assignment (Wendex.Taxi)
## Made by Alexander Golovin, BS20-02

REQUIREMENTS
------------
**C++14**   
CLion is the most appropriate IDE, that already includes:
gcc   
cmake  
sqlite3  
[sqlite_orm](https://github.com/fnc12/sqlite_orm) (`README.md` file includes all the necessary instructions for working with databases)

An additional library, used for storing and updating data for Passengers and Drivers, need to be included onto the project.

DESCRIPTION
-----------
Here's simple implementation a backend for the WEndex.Taxi  
Two getaways are implemented in `PassengerGateway` and `DriverGateaway`classes  
  
In `DB.h` you can find the initialisation of database and initial classes `Driver`, `Passenger`, `Car`, `Order`  
TODO: all variables are public, it's the subject of updates om the Homework 5
Behaviour of `Driver` and `Passenger` is written in their gateways, not in class, to be updated too

`Calculator` is a distinct 


