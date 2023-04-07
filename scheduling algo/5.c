#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 4
#define NUM_RESOURCES 3

int available[NUM_RESOURCES] = {3, 3, 2};

int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1}
};

int max[NUM_PROCESSES][NUM_RESOURCES] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2}
};

int need[NUM_PROCESSES][NUM_RESOURCES];

bool finish[NUM_PROCESSES] = {false};

int safe_sequence[NUM_PROCESSES];
int num_safe_processes = 0;

bool is_safe() {
    // Initialize need
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize finish
    for (int i = 0; i < NUM_PROCESSES; i++) {
        finish[i] = false;
    }

    // Initialize work
    int work[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    // Find an i such that finish[i] == false and need[i] <= work
    bool found = true;
    while (found) {
        found = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                bool need_leq_work = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        need_leq_work = false;
                        break;
                    }
                }
                if (need_leq_work) {
                    // i can be finished
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    safe_sequence[num_safe_processes++] = i;
                    found = true;
                }
            }
        }
    }

    // Check if all processes were finished
    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (!finish[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    if (is_safe()) {
        printf("Safe sequence: ");
        for (int i = 0; i < NUM_PROCESSES; i++) {
            printf("P%d ", safe_sequence[i]);
        }
        printf("\n");
    } else {
        printf("Unsafe state\n");
    }

    return 0;
}
