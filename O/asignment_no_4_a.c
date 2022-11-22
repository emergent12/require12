
#include <stdio.h>
#include <stdlib.h>

// use of mutex lock  and semaphore
// x is used as a mutex lock to protect the critical section
int mutex = 1, full = 0, empty = 3, x = 0;

// wait(S) decreases the binary semaphore variable S to 0
//  so that no other process which is willing to enter into its critical section is allowed.
int wait(int s)
{
    return (--s);
}

// 12. signal(S) increases the binary semaphore variable S
//  to 1 so that other processes who are willing to enter into its critical section can now be allowed.
int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d", x);
    x--;
    mutex = signal(mutex);
}
int main()
{
    int n;

   
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full!!");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty!!");
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
