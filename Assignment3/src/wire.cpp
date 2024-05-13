#include "../include/wire.h"

// Constructor: Initializes a wire with a source and a destination pin.
Wire::Wire(Pin* src, Pin* dest) : source(src), destination(dest) {
}

// propagateSignal: Transfers the signal from the source pin to the destination pin.
void Wire::propagateSignal() {
    destination->set(source->get());
}