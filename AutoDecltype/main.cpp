/*
https://habr.com/ru/post/206458/ 
*/

#include <iostream>

int foo() { return 0; }
int& foo1() { int a; return a; }
const int foo2(){ return 0; }
const int& foo3(){ return 0; }

int main()
{
    auto ri = foo(); // int
    auto ri1 = foo1(); // int
    auto ri2 = foo2(); // int
    auto ri3 = foo3(); // int

    //auto& ri4 = foo(); // No Error
    auto& ri5 = foo1(); // int&
    //auto& ri6 = foo2(); // No Error
    auto& ri7 = foo3(); // const int&

    auto&& ri8 = foo(); // int&&
    auto&& ri9 = foo1(); // int&
    auto&& ri10 = foo2(); // const int&&
    auto&& ri11 = foo3(); // const int&

    int k = 5;
    //decltype(k) && rk = k; // Error
    decltype(foo()) && ri12 = foo(); // int&&
    decltype(foo1()) && ri13 = foo1(); // int&

    int i = 3;
    decltype(i) ri14; // int
    decltype((i)) ri15 = i; // int&

    int i1 = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i1 << " " << sum << std::endl;  // 100 45

    return 0;
}