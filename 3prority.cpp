#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

const int N = 100005;

struct process {
    int priority;
    int id;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int starting_time;
    int finishing_time;
    int waiting_time;
    int turn_around_time;
};

int n;
process P[N];

bool compareArrivalTime(process A, process B) {
    return A.arrival_time < B.arrival_time;
}

struct ComparePriority {
    bool operator()(const process &A, const process &B) {
        return A.priority > B.priority;
    }
};

void PriorityPreemptive() {
    sort(P, P + n, compareArrivalTime);

    priority_queue<process, vector<process>, ComparePriority> pq;
    int current_time = P[0].arrival_time;
    int completed = 0;
    double total_waiting_time = 0.0;
    double total_turn_around_time = 0.0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (P[i].arrival_time <= current_time && P[i].burst_time > 0) {
                pq.push(P[i]);
            }
        }

        if (pq.empty()) {
            current_time++;
            continue;
        }

        process current_process = pq.top();
        pq.pop();

        if (current_process.starting_time == -1) {
            current_process.starting_time = current_time;
        }

        current_process.remaining_time--;
        current_time++;

        if (current_process.remaining_time == 0) {
            current_process.finishing_time = current_time;
            current_process.turn_around_time = current_process.finishing_time - current_process.arrival_time;
            current_process.waiting_time = current_process.turn_around_time - current_process.burst_time;

            total_waiting_time += current_process.waiting_time;
            total_turn_around_time += current_process.turn_around_time;

            completed++;
        } else {
            pq.push(current_process);
        }
    }

    cout << fixed << setprecision(2);
    cout << "ID\tBurst Time\tArrival Time\tPriority\tWT\tCT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << P[i].id << "\t" << P[i].burst_time << "\t\t" << P[i].arrival_time << "\t\t" << P[i].priority << "\t\t" << P[i].waiting_time << "\t" << P[i].finishing_time << "\t" << P[i].turn_around_time << "\n";
    }

    cout << "Average Waiting Time: " << (total_waiting_time / n) << "\n";
    cout << "Average Turn Around Time: " << (total_turn_around_time / n) << "\n";
}

int main() {
    cout << "Number of Processes: ";
    cin >> n;

    cout << "Process Ids:\n";
    for (int i = 0; i < n; i++)
        cin >> P[i].id;

    cout << "Process Burst Times:\n";
    for (int i = 0; i < n; i++)
        cin >> P[i].burst_time;

    cout << "Process Arrival Times:\n";
    for (int i = 0; i < n; i++)
        cin >> P[i].arrival_time;

    cout << "Process Priorities:\n";
    for (int i = 0; i < n; i++)
        cin >> P[i].priority;

    for (int i = 0; i < n; i++) {
        P[i].remaining_time = P[i].burst_time;
        P[i].starting_time = -1;
    }

    PriorityPreemptive();
    return 0;
}
