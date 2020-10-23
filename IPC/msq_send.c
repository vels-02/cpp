#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

struct msgbuf
{
    long mtype;
    char msgtxt[200];
};


int main()
{

    struct msgbuf msg;
    
    int msgid;
    key_t key;

    if( (key = ftok("3_msgsnd.c",'b')) == -1)
    {
        perror("key");
        exit(EXIT_FAILURE);
    }
    
    if( (msgid = msgget(key,0644 | IPC_CREAT)) == -1)
    {
        perror("Message ID");
        exit(EXIT_FAILURE);

    }
    printf("\nthe msgid is : %d\n", msgid);

     printf("\nEnter the exit : ");

     msg.mtype = 1;

     while(gets(msg.msgtxt),!feof(stdin))

    if(msgsnd(msgid, &msg, sizeof(msg),0) == -1 )
    {
        perror("msgsend");
        exit(1);
    }

    if(msgctl(msgid, IPC_RMID,NULL) == -1)
    {
        perror("msg send");
        exit(1);
    }

    return 0;
}
