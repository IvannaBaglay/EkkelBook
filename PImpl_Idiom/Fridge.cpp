#include "Fridge.h"

Fridge::Fridge() : impl_(new FridgeImpl) {}

Fridge::~Fridge() = default;

void Fridge::CoolDown() {
    impl_->CoolDown();
}

