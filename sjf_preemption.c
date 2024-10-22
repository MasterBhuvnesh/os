// NAME - BHUVNESH VERMA
// ROLL NO - A2_28
// BRANCH - AIML
// LAB - OS 
// PRACTICAL - PRACTICAL 4
// TOPIC - SJF WITH PREEMPTION 


#include <stdio.h>
#include <limits.h>

void bubbleSort(int array[], int array2[], int size) {
    for (int step = 0; step < size - 1; ++step) { 
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                
                int temp2 = array2[i];
                array2[i] = array2[i + 1];
                array2[i + 1] = temp2;
            }
        }
    }
}

void sjfPreemptive(int n, int pid[], int BT[], int AT[], int WT[], int TAT[]) {
    int remBT[n], complete = 0, t = 0, minIndex, minBT;
    int timeRemaining[n];
    
    for (int i = 0; i < n; i++) {
        remBT[i] = BT[i];
        timeRemaining[i] = INT_MAX;
    }

    while (complete < n) {
        minBT = INT_MAX;
        minIndex = -1;
        
        for (int i = 0; i < n; i++) {
            if (AT[i] <= t && remBT[i] > 0 && remBT[i] < minBT) {
                minBT = remBT[i];
                minIndex = i;
            }
        }
        
        if (minIndex != -1) {
            remBT[minIndex]--;
            timeRemaining[minIndex] = t;
            
            if (remBT[minIndex] == 0) {
                complete++;
                TAT[minIndex] = t + 1 - AT[minIndex];
                WT[minIndex] = TAT[minIndex] - BT[minIndex];
            }
        }
        t++;
    }
}

int main() {
    int n;
    float avgWT = 0.0, avgTAT = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], BT[n], AT[n], WT[n], TAT[n];
    
    printf("Enter values for PID array:\n");
    for (int i = 0; i < n; i++) {
        printf("PID[%d]: ", i+1);
        scanf("%d", &pid[i]);
    }
    
    printf("Enter values for Burst Time (BT) array:\n");
    for (int i = 0; i < n; i++) {
        printf("BT[%d]: ", i+1);
        scanf("%d", &BT[i]);
    }
    
    printf("Enter values for Arrival Time (AT) array:\n");
    for (int i = 0; i < n; i++) {
        printf("AT[%d]: ", i+1);
        scanf("%d", &AT[i]);
    }

    // Initialize WT and TAT arrays to 0
    for (int i = 0; i < n; i++) {
        WT[i] = 0;
        TAT[i] = 0;
    }

    sjfPreemptive(n, pid, BT, AT, WT, TAT);

    printf("\nPID  -->  BT  -->  AT  -->  WT  -->  TAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d    -->  %d   -->  %d   -->  %d   -->  %d\n", pid[i], BT[i], AT[i], WT[i], TAT[i]);
    }
    
    for (int i = 0; i < n; i++) {
        avgWT += WT[i];
       avgTAT += TAT[i];
    }
    
    printf("AVERAGE WT is %.2f\n", avgWT / n);
   printf("AVERAGE TAT is %.2f\n", avgTAT / n);
    
    return 0;
}

