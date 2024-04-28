#include "../include/headworker.hpp"

// Constructor
HeadWorker::HeadWorker(Worker &worker)
    : Worker(worker.getName(), worker.getCostPerDay(), worker.getReturnPerDay())
{
    m_experience = worker.getExperience();
}

// Getter function
float HeadWorker::getReturnPerDay()
{   
    int revenue = Unit::getReturnPerDay() + 5 * m_experience;
    m_experience++;
    return revenue;
}