#include <stdio.h>
#include <stdlib.h>

#define NUM_REQUESTS 11

// Function to calculate FCFS total movements
void calculateFCFS(int requests[], int count, int head) {
    int totalMovement = 0;
    int currentPos = head;

    for (int i = 0; i < count; i++) {
        totalMovement += abs(currentPos - requests[i]);
        currentPos = requests[i];
    }

    printf("FCFS Total Movements: %d\n", totalMovement);
}

// Function to calculate SSTF total movements
void calculateSSTF(int requests[], int count, int head) {
    int totalMovement = 0;
    int visited[NUM_REQUESTS] = {0};  // To track visited requests
    int currentPos = head;

    for (int i = 0; i < count; i++) {
        int minIndex = -1;
        int minDistance = 10000; // Large number for comparison

        for (int j = 0; j < count; j++) {
            if (!visited[j]) {
                int distance = abs(currentPos - requests[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    minIndex = j;
                }
            }
        }

        if (minIndex != -1) {
            totalMovement += minDistance;
            currentPos = requests[minIndex];
            visited[minIndex] = 1;
        }
    }

    printf("SSTF Total Movements: %d\n", totalMovement);
}

// Function to calculate C-Look total movements
void calculateCLook(int requests[], int count, int head) {
    int totalMovement = 0;
    int currentPos = head;

    // Sort the requests in ascending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // Find the starting index where the requests are greater than the head
    int startIndex = 0;
    while (startIndex < count && requests[startIndex] < head) {
        startIndex++;
    }

    // Serve requests from the start index to the end
    for (int i = startIndex; i < count; i++) {
        totalMovement += abs(currentPos - requests[i]);
        currentPos = requests[i];
    }

    // After reaching the end, serve the remaining requests from the beginning
    if (startIndex > 0) {
        totalMovement += abs(currentPos - requests[0]);
        currentPos = requests[0];
        for (int i = 1; i < startIndex; i++) {
            totalMovement += abs(currentPos - requests[i]);
            currentPos = requests[i];
        }
    }

    printf("C-Look Total Movements: %d\n", totalMovement);
}

int main() {
    int requests[NUM_REQUESTS] = {86, 147, 91, 177, 94, 150, 102, 130, 175, 120, 189};
    int head = 143;

    // Calculate total movements for each scheduling algorithm
    calculateFCFS(requests, NUM_REQUESTS, head);
    calculateSSTF(requests, NUM_REQUESTS, head);
    calculateCLook(requests, NUM_REQUESTS, head);

    return 0;
}
