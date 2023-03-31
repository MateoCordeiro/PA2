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
#include <iomanip>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>
#include <windows.h>
#include "FCFS.h"
using namespace std;


/////////////////////////////////////////////////////////////////////////
// Number generators
/////////////////////////////////////////////////////////////////////////

double factorial(double n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

double interArrivalTimes(double lambda) {
    return abs(((1/lambda)*(log((double)rand() / (double)RAND_MAX))));
}

double serviceTime() {
    return (0.04 * -log(1 - ((double)rand() / (double)RAND_MAX)));
}

/////////////////////////////////////////////////////////////////////////
// CPU Processor
/////////////////////////////////////////////////////////////////////////

void processor(PriorityQueue pq) {

    PriorityQueue RQ;
    PriorityQueue DQ;
    bool state = false;
    int numInQ = 0;
    bool isServerIdle = true; 
    double worldClock = 0;
    double turnAroundSum = 0;
    
    while (!pq.is_empty())
    {
        Node *temp = pq.pop();
        pq.print();

        if (temp->event.type == 1) // Arrival
        {
            if (isServerIdle == true)
            {
                temp->process.start_time = worldClock;
                worldClock += temp->process.service_time;
                temp->process.end_time = worldClock;
                temp->process.turnaround_time = (temp->process.start_time - temp->process.end_time);
                DQ.insert(temp->event, temp->process);
                DQ.print();
                temp->process.turnaround_time += turnAroundSum;
            }
            if (isServerIdle == false)
            {
                RQ.insert(temp->event, temp->process);
                numInQ++;
                RQ.print();
            }
        }
        else (temp->event.type == 2) // Departure
        ;{
            
        }
    }
}

void arrHandler(Event e, Process p) {

}

/////////////////////////////////////////////////////////////////////////
// Main
/////////////////////////////////////////////////////////////////////////

int main() {
    PriorityQueue pq;
    // Add some events to the priority queue
    // Process p1 = {1, 0.0, 5.0, 0.0, 0.0, 0.0};
    // Event e1 = {p1.arrival_time, 1, p1};
    // pq.insert(e1, p1);
    // Process p2 = {2, 2.0, 3.0, 0.0, 0.0, 0.0};
    // Event e2 = {p2.arrival_time, 1, p2};
    // pq.insert(e2, p2);
    // Process p3 = {3, 4.0, 4.0, 0.0, 0.0, 0.0};
    // Event e3 = {p3.arrival_time, 1, p3};
    // pq.insert(e3, p3);
    // Process p4 = {4, 5.0, 2.0, 0.0, 0.0, 0.0};
    // Event e4 = {p4.arrival_time, 1, p4};
    // pq.insert(e4, p4);
    // Print out the events in the priority queue
    // pq.print();

    double lambda = 10;
    double totalArrivalTime = 0;

    bool seeded=false;
    if (!seeded)
    {
        srand(time(nullptr));
        seeded=true;
    }

    // double current_time = 0;
    // for (int i = 1; i <= 5000; i++) {
    //     // Generate arrival event
    //     Process process;
    //     process.id = i;
    //     process.arrival_time = current_time + interArrivalTimes(lambda);
    //     process.service_time = serviceTime();
    //     process.end_time = 0;
    //     process.turnaround_time = 0;
    //     Event arrival_event;
    //     arrival_event.time = process.arrival_time;
    //     arrival_event.type = 1; // arrival
    //     arrival_event.process = process;

    //     // Generate departure event
    //     Process process_copy = process; // make a copy to store in departure event
    //     Event departure_event;
    //     departure_event.time = process.arrival_time + process.service_time;
    //     departure_event.type = 2; // departure

    //     pq.insert(arrival_event, process);
    //     pq.insert(departure_event, process);

    //     current_time = process.arrival_time;
    // }
    // pq.print();

////////////////////////////////////////////

    double worldClock = 0;
    Process p1;
    p1.id = 0;
    p1.arrival_time = 0;
    p1.service_time = 1;
    p1.start_time = 0;
    p1.end_time = 1;
    p1.turnaround_time = 1;
    Event e1;
    e1.time = 1;
    e1.type = 1;
    e1.process = p1;

    pq.insert(e1, p1);
    processor(pq);

    FCFS fcfs;
    fcfs.init(10, .04, 1000);
    fcfs.hi();
    cout << setprecision(5) <<fcfs.genRand0_1() << endl;
    cout << fcfs.genIntArrTime() << endl;
    cout << fcfs.genServiceTime() << endl;

    return 0;
}