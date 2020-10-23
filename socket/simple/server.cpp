#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>

#define PORT 8080

int main()
{
    int server_fd, new_scoket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    char *hello = "Hello from server";

    //Creating socket file descriptor
    if( ( server_fd = socket(AF_INET, SOCK_STREAM, 0) ) == 0 )
    {
        perror("Socket failes");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd,SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt)) )
    {
        perror("setsocketopt error");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);


    //bind sicketfd with port and address

    if( bind(server_fd, (struct sockaddr *)&address, sizeof(address))  < 0 )
    {
        perror("bind failes");
        exit(EXIT_FAILURE);
    }
 
    //listion
    if( listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //accept


if( (new_scoket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0 ) 
{
    perror("accept");
    exit(EXIT_FAILURE);
}

valread = read(new_scoket, buffer, 1024);
printf("%s\n", buffer);

send(new_scoket, hello, strlen(hello), 0); 

printf("hello messgae sent");

return 0;
}

