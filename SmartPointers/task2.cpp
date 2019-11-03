/*
    Polymorphism and virtual functions
    Conversions
    STL containers
    STL iterators
*/

#include <iostream>
#include <vector>

namespace {
    class A {
    public:
        A(int n = 0) : m_n(n) {

        }

        virtual int f() const { return m_n; }
        virtual ~A() {  };

    protected:
        int m_n;
    };

    class B : public A {
    public:
        B(int n = 0) : A(n) {

        }

        int f() const override { return m_n + 1; }
    };
    class C : public A {
    public:
        C(int n = 0) : A(n) {

        }

        int f() const override { return m_n + 1; }
    };
}

int task2() {
    const A a(1);
    const B b(3);
    const A* x[2] = { &a, &b };
    typedef std::vector<A> V;
    V y({ a, b });
    V::const_iterator i = y.begin();

    std::cout << x[0]->f() << x[1]->f() << i->f() << (i + 1)->f() << std::endl;

    typedef std::vector<const A*> V2;
    V2 y1({ &a, &b });
    V2::const_iterator i2 = y1.begin();
    std::cout <<  (*i2)->f() << (*(i2 + 1))->f() << std::endl;
    
    std::vector<A*> y2;
    y2.push_back(new B(1));
    y2.push_back(new C(2));
    std::vector<A*>::iterator i3 = y2.begin();
    std::cout << (*i3)->f() << (*(i3 + 1))->f() << std::endl;

    return 0;
}