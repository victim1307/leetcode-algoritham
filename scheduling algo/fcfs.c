#include <stdio.h>

#define MAX_PROCESSES 100

// structure to hold process details
struct process {
    char id[10];
    int arrival_time;
    int burst_time;
};

int main() {
    int n;
    struct process processes[MAX_PROCESSES];

    // get number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // get process details
    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i + 1);
        printf("ID: ");
        scanf("%s", processes[i].id);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
    }

    // sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // calculate waiting times and turnaround times
    int wait_time = 0, turnaround_time = 0;
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        wait_time += processes[i].burst_time;
        turnaround_time += wait_time - processes[i].arrival_time;
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, 
               processes[i].burst_time, wait_time - processes[i].burst_time - processes[i].arrival_time, 
               wait_time - processes[i].arrival_time);
    }

    // calculate average waiting time and average turnaround time
    float avg_wait_time = (float) wait_time / n;
    float avg_turnaround_time = (float) turnaround_time / n;
    printf("Average waiting time: %.2f\n", avg_wait_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}