#include "StrBlob.h"

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