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
        StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
        StrBlob(std::initializer_list<std::string> il):
        data(std::make_shared<std::vector<std::string>>(il)) { }
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const std::string& t) { data->push_back(t); }
        void pop_back() {
            check(0, "pop_back on empty StrBlob");
            data->pop_back();
        }
        std::string& front() {
            check(0, "front on empty StrBlob"); 
            return data->front();
        }
        std::string& back() {
            check(0, "back on empty StrBlob");
            return data->back();
        }
        const std::string& front() const {
            check(0, "front on empty StrBlob");
            return data->front();
        }
        const  std::string& back() const {
            check(0, "back on empty StrBlob");
            return data->back();
        }
    private:
        std::shared_ptr<std::vector<std::string>> data;

        void check(size_type i, const std::string& msg) const {
            if (i >= data->size())
                throw std::out_of_range(msg);
        }
    };
    void testStrBlob(StrBlob& sb) {
        try {
            sb.push_back("abc");
            sb.push_back("def");
            std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
            sb.pop_back();
            std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
            sb.pop_back();
            std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
        }
        catch (std::out_of_range err) {
            std::cerr << err.what() << " out of range" << std::endl;
        }
        catch (std::exception err) {
            std::cerr << err.what() << std::endl;
        }
    }

    void testStrBlob(const StrBlob& sb) {
        try {
            std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
        }
        catch (std::out_of_range err) {
            std::cerr << err.what() << " out of range" << std::endl;
        }
        catch (std::exception err) {
            std::cerr << err.what() << std::endl;
        }
    }
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

    //12.1
    {
        StrBlob b1;
        {
            StrBlob b2 = { "a", "an", "the" };
            b1 = b2;
            b2.push_back("about");
        }

    }

    //12.2
    {
        StrBlob sb1;
        StrBlob sb2{ "Hello", "World" };
        StrBlob sb3 = { "Bye", "World" };
        const StrBlob csb1;
        const StrBlob csb2{ "This", "Blob" };

        testStrBlob(sb1);
        std::cout << std::endl;
        testStrBlob(sb2);
        std::cout << std::endl;
        testStrBlob(sb3);
        std::cout << std::endl;
        testStrBlob(csb1);
        std::cout << std::endl;
        testStrBlob(csb2);
        std::cout << std::endl;
        testStrBlob({ "ppp", "qqq" });
        std::cout << std::endl;
        //testStrBlob({"mm", 1});  // Error
    }



}