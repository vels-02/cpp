#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define SERVER_PORT 8080

int sock = 0, valread;
struct sockaddr_in serv_addr; 
char *hello = "Hi from client";
char buffer[1024] = {0};

    

int main()
{
    printf("client started ! \n");
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    //convert ipv4 and ipv6 text to buinary form
    if( inet_pton(AF_INET, "127.0.01", &serv_addr.sin_addr) < 0 )
    {
        perror("\nInvalid address/ address not supported");
        exit(EXIT_FAILURE);
    }

    //connect the server
    if(  connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 )
    {
        perror("\nConnection Failed !\n");
        exit(EXIT_FAILURE);
    }

    send(sock, hello, strlen(hello), 0) ;
    printf("Hello Msg sent\n") ;

    valread = read(sock, buffer , 1024);

    printf("%s\n", buffer);


}
