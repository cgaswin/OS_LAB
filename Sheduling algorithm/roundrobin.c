#include <stdio.h>

void main()
{
    int n, tempNumOfProcess, bt[20], temp[20], wt[20], tat[20], p[20], i = 0, j, timeQuantum, sum = 0, count;
    float tatavg, wtavg;

    printf("Enter number of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter process id: ");
        scanf("%d", &p[i]);

        printf("Enter burst time of the process: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);

    tempNumOfProcess = n;
    printf("Gantt Chart: ");
    for (sum = 0, i = 0; tempNumOfProcess != 0;)
    {
        if (temp[i] <= timeQuantum && temp[i] > 0)
        {
            printf("[ %d ", sum);
            sum += temp[i];
            printf("%d %d ] ", i + 1, sum);
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            printf("[ %d ", sum);
            temp[i] -= timeQuantum;
            sum += timeQuantum;
            printf("%d %d ] ", i + 1, sum);
        }
        if (temp[i] == 0 && count == 1)
        {
            tempNumOfProcess--;
            tat[i] = sum;
            wt[i] = sum - bt[i];
            tatavg += tat[i];
            wtavg += wt[i];
            count = 0;
        }

        if (i == n - 1)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }

    printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %f", wtavg / n);
    printf("Average TurnAround Time: %f", tatavg / n);
}