#include <stdio.h>

// program for round robin sheduling algorithm

void round_robin(int n, int at[], int bt[], int q)
{
    // tat = turn around time
    // ct = completion time
    // t = time variable for checking if process is completed or not
    int i, j, k, t = 0, wt[10], tat[10], ct[10], p[10], temp[10];
    // use of p is to store the process number and use of temp is to store the burst time of the process for further use
    // use of t is to store the total time of the process
    float awt = 0, atat = 0;
    for (i = 0; i < n; i++)
    {
        temp[i] = bt[i];
        p[i] = i + 1;
    }
    while (1)
    {
        int done = 1;
        for (i = 0; i < n; i++)
        {
            if (temp[i] > 0)
            {
                done = 0;
                if (temp[i] > q)
                {
                    t = t + q;
                    temp[i] = temp[i] - q;
                }
                else
                {
                    t = t + temp[i];
                    tat[i] = t - at[i];
                    wt[i] = tat[i] - bt[i];
                    temp[i] = 0;
                }
            }
        }
        if (done == 1)
        {
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        awt = awt + wt[i];
        atat = atat + tat[i];
    }
    awt = awt / n;
    atat = atat / n;
    printf("\nProcess\t\tarrival time\t\t burst time\t\t CT\t\t  turnaround time\t\t  waiting time\n ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i], at[i], bt[i], tat[i] + at[i], tat[i], wt[i]);
    }
    printf("Average waiting time: %f", awt);
    printf("\nAverage turnaround time: %f", atat);
}

int main()
{
    int n, i, j, temp, at[10], burst_time[10], q;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of the processes: \n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &burst_time[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &q);
    round_robin(n, at, burst_time, q);
    return 0;
}
