#include <stdio.h>

// Function to implement First-Come-First-Serve scheduling algorithm
void fcfs(int processes[], int n, int burst_time[]) {
    int waiting_time = 0, turnaround_time = 0;

    // Calculate waiting time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time += burst_time[i];
        waiting_time += turnaround_time - burst_time[i];
        printf("Process %d executes. Waiting time: %d, Turnaround time: %d\n", processes[i], waiting_time - burst_time[i], turnaround_time);
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

    // Call the fcfs function
    fcfs(processes, n, burst_time);

    return 0;
}
