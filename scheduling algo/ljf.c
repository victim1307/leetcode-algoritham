#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int pid[MAX_SIZE], at[MAX_SIZE], bt[MAX_SIZE], ct[MAX_SIZE];
    int n, i, j, temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process ID, arrival time, and burst time for each process
    printf("Enter process ID, arrival time, and burst time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }

    // Sort processes in descending order of burst time using selection sort
    for (i = 0; i < n - 1; i++) {
        int max_index = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] > bt[max_index]) {
                max_index = j;
            }
        }
        // Swap the process with maximum burst time with the current process
        temp = bt[i];
        bt[i] = bt[max_index];
        bt[max_index] = temp;

        temp = at[i];
        at[i] = at[max_index];
        at[max_index] = temp;

        temp = pid[i];
        pid[i] = pid[max_index];
        pid[max_index] = temp;
    }

    // Calculate completion time and print the schedule table
    int total_time = 0;
    printf("\nPID\tAT\tBT\tCT\n");
    for (i = 0; i < n; i++) {
        ct[i] = total_time + bt[i];
        printf("%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i]);
        total_time = ct[i];
    }

    return 0;
}
