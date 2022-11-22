
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

// main program

int main(int argc, char *argv[])
{

    // reverse the array
    int i;

    printf("Reversed array using execv: ");
    for (i = argc - 1; i >= 0; i--)
    {
        printf("%s ", argv[i]);
    }
}