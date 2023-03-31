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

using namespace std;

/////////////////////////////////////////////////////////////////////////
// Structs
/////////////////////////////////////////////////////////////////////////

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
// Define Node
struct Node {
    Event event;
    Process process;
    Node* next;
};

/////////////////////////////////////////////////////////////////////////
// Priority Queue
/////////////////////////////////////////////////////////////////////////

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() {
        head = nullptr;
    }
    ~PriorityQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insert(Event event, Process process) {
        Node* new_node = new Node;
        new_node->event = event;
        new_node->process = process;
        new_node->next = nullptr;

        if (head == nullptr || head->process.end_time <= process.arrival_time) {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->process.end_time > process.arrival_time) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
    Node* pop() {
        if (head == nullptr) {
            return nullptr;
        }

        Node* temp = head;
        head = head->next;
        return temp;
    }
    void print() {
        Node* current = head;
        vector<Node*> nodes;
        while (current != nullptr) {
            nodes.push_back(current);
            current = current->next;
        }
        for (int i = nodes.size() - 1; i >= 0; i--) {
            cout << "Process ID: " << nodes[i]->process.id
                << " Time: " << fixed << setprecision(2) << nodes[i]->event.time;
            if (nodes[i]->event.type == 1) {
                cout << " Event Type: Arrival"
                    << " Arrival Time: " << nodes[i]->process.arrival_time
                    << " Service Time: " << nodes[i]->process.service_time << endl;
            } else {
                cout << " Event Type: Completion"
                    << " Start Time: " << nodes[i]->process.start_time
                    << " End Time: " << nodes[i]->process.end_time
                    << " Turnaround Time: " << nodes[i]->process.turnaround_time << endl;
            }
        }
    }
    bool is_empty() {
        return head == nullptr;
    }
};

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

void processor() {

    bool state = false;
    int numInQ = 0;

}

/////////////////////////////////////////////////////////////////////////
// Main
/////////////////////////////////////////////////////////////////////////

int main() {
    PriorityQueue pq;

    // // Add some events to the priority queue
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

    // // Print out the events in the priority queue
    pq.print();

    double lambda = 10;
    double totalArrivalTime = 0;

    bool seeded=false;
    if (!seeded)
    {
        srand(time(nullptr));
        seeded=true;
    }

    double current_time = 0;
    for (int i = 1; i <= 5000; i++) {
        // Generate arrival event
        Process process;
        process.id = i;
        process.arrival_time = current_time + interArrivalTimes(lambda);
        process.service_time = serviceTime();
        process.end_time = 0;
        process.turnaround_time = 0;
        Event arrival_event;
        arrival_event.time = process.arrival_time;
        arrival_event.type = 1; // arrival
        arrival_event.process = process;

        // Generate departure event
        Process process_copy = process; // make a copy to store in departure event
        Event departure_event;
        departure_event.time = process.arrival_time + process.service_time;
        departure_event.type = 2; // departure

        pq.insert(arrival_event, process);
        pq.insert(departure_event, process);

        current_time = process.arrival_time;
    }

    pq.print();

////////////////////////////////////////////

    double worldClock = 0;


    return 0;
}