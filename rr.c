// NAME - BHUVNESH VERMA
// ROLL NO - A2_28
// BRANCH - AIML
// LAB - OS 
// PRACTICAL - PRACTICAL 4


#include <stdio.h>

#define MAX 100

void roundRobin(int pid[], int bt[], int n, int timeQuantum) {
    int wt[MAX], tat[MAX], rem_bt[MAX];
    int time = 0;
    int i;
    
    // Initialize remaining burst times
    for (i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    // Initialize waiting time and turnaround time arrays
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }

    // Process scheduling
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is a pending process
                if (rem_bt[i] > timeQuantum) {
                    time += timeQuantum;
                    rem_bt[i] -= timeQuantum;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }

    // Calculate turnaround times
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Print results
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }
}

int main() {
    int n, timeQuantum;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n];

    // Input process IDs and burst times
    printf("Enter values for PID array:\n");
    for (int i = 0; i < n; i++) {
        printf("PID[%d]: ", i + 1);
        scanf("%d", &pid[i]);
    }

    printf("Enter values for BT array:\n");
    for (int i = 0; i < n; i++) {
        printf("BT[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Input time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    // Call Round Robin scheduling function
    roundRobin(pid, bt, n, timeQuantum);

    return 0;
}

