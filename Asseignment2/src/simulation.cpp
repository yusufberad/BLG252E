#include "../include/simulation.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


// constructor
Simulation::Simulation(Factory &factory, int total_days, string workers_list_path, string machines_list_path)
{
    m_factory = &factory;
    m_total_days = total_days;

    // read workers and machines from files
    ifstream workers_file(workers_list_path);
    ifstream machines_file(machines_list_path);
    
    string line;
    string name, price, cost_per_day, base_return_per_day, failure_probability, repair_time, repair_cost;
    while (getline(workers_file, line))
    {   
        stringstream fline(line);
        getline(fline, name, ' ');
        getline(fline, cost_per_day, ' ');
        getline(fline, base_return_per_day, ' ');
        if (name != "name")
        {
            Worker worker(name, stof(cost_per_day), stof(base_return_per_day));
            m_labor_market.push_back(worker);
        }
        
    }
    while (getline(machines_file, line))
    {   
        stringstream fline(line);
        getline(fline, name, ' '); 
        getline(fline, price, ' ');
        getline(fline, cost_per_day, ' ');
        getline(fline, base_return_per_day, ' ');
        getline(fline, failure_probability, ' ');
        getline(fline, repair_cost, ' ');
        getline(fline, repair_time, ' ');
        if (name != "name"){
            Machine machine(name, stof(price), stof(cost_per_day), stof(base_return_per_day), stof(failure_probability), stoi(repair_time), stof(repair_cost));
            m_machines_market.push_back(machine);
        }
    }
}




// print welcome message
void Simulation::printWelcomeMessage() const
{
    cout << "Welcome to the Car Factory!" << endl;
    cout << "You have " << m_total_days << " days to make as much money as possible" << endl;
    cout << "You can add workers, machines, and fast forward days" << endl;

    cout << "Available commands:" << endl;
    cout << "    wX: adds X workers" << endl;
    cout << "    mX: adds X machines" << endl;
    cout << "    pX: passes X days" << endl;
    cout << "    q: exit the game properly" << endl;
}

// buy a random machine
Machine Simulation::buyRandomMachine()
{  
    int random_index = rand() % m_machines_market.size();
    Machine random_machine = m_machines_market[random_index];
    m_machines_market.erase(m_machines_market.begin() + random_index);
    return random_machine;
}

// hire a random worker
Worker Simulation::hireRandomWorker()
{   
    int random_index = rand() % m_labor_market.size();
    Worker random_worker = m_labor_market[random_index];
    m_labor_market.erase(m_labor_market.begin() + random_index);
    return random_worker;
}


// run the simulation
void Simulation::run()
{

    string command;
    cout << "Enter a command: ";
    cin >> command;
    // loop until the user types 'q'
    while(command != "q")
    {
        // if the command is to add workers
        if(command[0] == 'w')
        {   
            int worker_count = stoi(command.substr(1));
            for(int i = 0; i < worker_count; i++)
            {
                Worker random_worker = hireRandomWorker();
                m_factory->addUnit(random_worker);
            }
        }
        // if the command is to add machines
        else if(command[0] == 'm')
        {   
            int machine_count = stoi(command.substr(1));
            for(int i = 0; i < machine_count; i++)
            {
                Machine random_machine = buyRandomMachine();
                m_factory->addUnit(random_machine);
            }
        }
        // if the command is to pass days
        else if(command[0] == 'p')
        {
            int days = stoi(command.substr(1));
            for(int i = 0; i < days; i++)
            {   
                m_total_days--;
                cout << "--- Day " << 30 - m_total_days << endl;
                m_factory->passOneDay();
            }
        }
        // if the command is invalid
        else
        {
            cout << "Invalid command" << endl;
        }
        if(m_factory->isBankrupt()){
            cout << "You are bankrupt!" << endl;
            break;
        }
        // get the next command
        cout << "Enter a command: ";
        cin >> command;
    }

    // print the final capital
    cout << "Congrats! You have earned " << m_factory->getCapital() - 100 << " in 30 days" << endl;   
}