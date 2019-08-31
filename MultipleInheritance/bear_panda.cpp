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
    private:
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
    private:
        std::string name_;
    };

    class Bear : public ZooAnimal {
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
    private:
        std::string name_;
    };

    class Panda : public Bear, public Endangered {
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
    private:
        std::string name_;
    };

   void print(const Bear&) {

    }
    void print(const Endangered&) {

    }
    void print(const ZooAnimal& zoo_animal) {
        std::cout << zoo_animal.get_name()<<std::endl;
    }
}



void CreatePanda() {
    NamespacePanda::Panda panda;
    NamespacePanda::Panda panda_with_name("name");

    //NamespacePanda::print(panda_with_name); //error: more than one instance of overloaded function "NamespacePanda::print" matches the argument list : MultipleInheritance	
}