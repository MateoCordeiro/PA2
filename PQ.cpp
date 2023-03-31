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
