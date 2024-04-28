#include "../include/factory.hpp"
#include <iostream>

using namespace std;

// Constructor
Factory::Factory(float capital)
{
    m_capital = capital;
    m_is_bankrupt = false;
}

// Public functions
void Factory::passOneDay()
{
    if (m_is_bankrupt)
    {
        return;
    }

    float total_cost = 0;
    float total_return = 0;
    int it = 0;
    for (auto &worker : m_workers)
    {   
        
        //Became a head worker
        if (worker.getExperience() >= 10)
        {   
            cout << worker.getName() << " is promoted." << endl;
            m_head_workers.push_back(HeadWorker(worker));
            // delete worker
            cout << m_workers.size() << endl;
            cout << it << endl;
            m_workers.erase(m_workers.begin() + it );
            it++;
            continue;
        }
        
        total_cost += worker.getCostPerDay();
        total_return += worker.getReturnPerDay();
        it++;
    }

    for (auto &head_worker : m_head_workers)
    {   
        total_cost += head_worker.getCostPerDay();
        total_return += head_worker.getReturnPerDay();
    }

    for (auto &machine : m_machines)
    {
        total_cost += machine.getCostPerDay();
        total_return += machine.getReturnPerDay();
    }

    m_capital += total_return - total_cost;

    if (m_capital < 0)
    {
        m_is_bankrupt = true;
    }
    cout << "[C : " << m_capital << ", W : " << getWorkerCount() << ", M : " << getMachineCount() << ", HW :" << getHeadWorkerCount() << "]" << endl;
}

// Add unit
void Factory::addUnit(const Worker &rhs_worker)
{
    m_workers.push_back(rhs_worker);
    cout << rhs_worker.getName() << " is hired." << endl;
}

// Add unit
void Factory::addUnit(const Machine &rhs_machine)
{
    m_machines.push_back(rhs_machine);
    cout << rhs_machine.getName() << " is bought." << endl;
    m_capital -= rhs_machine.getPrice();
}

// Getter functions
bool Factory::isBankrupt() const
{   
    return m_is_bankrupt;
}

float Factory::getCapital() const
{
    return m_capital;
}

int Factory::getWorkerCount() const
{
    return m_workers.size();
}

int Factory::getMachineCount() const
{
    return m_machines.size();
}

int Factory::getHeadWorkerCount() const
{
    return m_head_workers.size();
}
