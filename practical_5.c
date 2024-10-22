#include <stdio.h>
int main() {
    int n = 5;
    int m = 3;
    int Allocation[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    int Max[5][3] = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3} };
    int Available[3] = {3, 3, 2};
    int need[5][3];
    int Flag[5] = {0};
    int iteration = 0;
    int completedProcesses = 0;

    // Calculate the Need matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    // Print Need matrix
    printf("Need Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Banker's Algorithm execution
    while (completedProcesses < n) {
        int foundProcess = 0;
        for (int i = 0; i < n; i++) {
            if (Flag[i] == 0) {
                int Proceed = 1;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > Available[j]) {
                        Proceed = 0;
                        break;
                    }
                }

                if (Proceed) {
                    for (int j = 0; j < m; j++) {
                        Available[j] += Allocation[i][j];
                    }
                    printf("Process %d can be executed\n", i + 1);
                    Flag[i] = 1;
                    completedProcesses++;
                    foundProcess = 1;
                }
            }
        }

        if (!foundProcess) {
            printf("The processes have to wait.\n");
            break;
        }
    }

    // Print Available matrix after execution
    printf("The available matrix will be:\n");
    for (int j = 0; j < m; j++) {
        printf("%d ", Available[j]);
    }
    printf("\n");

    return 0;
}
