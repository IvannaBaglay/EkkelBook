namespace Q {
    namespace V { // V is a member of Q, and is fully defined within Q
  // namespace Q::V { // C++17 alternative to the above two lines
        class C { void m(); }; // C is a member of V and is fully defined within V
                               // C::m is only declared
        void f(); // f is a member of V, but is only declared here
    }
    void V::f() // definition of V's member f outside of V
                // f's enclosing namespaces are still the global namespace, Q, and Q::V
    {
        extern void h(); // This declares ::Q::V::h
    }
    void V::C::m() // definition of V::C::m outside of the namespace (and the class body)
                   // enclosing namespaces are the global namespace, Q, and Q::V
    {
    }
}

namespace blip {
    int i = 16, j = 15, k = 23;

}

namespace A {
    class C{
        friend void f2();
        friend void f(const C&);
        friend void f3(int i);
    };
}

int j = 0;
void manip(){
    using namespace blip;
    ++i;
    //++j; error using ::j or blip::j
    ++::j;
    ++blip::j;
    int k = 97;
    ++k;
    ++blip::k;
    A::C cobj;
    f(cobj);
    //f(3);
    //f2(); error f2 don't visible
}

