#include <vector>

#include "all_function.h"

namespace NamespacePanda {
    class ZooAnimal {
    public:
        ZooAnimal() {
            std::cout << "ZooAnimal" << std::endl;
        }
        ZooAnimal(std::string name) {
            name_ = name;
            std::cout << "ZooAnimal(name)" << std::endl;
        }
        ~ZooAnimal() {
            std::cout << "~ZooAnimal" << std::endl;
        }
        const std::string get_name() const {
            return name_;
        }
        void print() {
            std::cout << "ZooAnimal.print()" << std::endl;
        }
        void get_max_weight() {
            std::cout << "ZooAnimal.max_weight()" << std::endl;
        }
        void max_weight_with_paramets(double d, int i) {
            std::cout << "ZooAnimal.max_weight_with_paramets()" << std::endl;
        }
        virtual void f3(int i) {
            std::cout << "ZooAnimal.f3()" << std::endl;
        }
        void FunctionInZoo() {
            std::cout << "ZooAnimal.FunctionInZoo()" << std::endl;
        }
    private:
        void max_weight_with_paramets_in_private(double d, int i) {
            std::cout << "ZooAnimal.max_weight_with_paramets_in_private()" << std::endl;
        }
        std::string name_;

    };
    class Endangered {
    public:
        Endangered() {
            std::cout << "Endangered" << std::endl;
        }
        Endangered(std::string name) {
            name_ = name;
            std::cout << "Endangered(name)" << std::endl;
        }
        ~Endangered() {
            std::cout << "~Endangered" << std::endl;
        }
        void print() {
            std::cout << "Endangered.print()" << std::endl;
        }
        virtual void highlight() {
            std::cout << "Endangered.highlight()" << std::endl;
        }
        void get_max_weight() {
            std::cout << "Endangered.max_weight()" << std::endl;
        }
        void max_weight_with_paramets(std::string i) {
            std::cout << "Endangered.max_weight_with_paramets()" << std::endl;
        }
        void max_weight_with_paramets_in_private(double d, int i) {
            std::cout << "Endangered.max_weight_with_paramets_in_private()" << std::endl;
        }
    private:

        std::string name_;
    };

    class Bear : virtual public ZooAnimal {
    public:
        Bear() {
            std::cout << "Bear" << std::endl;
        }
        Bear(std::string name) :
            ZooAnimal(name)
        {
            name_ = name;
            std::cout << "Bear(name)" << std::endl;
        }
        ~Bear() {
            std::cout << "~Bear" << std::endl;
        }
        void print() {
            std::cout << "Bear.print()" << std::endl;
        }
        virtual void toes() {
            std::cout << "Bear.toes()" << std::endl;
        }
    private:
        std::string name_;
    };

    class Raccoon : public virtual ZooAnimal {
    public:
        Raccoon() {
            std::cout << "Raccoon" << std::endl;
        }
        Raccoon(std::string name) :
            ZooAnimal(name)
        {
            name_ = name;
            std::cout << "Raccoon(name)" << std::endl;
        }
        ~Raccoon() {
            std::cout << "~Raccoon" << std::endl;
        }
        void print() {
            std::cout << "Raccoon.print()" << std::endl;
        }
        virtual void toes() {
            std::cout << "Raccoon.toes()" << std::endl;
        }
    private:
        std::string name_;
    };

    class Panda : public Bear, public Raccoon, public Endangered {
    public:
        Panda() {
            std::cout << "Panda" << std::endl;
        }
        Panda(std::string name) :
            Endangered(name),
            Bear(name)
        {
            name_ = name;
            std::cout << "Panda(name)" << std::endl;
        }
        ~Panda() {
            std::cout << "~Panda" << std::endl;
        }
        void print() {
            std::cout << "Panda.print()" << std::endl;
        }
        virtual void highlight() {
            std::cout << "Panda.highlight()" << std::endl;
        }
        void toes() override {
            std::cout << "Panda.toes()" << std::endl;
        }
        virtual void cuddle() {
            std::cout << "Panda.cuddle()" << std::endl;
        }
         void get_max_weight() {
             std::cout << "Panda.max_weight()" << std::endl;
         }
         void max_weight_with_paramets(std::string i) {
             std::cout << "Panda.max_weight_with_paramets()" << std::endl;
         }
         void max_weight_with_paramets_in_private(double d, int i) {
             std::cout << "Panda.max_weight_with_paramets_in_private()" << std::endl;
         }
        virtual void f3(std::string i) //override be error 
        {
            std::cout << "Panda.f3()" << std::endl;
        }
    private:
        std::string name_;
    };


}
