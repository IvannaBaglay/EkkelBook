#ifndef PIMPL_IDIOM_FRIDGE_H_
#define PIMPL_IDIOM_FRIDGE_H_ 

#include <iostream>
#include <memory>

#include "Engine.h"
#include "FridgeImpl.h"

class Fridge {
public:
    Fridge();
    ~Fridge();

    void CoolDown();
private:

    class FridgeImpl {
    public:
        void CoolDown() {

        }
    private:
        Engine engine_;
    };
    std::unique_ptr<FridgeImpl> impl_;
};

#endif //PIMPL_IDIOM_FRIDGE_H_
