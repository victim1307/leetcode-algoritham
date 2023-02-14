#include<stdio.h>

// Function to implement SJF scheduling algorithm
void SJF(int pid[], int at[], int bt[], int n)
{
    int wt[n], tat[n], ct[n];
    int total_wt = 0, total_tat = 0;

    // Sort the processes based on their burst time
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(bt[j] > bt[j+1])
            {
                int temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;

                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
            }
        }
    }

    // Calculate the completion time of each process
    for(int i=0; i<n; i++)
    {
        if(i == 0)
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // Calculate the turnaround time and waiting time of each process
    for(int i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Print the results
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Turnaround Time = %0.2f\n", (float)total_tat/n);
    printf("Average Waiting Time = %0.2f\n", (float)total_wt/n);
}

int main()
{
    int pid[] = {1, 2, 3, 4};
    int at[] = {1, 0, 0, 6};
    int bt[] = {1, 2, 2, 5};
    int n = sizeof(pid)/sizeof(pid[0]);

    // Call the SJF function with the input data
    SJF(pid, at, bt, n);

    return 0;
}

