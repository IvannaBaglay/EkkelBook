#include <vector>

#include "all_function.h"
#include "class_MI.cpp"
#include "class_panda.cpp"



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

    //delete pb;

    NamespacePanda::Endangered *pen = new NamespacePanda::Panda;
    pen->print();
    pen->highlight();
    //pe->toes(); // error: class Endangered has njo member toes()
    //pe->cuddle(); // error: class Endangered has njo member cuddle()

    //delete pen; // TODO:


    //panda.get_max_weight(); // error: get_max_weight is ambiguous
    panda.ZooAnimal::get_max_weight();
    panda.Endangered::get_max_weight();

    //panda.max_weight_with_paramets("a");// error: max_weight_with_paramets is ambiguous
    //panda.max_weight_with_paramets(1,2);// error: max_weight_with_paramets is ambiguous
    panda.ZooAnimal::max_weight_with_paramets(1, 2);
    panda.Endangered::max_weight_with_paramets("a");
    panda.Bear::max_weight_with_paramets(1.2, 1);
    
    //panda.max_weight_with_paramets_in_private(1, 1); //error: max_weight_with_paramets_in_private is ambiguous
    panda.Endangered::max_weight_with_paramets_in_private(1,2);
    //panda.ZooAnimal::max_weight_with_paramets_in_private(1, 2); // error: is inaccessible
    //NamespacePanda::print(panda_with_name); //error: more than one instance of overloaded function "NamespacePanda::print" matches the argument list : MultipleInheritance	

    
    //panda.f3(2.0) // right if Panda don't have own member f3
    //panda.f3("a"); // right if Panda have own member f3, but we can't use f3 from ZooAnimal

    NamespacePanda::ZooAnimal* pz = new NamespacePanda::Panda;

    //pz->f3("s"); //error ZooAnimal don't have f3(string) 

    MIClass::MI mi;
    mi.print(42);

    panda.FunctionInZoo();

}