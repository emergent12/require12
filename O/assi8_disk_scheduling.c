#include <stdio.h>
#include <math.h>

int n;
int refStr[20];
int head;
int tracks;

void sort()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (refStr[j + 1] < refStr[j])
            {
                int temp = refStr[j + 1];
                refStr[j + 1] = refStr[j];
                refStr[j] = temp;
            }
        }
    }
}

int sstf()
{
    int headSSTF = head;
    int pendingReqs = n;

    int finish[n];
    int indexWithShortest;
    int totalMovement = 0;

    for (int i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    printf("%d-->", headSSTF);

    while (pendingReqs > 0)
    {
        int minDiff = 9999;
        for (int i = 0; i < n; i++)
        {
            int currDiff = abs(headSSTF - refStr[i]);
            if (finish[i] == 0 && currDiff < minDiff)
            {
                minDiff = currDiff;
                indexWithShortest = i;
            }
        }
        finish[indexWithShortest] = 1;
        totalMovement += abs(headSSTF - refStr[indexWithShortest]);
        headSSTF = refStr[indexWithShortest];
        pendingReqs--;
        printf("%d-->", headSSTF);
    }

    return totalMovement;
}

int scan()
{

    int headScan = head;
    int totalMovement = 0;
    int direction; // 1 for right and 0 for left

    printf("\nEnter the direction: ");
    scanf("%d", &direction);

    sort(); // sorting the reqs

    int index = 0;
    int i = 0;
    while (headScan > refStr[i])
    {
        index++;
        i++;
    }

    if (direction == 1)
    {
        for (i = index + 1; i < n; i++)
        {
            printf("%d-->", headScan);
            totalMovement += abs(headScan - refStr[i]);
            headScan = refStr[i];
        }
        totalMovement += abs((tracks - 1) - headScan);
        headScan = tracks - 1;
        printf("%d-->", headScan);
        for (i = index; i >= 0; i--)
        {
            printf("%d-->", headScan);
            totalMovement += abs(headScan - refStr[i]);
            headScan = refStr[i];
        }
    }
    else
    {
        for (i = index; i >= 0; i--)
        {
            printf("%d-->", headScan);
            totalMovement += abs(headScan - refStr[i]);
            headScan = refStr[i];
        }
        printf("%d-->", headScan);
        totalMovement += abs(0 - headScan);
        headScan = 0;
        for (i = index + 1; i < n; i++)
        {
            printf("%d-->", headScan);
            totalMovement += abs(headScan - refStr[i]);
            headScan = refStr[i];
        }
    }

    return totalMovement;
}

int clook()
{

    int headClook = head;
    int totalMovement = 0;
    int direction; // 1 for right and 0 for left

    printf("\nEnter the direction: ");
    scanf("%d", &direction);

    sort(); // sorting the reqs

    int index = 0;
    int i = 0;
    while (headClook > refStr[i])
    {
        index++;
        i++;
    }

    if (direction == 1)
    {
        for (i = index + 1; i < n; i++)
        {
            printf("%d-->", headClook);
            totalMovement += abs(headClook - refStr[i]);
            headClook = refStr[i];
        }

        for (i = 0; i < index; i++)
        {
            printf("%d-->", headClook);
            totalMovement += abs(headClook - refStr[i]);
            headClook = refStr[i];
        }
    }
    else
    {
        for (i = index; i >= 0; i--)
        {
            printf("%d-->", refStr[i]);
            totalMovement += abs(headClook - refStr[i]);
            headClook = refStr[i];
        }

        for (i = n - 1; i >= index + 1; i--)
        {
            printf("%d-->", headClook);
            totalMovement += abs(headClook - refStr[i]);
            headClook = refStr[i];
        }
    }

    return totalMovement;
}

int main()
{

    printf("\nEnter the total tracks: ");
    scanf("%d", &tracks);

    printf("\nEnter the total number of requests: ");
    scanf("%d", &n);

    printf("\nEnter the page reference string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &refStr[i]);
    }

    printf("\nEnter the current head position: ");
    scanf("%d", &head);
    int choice;

    do
    {

        printf("\nEnter your choice: 1. SSTF 2. Scan 3. Clook --> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nSSTF\n");
            printf("\nTotal head movement with sstf: %d", sstf());
            break;

        case 2:
            printf("\nScan\n");
            printf("\nTotal head movement with scan: %d", scan());
            break;

        case 3:
            printf("\nC-look\n");
            printf("\nTotal head movement with clook: %d \n", clook());
            break;

        case 4:
            break;

        default:
            break;
        }
    } while (choice != 4);

    return 0;
}