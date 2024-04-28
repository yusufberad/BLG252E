#include "../include/worker.hpp"
#include <iostream>

using namespace std;

// Constructor
Worker::Worker(string name, float cost_per_day, float base_return_per_day)
    : Unit(name, cost_per_day, base_return_per_day)
{
    m_experience = 0;
}


// Getter functions

float Worker::getReturnPerDay()
{   
    float revenue = Unit::getReturnPerDay() + m_experience * 2 + m_num_head_workers * 3;
    m_experience++;
    return revenue;
}

int Worker::getExperience() const
{
    return m_experience;
}

// Static functions
void Worker::increaseHeadWorkerCount()
{
    m_num_head_workers++;
}
