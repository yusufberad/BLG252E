#include "../include/or_gate.h"

// Constructor: Initializes the OR gate with a unique identifier.
ORGate::ORGate(const std::string& id) : Gate(id, 2) {
}

// evaluate: If any of the input pins are set to true, the output pin is set to true.
void ORGate::evaluate() {
    bool result = false;
    for (Pin* pin : inputs) {
        if (pin->get()) {
            result = true;
            break;
        }
    }
    output->set(result);
}