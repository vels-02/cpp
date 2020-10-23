#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int  main()
{
    int fd, retval; 
    char buffer[8] ;
   
    //open read only
    fd = open("/tmp/velufifo", O_RDONLY);

    retval = read(fd, buffer, sizeof(buffer));

    fflush(stdin);

    write(1, buffer, sizeof(buffer));

    close(fd);
}
