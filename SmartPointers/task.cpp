/*
    Pointers, references and values
    Constructors
    Function call
*/

#include <iostream>

namespace {
    class A {
    public:
        A(int n = 0)
            : m_n(n) {
            std::cout << "d";
        }
        A(const A& a)
            : m_n(a.m_n) {
            std::cout << "c";
        }
    private:
        int m_n;
    };

    void f(const A& a1, const A& a2 = A()) {

    }
}

int task1() {
    /*std::unique_ptr<int> uptr(new int(1020));
    int *i = new int(10);
    double *d = new double(10.0);

    //i = d;
    //d = i;

    UseUniqurPtr();
    */

    A a(2), b;
    const A c(a), & d = c, e = b;
    b = d;
    A* p = new A(c), * q = &a;
    static_cast<void>(q);
    delete p;
    f(3);
    std::cout << std::endl;

    return 0;
}