// DO NOT MODIFY THIS FILE
#ifndef HEADWORKER_HPP
#define HEADWORKER_HPP

#include "worker.hpp"

class HeadWorker: public Worker
{
public:
    HeadWorker(Worker &worker);
    
    float getReturnPerDay();
};

#endif // HEADWORKER_HPP