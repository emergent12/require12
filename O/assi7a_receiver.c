
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int count_char(char *str)
{
    int i, ch;
    i = 0;
    ch = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        {
            ch++;
        }
        i++;
    }
    return (ch);
}

int count_word(char *str)
{
    int i, wrd;
    i = 0;
    wrd = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            wrd++;
        }
        i++;
    }
    return (wrd);
}

int count_lines(char *str)
{
    int i, lines;
    i = 0;
    lines = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            lines++;
        }
        i++;
    }
    return (lines);
}

char *int_to_string(int num)
{
    char *str = (char *)malloc(10);
    sprintf(str, "%d", num);
    return (str);
}

int main()
{
    int fd1, fd2, n;
    char buff[100];
    char *str;
    char cha[50] = "character are: ";
    char words[50] = " and words are ";
    char lines[50] = " lines are :";
    // create fifo2
    mkfifo("fifo2", 0666);
    printf("fifo2 created\n");

    // read from fifo1
    fd1 = open("fifo1", O_RDWR);
    read(fd1, buff, 100);
    close(fd1);

    // write on fifo2
    fd2 = open("fifo2", O_RDWR);

    // count characters, words and lines
    int ch = count_char(buff);
    int wrd = count_word(buff);
    int line = count_lines(buff);

    // convert int to string
    char *ch_str = int_to_string(ch);
    char *wrd_str = int_to_string(wrd);
    char *line_str = int_to_string(line);

    strcat(cha, ch_str);
    strcat(cha, words);
    strcat(cha, wrd_str);
    strcat(cha, lines);
    strcat(cha, line_str);
    write(fd2, cha, 100);

    close(fd2);

    return 0;
}