#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include <arpa/inet.h>
#include<time.h>
void main()
{
  int servsock,len;
  char buffer[1024];
  time_t tim;
  
  struct sockaddr_in clientaddr,servaddr;
  servsock=socket(AF_INET,SOCK_DGRAM,0);
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=htons(2090);
  servaddr.sin_addr.s_addr=INADDR_ANY;
  bind(servsock,(struct sockaddr*)&servaddr,sizeof(servaddr));
 
  int i=recvfrom(servsock,(char *)buffer,1024,MSG_WAITALL,(struct sockaddr*)&clientaddr,&len);
  buffer[len]='\0';
  printf("received %s",buffer);
  if (strcmp(buffer,"Time")==0)
 {  
   time(&tim);
    
  sendto(servsock,ctime(&tim),strlen(ctime(&tim)),MSG_CONFIRM,( struct sockaddr *)&clientaddr,len);
}
}

