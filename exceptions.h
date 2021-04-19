#ifndef HOMEWORK_4_EXCEPTIONS_H
#define HOMEWORK_4_EXCEPTIONS_H

#include <string>
#include <exception>

using namespace std;

class LoginBusy: public exception
{
    virtual const char* what() const throw()
    {
        return "The login is already exist, type in another";
    }
};

class LoginOrPasswordIncorrect: public exception
{
    virtual const char* what() const throw()
    {
        return "The login or password is incorrect";
    }
};

class NoDrivers: public exception
{
    virtual const char* what() const throw()
    {
        return "No any available drivers around";
    }
};

class DriverIsOfflineOrBusy: public exception
{
    virtual const char* what() const throw()
    {
        return "Driver is offline or busy";
    }
};

class NoOrders: public exception
{
    virtual const char* what() const throw()
    {
        return "No orders";
    }
};

#endif //HOMEWORK_4_EXCEPTIONS_H
