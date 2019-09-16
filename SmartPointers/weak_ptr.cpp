#include "all_function.h"

std::weak_ptr<int> gw;

void Observe() {
    std::cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()) {
        std::cout << *spt << std::endl;
    }
    else {
        std::cout << "gw is expired" << std::endl;
    }
}

void UseWeakPointer() {

    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
        Observe();
    }

    Observe();

}