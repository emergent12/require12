// B. Implement the C program in which main program accepts an array. Main program uses the FORK
// system call to create a new process called a child process. Parent process sorts an array and passes
// the sorted array to child process through the command line arguments of EXECVE system call. The
// child process uses EXECVE system call to load new program which display array in reverse order


// reverse the array receviced from parent process

// Path: os\assi2b2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{

    printf("Child process is running with pid: %d\n", getpid());
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = atoi(argv[i]);
    }

    printf("Reverse array: ");
    for (int i = argc - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
}
