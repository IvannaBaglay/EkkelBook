#include <vector>
#include <string>
#include <fstream>

#include "StrBlob.h"
#include "StrBlobPtr.h"

template<typename T>
using UniquePointerSet = std::set<std::unique_ptr<T>, ComparePointer>;


namespace {

    struct ComparePointer
    {
        template<typename T>
        bool operator() (std::unique_ptr<T> const& up1, std::unique_ptr<T> const& up2) {
            return *up1 < *up2;
        }
    
    };

    class Base {

    };
    class Derived : public Base {

    };

}

void UseUniqurPtr() {



    std::unique_ptr<int> p(new int(5));

    //std::unique_ptr<int> q(p);

    std::unique_ptr<int> q;
    //q = p;
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;

    // (a) Illegal. `ix` is not a pointer.
    //IntP p0(ix);
    // (b) Illegal. The memory pointed by `p1` is not dynamically allocated in
    // heap, thus cannot be freed by a smart pointer.
    //IntP p1(pi);
    // (c) OK. Note that if `p2` is destroyed, `pi2` should not be use to visit
    // that memory any more.
    IntP p2(pi2);
    // (d) Illegal. Same reason as (b).
    //IntP p3(&ix);
    // (e) OK.
    IntP p4(new int(2048));
    // (f) Can be compiled, but will result error. Two unique pointers point to
    // the same memory, so that the memory will be freed twice when these
    // pointers are destroyed.
    //IntP p5(p2.get());

    //12.20
    {
        std::cout << "Input the file name: ";
        std::string filename;
        std::cin >> filename;
        std::ifstream in(filename);
        if (!in.is_open()) {
            std::cerr << "Cannot open file: " << filename << std::endl;
            //return -1;
        }
        StrBlob texts;
        for (std::string line; std::getline(in, line); texts.push_back(line)) {}
        StrBlobPtr p = texts.begin();
        for (StrBlob::size_type pos = 0; pos != texts.size(); ++pos, p.inc())
            std::cout << pos + 1 << ":\t" << p.deref() << std::endl;
        // The following loop cannot be compiled, because we don't define the `!=`
        // operator for `StrBlobPtr`
        //for (StrBlobPtr p = texts.begin(); p != texts.end(); p.inc())
    }

    UniquePointerSet<Base> source;
    source.insert(std::make_unique<Derived>());

    UniquePointerSet<Base> destination;

    destination.merge(source);
}