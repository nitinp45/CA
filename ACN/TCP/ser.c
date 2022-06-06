#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>


int main()
{
    int srsock, nsock, cnt;
    char msgrcv[10];

    struct sockaddr_in ser_addr;
    struct sockaddr_in *claddr;

    int lencladdr;
    	//1 socket=Create a new communication endpoint
    srsock= socket(AF_INET, SOCK_STREAM,0);
    if(srsock==-1)
    {
        printf("Could not create socket...");
        exit(0);
    }

    ser_addr.sin_family = AF_INET;
    // ser_addr 
    ser_addr.sin_port = htons(5000);
    ser_addr.sin_addr.s_addr = inet_addr("192.168.125.188");

	//3 bind= Attach a local address to a socket
    bind(srsock,(struct sockaddr*)&ser_addr,sizeof(ser_addr));
    claddr = malloc(sizeof(ser_addr));
    printf("socket binded....\n");
    printf("Server address: %s\n", inet_ntoa(ser_addr.sin_addr));

	//4 listen= Announce willingness to accept connection
    listen(srsock,5);

    printf("Waiting for Connection..\n");

	//5 accept=Block caller until a connection request
    nsock = accept(srsock,(struct sockaddr*)claddr, &lencladdr);

    printf("Client connection...\n");
    printf("Client address: %s\n", inet_ntoa(claddr->sin_addr));

    //scanf("%d",&cnt);

	//6 recv= Recive some data over the connection
    cnt = recv(nsock,msgrcv,5,0);
    printf("recived %d bytes\n",cnt);
    printf("Message Recived: %s\n",msgrcv);
    printf("Sending recived data.....\n");

	//6
    char senddata[4];	
    printf("Enetr the Data: ");
    scanf("%d",senddata);
    cnt = send(nsock,senddata[4],6,0);

    printf("Bytes Send: %d \n",cnt);

    return (1);
}

 
