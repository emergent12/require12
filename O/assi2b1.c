#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char *argv[])
{
    int n;
    char *str[10];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("fork creation failed");
    }
    else if (pid > 0)
    {
        printf("Parent process is running with pid: %d\n", getpid());
        quickSort(arr, 0, n - 1);
        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // assign null to string array
        for (int i = 0; i < 10; i++)
        {
            str[i] = NULL;
        }
        
        // convert integer array to string array
        for (int i = 0; i < n; i++)
        {
            str[i] = (char *)malloc(10 * sizeof(char));
            sprintf(str[i], "%d", arr[i]);
        }

        execv("./assi2b2", str);
        printf("execve not called\n");
    }
}
