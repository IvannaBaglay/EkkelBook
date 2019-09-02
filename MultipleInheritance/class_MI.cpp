#include <string>
#include <vector>

#include "all_function.h"


namespace MIClass {
    struct Base1 {
        void print(int) const
        {
            std::cout << "Base1::print(int)\n";
        }
    protected:
        int ival;
        double dval;
        char cval;
    private:
        int* id;
    };

    struct Base2 {
        void print(double) const
        {
            std::cout << "Base2::print(double)\n";
        }
    protected:
        double fval;
    private:
        double dval;
    };

    struct Derived : public Base1 {
        void print(std::string) const
        {
            std::cout << "Derived::print(std::string)\n";
        }
    protected:
        std::string sval;
        double dval;
    };

    struct MI : public Derived, public Base2 {
        void print(std::vector<double>) const
        {
            std::cout << "MI::print(vector<double>)\n";
        }
        void print(int) const
        {
            std::cout << "MI::print(int)\n";
        }
        void foo(double cval)
        {
            // local dval, MI::print, MI::ival, MI::dvec, Derived::sval, Base2::fval
            fval, cval, dvec, ival, sval;
            //dval; // is ambiguous
            int dval;
            dval;

            // exercise questions occur here
        }
    protected:
        //int dval;
        int* ival;
        std::vector<double> dvec;
    };

}
