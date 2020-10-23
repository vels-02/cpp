#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros  

#define TRUE   1  
#define FALSE  0 

#define PORT 8080
#define MAX_CLIENTS 10
int main()
{
    int server_fd, new_scoket, valread, client_socket[MAX_CLIENTS], activity, sd;
    int max_sd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen;
    char buffer[1024] = {0};

    //set of socket descriptors  
    fd_set readfds;  

    char *hello = "Hello from server";

    for(int i =0; i < MAX_CLIENTS; ++i)
    {
        client_socket[i] = 0;
    }

    //Creating socket file descriptor
    if( ( server_fd = socket(AF_INET, SOCK_STREAM, 0) ) == 0 )
    {
        perror("Socket failes");
        exit(EXIT_FAILURE);
    }

     //set master socket to allow multiple connections
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

    // "Waiting for connections"
    //accept
    addrlen = sizeof(address);

    while(TRUE)
    {
        //clear the socket set  
        FD_ZERO(&readfds);

        //add master socket to set  
        FD_SET(server_fd, &readfds);   
        max_sd = server_fd;  

        //add chile sockets to set
        for(int i = 0; i < MAX_CLIENTS; i++)
        {
            sd =  client_socket[i];

            //if valid socket descriptor then add to read list  
            if(sd > 0)
                FD_SET( sd , &readfds); 

            //highest file descriptor number, need it for the select function  
            if(sd > max_sd)   
                max_sd = sd;   

            activity = select(max_sd+1, &readfds, NULL, NULL, NULL);

            if(activity < 0  && (errno!=EINTR))  
            {
                perror("select error");
            }

            //If something happened on the master socket ,  
            //then its an incoming connection 

            if (FD_ISSET(server_fd, &readfds)) 
            {
                if( (new_scoket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0 ) 
                {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }

            }
             //inform user of socket number - used in send and receive commands  
            printf("New connection , socket fd is %d , ip is : %s , port : %d  \n" , new_scoket , 
            inet_ntoa(address.sin_addr) , ntohs (address.sin_port));   

            if ( (send(new_scoket, hello, strlen(hello), 0)) != strlen(hello) )
            {
                perror("send");
            }
            puts("Welcome message sent successfully");   

            //add new socket to array of sockets  
            for (i = 0; i < MAX_CLIENTS; i++)   
            {   
                //if position is empty  
                if( client_socket[i] == 0 )   
                {   
                    client_socket[i] = new_scoket;   
                    printf("Adding to list of sockets as %d\n" , i);   
                         
                    break;   
                }   
            }   
        }
   
        //else its some IO operation on some other socket 
        for (int i = 0; i < MAX_CLIENTS; i++)   
        {
            sd = client_socket[i];  
            if (FD_ISSET( sd , &readfds))   
            {   
                //Check if it was for closing , and also read the  
                //incoming message  
                if ((valread = read( sd , buffer, 1024)) == 0)   
                {   
                                        //Somebody disconnected , get his details and print  
                    getpeername(sd , (struct sockaddr*)&address ,
                        (socklen_t*)&addrlen);   
                    printf("Host disconnected , ip %s , port %d \n" ,  
                          inet_ntoa(address.sin_addr) , ntohs(address.sin_port));   
                         
                    //Close the socket and mark as 0 in list for reuse  
                    close( sd );   
                    client_socket[i] = 0;   
                }  
                //Echo back the message that came in  
                else 
                {   
                    //set the string terminating NULL byte on the end  
                    //of the data read  
                    buffer[valread] = '\0';   
                    send(sd , buffer , strlen(buffer) , 0 );   
                }   
            } 
        }
    }   
    return 0;
}

