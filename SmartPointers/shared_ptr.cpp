#include <vector>
#include <string>

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

    class StrBlob {
    public:
        typedef std::vector<std::string>::size_type size_type;
        StrBlob() {

        }
        StrBlob(std::initializer_list<std::string> il) {

        }
        size_type size() const { return data->size; }
        bool empty() const { return data->empty; }
        void push_back(const std::string& t) { data->push_back(t); }
        void pop_back();
        std::string& front();
        std::string& back();
    private:
        std::shared_ptr<std::vector<std::string>> data;

        void check(size_type i, const std::string& msg) const;
    };
}


void UseSharedPtr() {
    auto p = std::make_shared<int>(42);
    auto q(p);
    auto r = std::make_shared<int>(12);
    auto r2(r);
    auto foo = std::make_shared<Foo>(1);
    auto foo2(foo);
    r = q;  
    foo = UseFactoryWithReturn(5);

}