#include <stdio.h>
#include <conio.h>

// bankers algorithm

void bankers(int n, int m, int alloc[][m], int max[][m], int avail[m])
{
    int i, j, y, k, x = 0;
    // f is used to check whether the process is completed or not f[i]=0 means process is not completed
    int f[n], ans[n], ind = 0;
    // ans is used to store the safe sequence
    // loop to initialize the f array to 0
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    // need matrix is used to store the need of each process
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    // 
    for(k=0;k<n;k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    // if the need of the process is greater than the available resources

                    if (need[i][j] > avail[j])
                    {
                        // set the flag to 1
                        flag = 1;
                        break;
                    }
                }
                // if the flag is 0 then the process is completed
                if (flag == 0)
                {
                    // add the process to the safe sequence
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                    {
                        /// add the allocated resources to the available resources
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    printf("Following is the SAFE Sequence \n");
    for (i = 0; i < n - 1; i++)
    {
        printf(" P%d ->", ans[i]);
    }
    printf(" P%d", ans[n - 1]);
}

// main function
int main()
{
    int n, m, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], avail[m];
    printf("Enter allocation matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter max matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter available matrix: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    bankers(n, m, alloc, max, avail);
    return 0;
}

// second code

// #include <stdio.h>
// #include <conio.h>
// int main()
// {
//     int Max[10][10], need[10][10], alloc[10][10], avail[10],
//         completed[10], safeSequence[10];
//     int p, r, i, j, process, count;
//     count = 0;
//     printf("Enter the no of processes : ");
//     scanf("%d", &p);
//     for (i = 0; i < p; i++)
//         completed[i] = 0;
//     printf("\n\nEnter the no of resources : ");
//     scanf("%d", &r);
//     printf("\n\nEnter the Max Matrix for each process : ");
//     for (i = 0; i < p; i++)
//     {
//         printf("\nFor process %d : ", i + 1);
//         for (j = 0; j < r; j++)
//             scanf("%d", &Max[i][j]);
//     }
//     printf("\n\nEnter the allocation for each process : ");
//     for (i = 0; i < p; i++)
//     {
//         printf("\nFor process %d : ", i + 1);
//         for (j = 0; j < r; j++)
//             scanf("%d", &alloc[i][j]);
//     }
//     printf("\n\nEnter the Available Resources : ");
//     for (i = 0; i < r; i++)
//         scanf("%d", &avail[i]);
//     for (i = 0; i < p; i++)
//         for (j = 0; j < r; j++)
//             need[i][j] = Max[i][j] - alloc[i][j];
//     do
//     {
//         printf("\n Max matrix:\tAllocation matrix:\n");
//         for (i = 0; i < p; i++)
//         {
//             for (j = 0; j < r; j++)
//                 printf("%d ", Max[i][j]);
//             printf("\t\t");
//             for (j = 0; j < r; j++)
//                 printf("%d ", alloc[i][j]);
//             printf("\n");
//         }
//         process = -1;
//         for (i = 0; i < p; i++)
//         {
//             if (completed[i] == 0) // if not completed
//             {
//                 process = i;
//                 for (j = 0; j < r; j++)
//                 {
//                     if (avail[j] < need[i][j])
//                     {
//                         process = -1;
//                         break;
//                     }
//                 }
//             }
//             if (process != -1)
//                 break;
//         }
//         if (process != -1)
//         {
//             printf("\nProcess %d runs to completion!",
//                    process + 1);
//             safeSequence[count] = process + 1;
//             count++;
//             for (j = 0; j < r; j++)
//             {
//                 avail[j] += alloc[process][j];
//                 alloc[process][j] = 0;
//                 Max[process][j] = 0;
//                 completed[process] = 1;
//             }
//         }
//     } while (count != p && process != -1);
//     if (count == p)
//     {
//         printf("\nThe system is in a safe state!!\n");
//         printf("Safe Sequence : < ");
//         for (i = 0; i < p; i++)
//             printf("%d ", safeSequence[i]);
//         printf(">\n");
//     }
//     else
//         printf("\nThe system is in an unsafe state!!");
//     getch();
// }
