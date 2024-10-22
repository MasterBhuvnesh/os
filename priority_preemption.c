#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Function to find waiting time and turnaround time
void findWaitingTime(int pid[], int n, int BT[], int WT[], int TAT[], int PR[]) {
    int remainingBT[MAX], completed = 0, currentTime = 0, minPriority = MAX;
    bool isCompleted[MAX] = {false};  // To track if process is completed
    
    // Initialize remaining burst times as the burst times initially
    for (int i = 0; i < n; i++) {
        remainingBT[i] = BT[i];
    }

    while (completed < n) {
        int highestPriorityProcess = -1;
        minPriority = MAX;

        // Find the process with the highest priority (lowest priority value)
        for (int i = 0; i < n; i++) {
            if (!isCompleted[i] && PR[i] < minPriority && remainingBT[i] > 0) {
                minPriority = PR[i];
                highestPriorityProcess = i;
            }
        }

        if (highestPriorityProcess == -1) {
            currentTime++;
            continue;
        }

        // Execute the process
        remainingBT[highestPriorityProcess]--;
        currentTime++;

        // If the process is completed
        if (remainingBT[highestPriorityProcess] == 0) {
            completed++;
            isCompleted[highestPriorityProcess] = true;
            int finishTime = currentTime;

            // Calculate turnaround time and waiting time
            TAT[highestPriorityProcess] = finishTime;
            WT[highestPriorityProcess] = TAT[highestPriorityProcess] - BT[highestPriorityProcess];
        }
    }
}

int main() {
    int n, pid[MAX], BT[MAX], WT[MAX], TAT[MAX], PR[MAX];
    float avgWT = 0.0, avgTAT = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process IDs
    printf("Enter process IDs:\n");
    for (int i = 0; i < n; i++) {
        printf("PID[%d]: ", i+1);
        scanf("%d", &pid[i]);
    }

    // Input burst times
    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("BT[%d]: ", i+1);
        scanf("%d", &BT[i]);
    }

    // Input priorities
    printf("Enter priorities:\n");
    for (int i = 0; i < n; i++) {
        printf("PR[%d]: ", i+1);
        scanf("%d", &PR[i]);
    }

    // Calculate waiting times and turnaround times
    findWaitingTime(pid, n, BT, WT, TAT, PR);

    // Display the process details
    printf("\nPID  -->  BT  -->  Priority  -->  WT  -->  TAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d    -->  %d   -->  %d      -->  %d   -->  %d\n", pid[i], BT[i], PR[i], WT[i], TAT[i]);
        avgWT += WT[i];
        avgTAT += TAT[i];
    }

    // Calculate and display average waiting time and turnaround time
    avgWT /= n;
    avgTAT /= n;
    printf("Average Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);

    return 0;
}
