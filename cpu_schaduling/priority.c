#include <stdio.h>

// Function to perform Priority Scheduling
void priorityScheduling(int processes[], int priorities[], int burstTimes[], int n) {
    // Sort the processes based on priority (in ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priorities[j] > priorities[j + 1]) {
                // Swap the processes
                int temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                // Swap the priorities
                temp = priorities[j];
                priorities[j] = priorities[j + 1];
                priorities[j + 1] = temp;

                // Swap the burst times
                temp = burstTimes[j];
                burstTimes[j] = burstTimes[j + 1];
                burstTimes[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time, turnaround time, average waiting time, and average turnaround time
    int waitingTime[n], turnaroundTime[n];
    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    waitingTime[0] = 0;
    turnaroundTime[0] = burstTimes[0];

    for (int i = 1; i < n; i++) {
        waitingTime[i] = turnaroundTime[i - 1];
        turnaroundTime[i] = waitingTime[i] + burstTimes[i];
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }

    // Display the schedule and performance metrics
    printf("\nProcess Schedule (Priority Scheduling):\n");
    printf("-----------------------------------------------------------\n");
    printf("Process ID | Priority | Burst Time | Waiting Time | Turnaround Time\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("   %2d      |    %2d    |     %2d      |        %2d      |     %2d      \n",
               processes[i], priorities[i], burstTimes[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("-----------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", avgWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime / n);
}

int main() {
    // Number of processes
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Arrays to store process details
    int processes[n];
    int priorities[n];
    int burstTimes[n];

    // Input process details
    printf("Enter Priority and Burst time for all : \n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("For P%d: ", i + 1);
        scanf("%d %d", &priorities[i], &burstTimes[i]);
    }

    // Perform Priority Scheduling and calculate performance metrics
    priorityScheduling(processes, priorities, burstTimes, n);

    return 0;
}
