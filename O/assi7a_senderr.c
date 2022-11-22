// Inter process communication in Linux using fifos

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// FIFOS: Full duplex communication between two independent processes. First process accepts
// sentences and writes on one pipe to be read by second process and second process counts number of
// characters, number of words and number of lines in accepted sentences, writes this output in a text file
// and writes the contents of the file on second pipe to be read by first process and displays onstandard
// output.

// first process

int main()
{
    int fd1, fd2, n;
    char buff[100];

    // create fifo1
    mkfifo("fifo1", 0666);
    mkfifo("fifo2",0666);
    printf("fifo1 created\n");
    printf("Enter string to write :");
    fgets(buff, 100, stdin);

    // write on fifo1
    fd1 = open("fifo1", O_RDWR);
    write(fd1, buff, 100);
    close(fd1);

    // read from fifo2
    fd2 = open("fifo2", O_RDWR);
    read(fd2, buff, 100);
    printf("printing data received from fifo2 %s\n", buff);
    close(fd2);

    return 0;
}
