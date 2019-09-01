#include "all_function.h"

namespace NamespaceBaseStruct {
    
    struct Base1 {
        Base1() = default;
        Base1(const std::string&);
        Base1(std::shared_ptr<int>);
    };
    struct Base2 {
        Base2() = default;
        Base2(const std::string&);
        Base2(int);
    };

    struct D1: public Base1, public Base2 {
        using Base1::Base1;
        //using Base2::Base2; //error: both struct have same constructors Base(const std::string&) 'NamespaceBaseStruct::Base2::Base2': constructor has already been inherited from 'NamespaceBaseStruct::Base1'

    };
    struct D2 :public Base1, public Base2
    {
        using Base1::Base1;
        using Base2::Base2;
        // we must definition own constructor with (const string&)
        D2(const std::string& s) : Base1(s), Base2(s) {

        }
        D2() = default;
    };
}

void CreateD() {
    NamespaceBaseStruct::D1 d1;
    NamespaceBaseStruct::D2 d2;

}