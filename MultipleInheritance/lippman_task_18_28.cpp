#include "all_function.h"

namespace {

    struct Base {
        void bar(int);
    protected:
        int ival;
    };

    struct Derived1 : virtual public Base {
        void bar(char); // +
        void foo(char);
    protected:
        char cval;
    };

    struct Derived2 : virtual public Base {
        void foo(int); // -
    protected:
        int ival; // +
        char cval; // -
    };

    class VMI : public Derived1, public Derived2 {

    };
}

/*Reguire no qualification:
ival; Derived2::ival overrides Base::ival, and thus, takes  precedence over it.
bar; Derived1::bar overrides Base:bar, and thus, takes precedence over it.

Require qualification:
cval; ambiguous--appears in both Derived1 and Derived2
foo; ambiguous--appears in both Derived1 and Derived2*/