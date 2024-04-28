#include "../include/machine.hpp"
#include <iostream>

using namespace std;

Machine::Machine(std::string name, float price, float cost_per_day, float base_return_per_day, float failure_probability, int repair_time, float repair_cost)
    : Unit(name, cost_per_day, base_return_per_day){
    m_failure_probability = failure_probability;
    m_repair_time = repair_time;
    m_price = price;
    m_repair_cost = repair_cost;
    m_days_until_repair = 0;
}

// get Return Per Day
float Machine::getReturnPerDay(){
    if(m_days_until_repair == 0){
        //failed machine
        if((rand() % 100)/100.000 < (float)m_failure_probability){
            m_days_until_repair = m_repair_time;
            return -m_repair_cost;
        }
        else{
            return Unit::getReturnPerDay();
        }
    }
    else{
        return 0;
    }
}

// get Price
float Machine::getPrice() const{
    return m_price;
}