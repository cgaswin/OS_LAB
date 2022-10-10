#include <stdio.h>

int main()
{
    int n, bt[20], wt[20], tat[20], p[20], i, j, sum = 0, temp;
    float wtavg, tatavg;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter process id: ");
        scanf("%d", &p[i]);

        printf("Enter burst time of the process: ");
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
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

    printf("Gantt Chart: ");
    sum += bt[0];
    printf("[ %d %d %d ] ", wt[0], p[0], sum);

    for (i = 1; i < n; i++)
    {
        sum += bt[i];
        printf("[ %d %d %d ] ", wt[i] + 1, p[i], sum);
    }

    printf("\nProcess\tBurst Time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %f\n", wtavg / n);
    printf("Average TurnAround Time: %f\n", tatavg / n);
}