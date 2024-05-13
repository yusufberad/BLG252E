#include "../include/circuit.h"


// Destructor: Cleans up all components and wires in the circuit to prevent memory leaks.
Circuit::~Circuit() {
    // Delete all components
    for (Component* comp : components) {
        delete comp;
    }

    // Delete all wires
    for (Wire* wire : wires) {
        delete wire;
    }
}

// addComponent: Adds a new component to the circuit.
void Circuit::addComponent(Component* comp) {
    components.push_back(comp);
}

// addWire: Adds a new wire to the circuit that connects components.
void Circuit::addWire(Wire* wire) {
    wires.push_back(wire);
}

// simulate: Initiates the simulation of the circuit.
void Circuit::simulate() {
    // Propagate signals through all wires
    for (Wire* wire : wires) {
        wire->propagateSignal();
    }

    // Evaluate all components
    for (Component* comp : components) {
        comp->evaluate();
    }
}