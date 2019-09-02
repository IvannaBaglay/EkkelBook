#include <exception>

#include "all_function.h"

class Up {};
class Fit {};
void g();

void f(int i) throw (Up, Fit) {
    switch (i)
    {
    case 1: throw Up();
    case 2: throw Fit();
    default:
        break;
    }
    g();
}

//void g() {} //V1
void  g() { //V2
    throw Up();
}
/*void  g() { //V3
    throw 47; //ERROR
}*/

void MyUnexpected() {
    cout << "unexpected exception throw" << endl;
    exit(0);
}



int Unexpected() {
    set_unexpected(MyUnexpected);

    for (int i=1 ; i<= 3; i++)
        try {
        f(i);
    }
    catch (Up) {
        cout << "Up caught" << endl;
    }
    catch (Fit) {
        cout << "Fit caught" << endl;
    }
    cout<<"END"<<endl;
    return 0;
}

