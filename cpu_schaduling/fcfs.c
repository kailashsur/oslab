#include<stdio.h>
#define MAX 3

int findWT(int bt[], int wt[], int *total_wt){
    // for process 1 wt is 0
    wt[0] = 0;
    for(int i=1; i<MAX; i++){
        wt[i] = bt[i-1]+wt[i-1];
    }

    for(int i=0; i<MAX; i++){
        *total_wt = *total_wt+wt[i];
    }

    return *total_wt/MAX;
}

int findTAT(int tat[], int *total_tat, int bt[], int wt[]){
    for(int i=0; i<MAX; i++){
        tat[i] = wt[i]+bt[i];
    }
    for(int i=0; i<MAX; i++){
        *total_tat = *total_tat + tat[i];
    }

    return *total_tat/MAX;

}

int main(){
    int bt[MAX], wt[MAX], tat[MAX], total_wt=0, total_tat=0, avgTAT=0, avgWT=0;
    printf("Enter All process and Burst time \n");

    for(int i=0; i<MAX; i++){
        printf("Burst Time for P%d = ", i+1);
        scanf("%d", &bt[i]);
    }

    avgWT = findWT(bt, wt, &total_wt);
    avgTAT = findTAT(tat, &total_tat, bt, wt);

    printf("Ps \t BT \t WT \t TAT \n");

    for(int i=0; i<MAX; i++){
        printf("P%d", i+1);
        printf("\t %d", bt[i]);
        printf("\t %d", wt[i]);
        printf("\t %d \n", tat[i]);
    }

    
    printf("Avorage Turn Around time = %d\n", avgTAT);
    printf("Avorage Waiting time = %d\n", avgWT);
    return 0;
}