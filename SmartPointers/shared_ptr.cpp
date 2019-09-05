#include "all_function.h"

namespace {

    class Foo {
    public:
        Foo() = default;
        Foo(int a) {
            arg_ = a;
        }
    private:
        int arg_;
    };
    std::shared_ptr<Foo> Factory(int arg) {
        return std::make_shared<Foo>(arg);
    }
    void UseFactory(int arg) {
        std::shared_ptr<Foo> p = Factory(arg);
        // use p
    }// delete p and object
    std::shared_ptr<Foo> UseFactoryWithReturn(int arg) {
        std::shared_ptr<Foo> p = Factory(arg);
        return p; // increment pointer's count 
    }//  don't delete object 
}

void UseSharedPtr() {
    auto p = std::make_shared<int>(42);
    auto q(p);
    auto r = std::make_shared<int>(12);
    auto r2(r);
    auto foo = std::make_shared<Foo>(1);
    auto foo2(foo);
    r = q;  
    foo = UseFactoryWithReturn(1);

}