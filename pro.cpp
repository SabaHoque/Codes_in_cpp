#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
// Structure to represent a process
struct Process {
int pid; // Process ID
int burstTime; // Burst Time
int arrivalTime; // Arrival Time
int priority; // Priority (used for Priority Scheduling)
int waitingTime; // Waiting Time
int turnAroundTime; // Turnaround Time
int remainingTime; // Remaining Time (used for Round Robin and SRTF)
};
// Function to display process details
void displayProcesses(const vector<Process>& processes) {
cout << "\nPID\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n";
for (const auto& p : processes) {
cout << p.pid << "\t" << p.burstTime << "\t\t" << p.arrivalTime
<< "\t\t" << p.priority << "\t\t" << p.waitingTime
<< "\t\t" << p.turnAroundTime << "\n";
}
}
// Function to calculate average waiting time
float calculateAverageWaitingTime(const vector<Process>& processes) {
float totalWaitingTime = 0;
for (const auto& p : processes) {
totalWaitingTime += p.waitingTime;
}
return totalWaitingTime / processes.size();
}
// Function to generate a Gantt Chart
void generateGanttChart(const vector<pair<int, int>>& gantt) {
cout << "\nGantt Chart:\n";
for (const auto& g : gantt) {
cout << "| P" << g.first << " ";
}

cout << "|\n";
for (const auto& g : gantt) {
cout << g.second << "\t";
}
cout << "\n";
}
// First-Come, First-Served Scheduling
void fcfs(vector<Process> processes) {
sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
return a.arrivalTime < b.arrivalTime;
});
int currentTime = 0;
vector<pair<int, int>> gantt;
for (auto& p : processes) {
if (currentTime < p.arrivalTime) {
currentTime = p.arrivalTime;
}
p.waitingTime = currentTime - p.arrivalTime;
currentTime += p.burstTime;
gantt.emplace_back(p.pid, currentTime);
p.turnAroundTime = p.waitingTime + p.burstTime;
}
displayProcesses(processes);
generateGanttChart(gantt);
cout << "\nAverage Waiting Time: " << calculateAverageWaitingTime(processes) << "\n";
}
// Shortest Job First Scheduling
void sjf(vector<Process> processes) {
sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
return a.arrivalTime < b.arrivalTime;
});
int currentTime = 0;
vector<Process> readyQueue;
vector<Process> completed;
vector<pair<int, int>> gantt;
while (!processes.empty() || !readyQueue.empty()) {
for (auto it = processes.begin(); it != processes.end();) {
if (it->arrivalTime <= currentTime) {

readyQueue.push_back(*it);
it = processes.erase(it);
} else {
++it;
}
}
if (!readyQueue.empty()) {
sort(readyQueue.begin(), readyQueue.end(), [](const Process& a, const Process& b) {
return a.burstTime < b.burstTime;
});
auto p = readyQueue.front();
readyQueue.erase(readyQueue.begin());
p.waitingTime = currentTime - p.arrivalTime;
if (p.waitingTime < 0) p.waitingTime = 0;
currentTime += p.burstTime;
gantt.emplace_back(p.pid, currentTime);
p.turnAroundTime = p.waitingTime + p.burstTime;
completed.push_back(p);
} else {
currentTime++;
}
}
displayProcesses(completed);
generateGanttChart(gantt);
cout << "\nAverage Waiting Time: " << calculateAverageWaitingTime(completed) << "\n";
}
// Shortest Job First with Preemption (Shortest Remaining Time First - SRTF)
void srtf(vector<Process> processes) {
int n = processes.size();
int currentTime = 0;
int completed = 0;
vector<int> remainingTime(n);
vector<pair<int, int>> gantt;
for (int i = 0; i < n; ++i) {
remainingTime[i] = processes[i].burstTime;
}
while (completed < n) {
int shortest = -1;

int minRemainingTime = INT_MAX;
for (int i = 0; i < n; ++i) {
if (processes[i].arrivalTime <= currentTime && remainingTime[i] > 0 && remainingTime[i]
< minRemainingTime) {
minRemainingTime = remainingTime[i];
shortest = i;
}
}
if (shortest == -1) {
currentTime++;
continue;
}
gantt.emplace_back(processes[shortest].pid, currentTime);
remainingTime[shortest]--;
currentTime++;
if (remainingTime[shortest] == 0) {
completed++;
processes[shortest].turnAroundTime = currentTime - processes[shortest].arrivalTime;
processes[shortest].waitingTime = processes[shortest].turnAroundTime -
processes[shortest].burstTime;
}
}
displayProcesses(processes);
generateGanttChart(gantt);
cout << "\nAverage Waiting Time: " << calculateAverageWaitingTime(processes) << "\n";
}
// Priority Scheduling
void priorityScheduling(vector<Process> processes) {
sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
return a.arrivalTime < b.arrivalTime;
});
int currentTime = 0;
vector<Process> readyQueue;
vector<Process> completed;
vector<pair<int, int>> gantt;
while (!processes.empty() || !readyQueue.empty()) {

for (auto it = processes.begin(); it != processes.end();) {
if (it->arrivalTime <= currentTime) {
readyQueue.push_back(*it);
it = processes.erase(it);
} else {
++it;
}
}
if (!readyQueue.empty()) {
sort(readyQueue.begin(), readyQueue.end(), [](const Process& a, const Process& b) {
return a.priority < b.priority;
});
auto p = readyQueue.front();
readyQueue.erase(readyQueue.begin());
p.waitingTime = currentTime - p.arrivalTime;
if (p.waitingTime < 0) p.waitingTime = 0;
currentTime += p.burstTime;
gantt.emplace_back(p.pid, currentTime);
p.turnAroundTime = p.waitingTime + p.burstTime;
completed.push_back(p);
} else {
currentTime++;
}
}
displayProcesses(completed);
generateGanttChart(gantt);
cout << "\nAverage Waiting Time: " << calculateAverageWaitingTime(completed) << "\n";
}
// Round Robin Scheduling
void roundRobin(vector<Process> processes, int timeQuantum) {
sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
return a.arrivalTime < b.arrivalTime;
});
vector<Process> readyQueue;
vector<Process> completed;
vector<pair<int, int>> gantt;
int currentTime = 0;
for (auto& p : processes) {

p.remainingTime = p.burstTime;
}
while (!processes.empty() || !readyQueue.empty()) {
for (auto it = processes.begin(); it != processes.end();) {
if (it->arrivalTime <= currentTime) {
readyQueue.push_back(*it);
it = processes.erase(it);
} else {
++it;
}
}
if (!readyQueue.empty()) {
auto p = readyQueue.front();
readyQueue.erase(readyQueue.begin());
int executedTime = min(p.remainingTime, timeQuantum);
gantt.emplace_back(p.pid, currentTime);
currentTime += executedTime;
p.remainingTime -= executedTime;
if (p.remainingTime > 0) {
readyQueue.push_back(p);
} else {
p.waitingTime = currentTime - p.arrivalTime - p.burstTime;
if (p.waitingTime < 0) p.waitingTime = 0;
p.turnAroundTime = p.waitingTime + p.burstTime;
completed.push_back(p);
}
} else {
currentTime++;
}
}
displayProcesses(completed);
generateGanttChart(gantt);
cout << "\nAverage Waiting Time: " << calculateAverageWaitingTime(completed) << "\n";
}
// Main menu
void menu() {
vector<Process> processes;
int n;

cout << "Enter the number of processes: ";
cin >> n;
for (int i = 0; i < n; ++i) {
Process p;
p.pid = i + 1;
cout << "Enter burst time for process " << p.pid << ": ";
cin >> p.burstTime;
cout << "Enter arrival time for process " << p.pid << ": ";
cin >> p.arrivalTime;
cout << "Enter priority for process " << p.pid << ": ";
cin >> p.priority;
processes.push_back(p);
}
int choice;
do {
cout << "\nCPU Scheduling Simulator\n";
cout << "1. First-Come, First-Served (FCFS)\n";
cout << "2. Shortest Job First (SJF)\n";
cout << "3. Priority Scheduling\n";
cout << "4. Round Robin (RR)\n";
cout << "5. Shortest Job First (Preemptive - SRTF)\n";
cout << "6. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
fcfs(processes);
break;
case 2:
sjf(processes);
break;
case 3:
priorityScheduling(processes);
break;
case 4: {
int timeQuantum;
cout << "Enter time quantum for Round Robin: ";
cin >> timeQuantum;
roundRobin(processes, timeQuantum);
break;
}

case 5:
srtf(processes);
break;
case 6:
cout << "Exiting...\n";
break;
default:
cout << "Invalid choice! Please try again.\n";
}
} while (choice != 6);
}
int main() {
menu();
return 0;
}
