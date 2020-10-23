#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{

    int fd, retval; 
    char buffer[8] = "TESTDATA";
    fflush(stdin);

    //create the fifo (named pipe)
    retval = mkfifo("/tmp/velufifo", 0666);

    fd = open("/tmp/velufifo", O_WRONLY);

    write(fd, buffer, sizeof(buffer));

    close(fd);


    return 0;

}
