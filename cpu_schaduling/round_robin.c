#include <stdio.h>

// Function to implement Round Robin scheduling algorithm
void roundRobin(int processes[], int n, int burst_time[], int quantum) {
    int waiting_time = 0, turnaround_time = 0;
    int remaining_time[n];
    
    // Copy burst times to remaining_time array
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }

    int time = 0; // Current time

    // Continue until all processes are executed
    while (1) {
        int done = 1; // Assume all processes are done

        // Traverse all processes
        for (int i = 0; i < n; i++) {
            // If process is not done
            if (remaining_time[i] > 0) {
                done = 0; // Set done to false

                // Process quantum or remaining time, whichever is smaller
                int execute_time = (remaining_time[i] > quantum) ? quantum : remaining_time[i];

                // Update remaining time for the process
                remaining_time[i] -= execute_time;

                // Update total waiting time and turnaround time
                waiting_time += time;
                time += execute_time;
                turnaround_time += time;

                printf("Process %d executes for %d units. Remaining time: %d\n", i + 1, execute_time, remaining_time[i]);
            }
        }

        // Break the loop if all processes are done
        if (done == 1)
            break;
    }

    // Calculate average waiting time and turnaround time
    float avg_waiting_time = (float)waiting_time / n;
    float avg_turnaround_time = (float)turnaround_time / n;

    // Print average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    // Input burst time for each process
    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }

    int quantum;

    // Input time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Call the roundRobin function
    roundRobin(processes, n, burst_time, quantum);

    return 0;
}
