//**********************************
// PA         : 2
// Programmer : Mateo Cordeiro
// Status     : incomplete
// Date       : 03/29/23
//
//**********************************

#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>
#include <windows.h>



using namespace std;


// Define the process structure
struct Process {
    int id;
    double arrival_time;
    double service_time;
    double start_time;
    double end_time;
    double turnaround_time;
};

// Define the Event structure
struct Event {
    double time;
    int type; // 1: process arrival, 2: process completion
    Process process;
};

// Define a custom comparator for the Event priority queue
struct EventComparator {
    bool operator() (const Event& e1, const Event& e2) {
        return e1.time > e2.time; // sort events in ascending order of time
    }
};

// Define the state of the system
struct SystemState {
    int num_processes_in_queue;
    bool cpu_busy;
    Process current_process;
};

