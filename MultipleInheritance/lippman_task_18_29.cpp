#include "all_function.h"


namespace NamespaceClassTask {
    class Class {
    public:
        Class() {
            std::cout << "Class"<<std::endl;
        }
        ~Class() {
            std::cout << "~Class"<<std::endl;
        }
    };
    class Base : public Class { 
    public:
        Base() {
            std::cout << "Base" << std::endl;
        }
        ~Base() {
            std::cout << "~Base" << std::endl;
        }
    };
    class D1 : virtual public Base { 
    public:
        D1() {
            std::cout << "D1" << std::endl;
        }
        ~D1() {
            std::cout << "~D1" << std::endl;
        }
    };
    class D2 : virtual public Base { 
    public:
        D2() {
            std::cout << "D2" << std::endl;
        }
        ~D2() {
            std::cout << "~D2" << std::endl;
        }
    };
    class MI : public D1, public D2 { 
    public:
        MI() {
            std::cout << "MI" << std::endl;
        }
        ~MI() {
            std::cout << "~MI" << std::endl;
        }
    };
    class Final : public MI, public Class {
    public:
        Final() {
            std::cout << "Final" << std::endl;
        }
        ~Final() {
            std::cout << "~Final" << std::endl;
        }
    };

}


void CallClass() {
    using namespace NamespaceClassTask;
    Final F;

    Base* pb;
    Class* pc;
    MI* pmi = new MI;
    D2* pd2;

    //pb = new Class;
    pc = new Final;
    //pmi = pb;
    pd2 = pmi;
}