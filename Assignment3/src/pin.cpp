#include "../include/pin.h"

// Constructor
Pin::Pin(const std::string& id) : Component(id) {
}

// set signal value
void Pin::setSignal(bool val) {
    value = val;
}

// get signal value
bool Pin::getSignal() const {
    return value;
}