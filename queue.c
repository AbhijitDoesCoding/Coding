#include <stdio.h>

struct queue {
    int arrival_time;
    int execution_time;
    int wait_time;
    int turnaround_time;
    int pid;
};

void queuefill(struct queue queue[100], int m);
void display(struct queue queue[100], int m);

void main() {
    struct queue queue[100];
    int m;
    int inpflag = 1;
    
    do {
        printf("Enter number of processes:\n");
        scanf("%d", &m);
        
        for (int i = 0; i < m; i++) {
            printf("Inputs for Process %d\n", i);
            printf("Execution time:\n");
            scanf("%d", &queue[i].execution_time);
            printf("Arrival time:\n");
            scanf("%d", &queue[i].arrival_time);
            queue[i].pid = i;
        }
        
        queuefill(queue, m);
        
        printf("Do you want to exit?\n0.Exit\n1.Continue\n");
        scanf("%d", &inpflag);
        
    } while (inpflag);
}

void queuefill(struct queue queue[100], int m) {
    int total = queue[0].execution_time;
    int avg_turnaroundtime, avg_executiontime = 0;
    int total_turnaroundtime = queue[0].execution_time;
    int total_executiontime = queue[0].execution_time;
    
    queue[0].wait_time = 0;
    queue[0].turnaround_time = queue[0].execution_time;
    
    for (int i = 1; i < m; i++) {
        if (total == queue[i].arrival_time) {
            queue[i].wait_time = 0;
        } else if (total > queue[i].arrival_time) {
            queue[i].wait_time = total - queue[i].arrival_time;
        } else if (total < queue[i].arrival_time) {
            queue[i].wait_time = 0;
            int idle = queue[i].arrival_time - total;
            total += idle;
        }
        
        total += queue[i].execution_time;
        queue[i].turnaround_time = queue[i].wait_time + queue[i].execution_time;
        
        total_turnaroundtime += queue[i].turnaround_time;
        total_executiontime += queue[i].execution_time;
    }
    
    avg_turnaroundtime = total_turnaroundtime / m;
    avg_executiontime = total_executiontime / m;
    
    display(queue, m);
    
    printf("Avg turnaround time: %d\n", avg_turnaroundtime);
    printf("Avg execution time: %d\n", avg_executiontime);
    printf("Total turnaround time: %d\n", total_turnaroundtime);
    printf("Total execution time: %d\n", total_executiontime);
}

void display(struct queue queue[100], int m) {
    printf("Pid\tET\tWT\tAT\tTAT\n");
    for (int i = 0; i < m; i++) {
        printf("%d \t %d \t %d \t %d \t %d\n", 
               queue[i].pid, 
               queue[i].execution_time, 
               queue[i].wait_time, 
               queue[i].arrival_time, 
               queue[i].turnaround_time);
    }
}
