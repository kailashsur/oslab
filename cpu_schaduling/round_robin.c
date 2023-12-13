#include <stdio.h>

// Function to perform Round Robin Scheduling
void roundRobinScheduling(int processes[], int n, int burstTimes[], int timeQuantum) {
    // Arrays to store waiting time and turnaround time
    int waitingTimes[n], turnaroundTimes[n];

    // Initialize waiting time and turnaround time arrays
    for (int i = 0; i < n; i++) {
        waitingTimes[i] = 0;
        turnaroundTimes[i] = 0;
    }

    int remainingBurstTimes[n];  // Array to store remaining burst times
    for (int i = 0; i < n; i++) {
        remainingBurstTimes[i] = burstTimes[i];
    }

    int currentTime = 0;
    int flag = 0;

    // Perform Round Robin Scheduling
    while (1) {
        flag = 0; // Flag to check if any process has remaining burst time

        for (int i = 0; i < n; i++) {
            if (remainingBurstTimes[i] > 0) {
                flag = 1; // There is a process with remaining burst time

                if (remainingBurstTimes[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingBurstTimes[i] -= timeQuantum;
                } else {
                    currentTime += remainingBurstTimes[i];
                    waitingTimes[i] = currentTime - burstTimes[i];
                    remainingBurstTimes[i] = 0;
                    turnaroundTimes[i] = currentTime;
                }
            }
        }

        if (flag == 0) {
            break; // No process has remaining burst time
        }
    }

    // Calculate average waiting time and average turnaround time
    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTimes[i];
        avgTurnaroundTime += turnaroundTimes[i];
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    // Display the schedule and performance metrics
    printf("\nProcess Schedule (Round Robin Scheduling):\n");
    printf("-----------------------------------------------------------\n");
    printf("Process ID | Burst Time | Waiting Time | Turnaround Time\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("   %2d      |     %2d      |       %2d      |        %2d      \n",
               processes[i], burstTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }

    printf("-----------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
    // Number of processes
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Arrays to store process details
    int processes[n];
    int burstTimes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTimes[i]);
    }

    // Time quantum for Round Robin Scheduling
    int timeQuantum;

    printf("Enter the time quantum for Round Robin Scheduling: ");
    scanf("%d", &timeQuantum);

    // Perform Round Robin Scheduling and calculate performance metrics
    roundRobinScheduling(processes, n, burstTimes, timeQuantum);

    return 0;
}
