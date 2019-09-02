//The use of dynamic-exception-specifiers is deprecated (since C++11).
// removed since C++17

#include <exception>
#include <cstdio>

#include "all_function.h"

class BadExceptionA{};
class BadExceptionB{};

void MyThandler() {
    cout << "terminated called" << endl;
    exit(0);
}

void MyUHandler1() {
    throw BadExceptionA();
}

void MyUHandler2() {
    throw;
}

void BadExceptiont() {
    throw BadExceptionB();
}

void BadExceptionf() throw (BadExceptionA) {
    BadExceptiont();
}

void BadExceptiong() throw (BadExceptionA, bad_exception) {
    BadExceptiont();
}

int BadException() {
    set_terminate(MyThandler);
    set_unexpected(MyUHandler1);
    try {
        BadExceptionf();
    }
    catch (BadExceptionA&) {
        cout << "caught an A from f"<<endl;
    }
    set_unexpected(MyUHandler2);
    try
    {
        BadExceptiong();
    }
    catch (bad_exception&)
    {
        cout << "caught a bad_exception from g()"<<endl;
    }
    try {
        BadExceptionf();
    }
    catch (...) {
        cout << "this will never print" << endl;
    }
    return 0;
}