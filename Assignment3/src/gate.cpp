#include "../include/gate.h"

// Constructor: Initializes the gate with a unique identifier.
Gate::Gate(const std::string& id, int numbersOfInputs) : Component(id){
    // Create input pins
    for (int i = 0; i < numbersOfInputs; i++) {
        inputs.push_back(new Pin(id + "_in" + std::to_string(i)));
    }
    // Create output pin
    output = new Pin(id + "_out");
}

// Destructor: Cleans up input and output pins.
Gate::~Gate() {
    for (Pin* pin : inputs) {
        delete pin;
    }
    delete output;
}

// getOutputPin: Returns a pointer to the output pin of the gate.
Pin* Gate::getOutputPin() {
    return output;
}

// getInputPin: Returns a pointer to a specific input pin of the gate.
Pin* Gate::getInputPin(int i) {
    return inputs[i];
}