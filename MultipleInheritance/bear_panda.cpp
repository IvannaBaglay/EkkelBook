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
            std::cout << "ZooAnimal" << std::endl;
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
            std::cout << "Endangered" << std::endl;
        }
    private:
        std::string name_;
    };

    class Bear : public ZooAnimal {
    public:
        Bear() {
            std::cout << "Bear" << std::endl;
        }
        Bear(std::string name) {
            name_ = name;
            std::cout << "Bear(name)" << std::endl;
        }
        ~Bear() {
            std::cout << "Bear" << std::endl;
        }
    private:
        std::string name_;
    };

    class Panda : public Bear, public Endangered {
    public:
        Panda() {
            std::cout << "Panda" << std::endl;
        }
        Panda(std::string name) {
            name_ = name;
            std::cout << "Panda(name)" << std::endl;
        }
        ~Panda() {
            std::cout << "~Panda" << std::endl;
        }
    private:
        std::string name_;
    };

}

void CreatePanda() {
    NamespacePanda::Panda panda;
}