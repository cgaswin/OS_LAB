#include <stdio.h>

void main()
{
    int n, i, j, p[20], bt[20], wt[20], tat[20], sum = 0;
    float tatavg, wtavg;

    printf("Enter number of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter process id: ");
        scanf("%d", &p[i]);

        printf("Enter burst time of the process: ");
        scanf("%d", &bt[i]);
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("Gantt chart: ");
    printf("[ %d %d %d ] ", wt[0], p[0], tat[0]);

    for (i = 1; i < n; i++)
    {
        sum += tat[i];
        printf("[ %d %d %d ] ", wt[i] + 1, p[i], sum);
    }

    printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting time: %f\n", wtavg / n);
    printf("Average Turnaround time: %f\n", tatavg / n);
}