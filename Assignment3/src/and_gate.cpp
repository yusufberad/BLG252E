#include "../include/and_gate.h"

// Constructor: Initializes the AND gate with a unique identifier.
ANDGate::ANDGate(const std::string& id) : Gate(id, 2) {}

// evaluate: Implementation for the abstract evaluate method from Component.
void ANDGate::evaluate() {
    // Get input pin values
    bool input1 = getInputPin(0)->getSignal();
    bool input2 = getInputPin(1)->getSignal();
    
    // Perform AND operation
    bool result = input1 && input2;
    
    // Set output pin value
    getOutputPin()->setSignal(result);
}