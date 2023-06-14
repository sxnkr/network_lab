#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include <arpa/inet.h>
void main()
{
  int servsock,len;
  char buffer[1024];
  struct sockaddr_in clientaddr,servaddr;
  servsock=socket(AF_INET,SOCK_DGRAM,0);
  clientaddr.sin_family=AF_INET;
  clientaddr.sin_port=htons(2090);
  clientaddr.sin_addr.s_addr=INADDR_ANY;
 
 sendto(servsock,"Time",strlen("Time"),MSG_CONFIRM,(const struct sockaddr *)&clientaddr,sizeof(clientaddr));
 
  int i=recvfrom(servsock,buffer,1024,MSG_WAITALL,(struct sockaddr*)&clientaddr,&len);
   
  buffer[len]='\0';
  printf("received %s",buffer);
  
}

