//**********************************
// PA         : 2
// Programmer : Mateo Cordeiro
// Status     : incomplete
// Date       : 03/29/23
//
//**********************************

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct process {
    float arrivalTime;
    float serviceTime;
    float remainingServiceTime;
    int priority;
};

struct event {
    int type;
    float time;
    event* nextEvent;
    process* p;
};

int main() {
    
    // Init
    int lamda = 10;
    int clock = 0;
    bool serverIdle = true;
    int readyQueueCount = 0;

    //generate seed
    srand((unsigned) time(NULL));

    double randy;
    randy = (double)rand() / RAND_MAX;

    std::cout << randy << std::endl; 

    // // need to gen 10,000 processes
    // int processCount = 0;
    // while (processCount < 10000) {
        
    //     event *e1 = new event;
    //     event *e2 = new event;
    //     e1->type = 0;
    //     e1->time = 0; //gen
    //     e1->nextEvent = e2;

    //     float arrTime = (-(1/lamda) * log());


    //     processCount++;
    // }

    return 0;
}
