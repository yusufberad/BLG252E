#include "../include/not_gate.h"

// Constructor: Initializes the NOT gate with a unique identifier.
NOTGate::NOTGate(const std::string& id) : Gate(id, 1) {}

// evaluate: Implementation for the abstract evaluate method from Component.
void NOTGate::evaluate() {
    // Set output pin value
    getOutputPin()->setSignal(!getInputPin(0)->getSignal());
}