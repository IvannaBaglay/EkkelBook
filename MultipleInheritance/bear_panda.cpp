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
        virtual void print() {
            std::cout << "ZooAnimal.print()" << std::endl;
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
        virtual void print() {
            std::cout << "Endangered.print()" << std::endl;
        }
        virtual void highlight(){
            std::cout << "Endangered.highlight()" << std::endl;
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
        void print() {
            std::cout << "Bear.print()" << std::endl;
        }
        virtual void toes() {
            std::cout << "Bear.toes()" << std::endl;
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
        void print() {
            std::cout << "Panda.print()" << std::endl;
        }
        virtual void highlight() {
            std::cout << "Panda.highlight()" << std::endl;
        }
        virtual void toes() {
            std::cout << "Panda.toes()" << std::endl;
        }
        virtual void cuddle() {
            std::cout << "Panda.cuddle()" << std::endl;
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

    NamespacePanda::ZooAnimal zoo_animal;
    NamespacePanda::Endangered endangered;
    NamespacePanda::Bear bear;

    std::cout << " \n\n\tprint()\n";

    bear.print();
    endangered.print();
    zoo_animal.print();

    std::cout << "\n\n\tfunction()\n";
    
    NamespacePanda::Bear* pb = new NamespacePanda::Panda;

    pb->print();
    pb->toes();
    //pb->cuddle(); // error: class Bear has njo member cuddle()
    //pb->highlight(); // error: class Bear has njo member highlight()

    delete pb;

    NamespacePanda::Endangered *pe = new NamespacePanda::Panda;
    pe->print();
    pe->highlight();
    //pe->toes(); // error: class Endangered has njo member toes()
    //pe->cuddle(); // error: class Endangered has njo member cuddle()

    delete pe;

    //NamespacePanda::print(panda_with_name); //error: more than one instance of overloaded function "NamespacePanda::print" matches the argument list : MultipleInheritance	
}