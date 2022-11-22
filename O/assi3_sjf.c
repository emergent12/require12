#include <stdio.h>

// program for sjf scheduling algorithm pre-emptive

// float sjf()

int main()
{
    int n, i, j, temp, at[10], burst_time[10], waiting_time[10], turnaroundtime[10], ct[10], p[10], t = 0;
    float awaiting_time = 0, atat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of the processes: \n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &burst_time[i]);
       // use of p array to store the process number
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (burst_time[i] > burst_time[j])
            {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (at[i] > t)
        {
            t = at[i];
        }
        t = t + burst_time[i];
        ct[i] = t;
        turnaroundtime[i] = ct[i] - at[i];
        waiting_time[i] = turnaroundtime[i] - burst_time[i];
        awaiting_time = awaiting_time + waiting_time[i];
        atat = atat + turnaroundtime[i];
    }
    awaiting_time = awaiting_time / n;
    atat = atat / n;
    printf("\nProcess\t\tarrival time\t\t burst time\t\t CT\t\t  turnaround time\t\t  waiting time\n ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i], at[i], burst_time[i], ct[i], turnaroundtime[i], waiting_time[i]);
    }
    printf("Average waiting time: %f", awaiting_time);
    printf("\nAverage turnaround time: %f", atat);
    return 0;
}

