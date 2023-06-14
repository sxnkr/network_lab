#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <arpa/inet.h>
#include<stdlib.h>
struct packet
{	int data;
	int seq;
};
void main()
{
	  int receiver,sende,len,i,r,x;
	  int ack;
	  char buffer[1024];
	  int opt=1;
	  struct packet p;
	  struct sockaddr_in sender,receiv;
	  receiver=socket(AF_INET,SOCK_STREAM,0);
	  receiv.sin_family=AF_INET;
	  receiv.sin_port=htons(2065);
	  receiv.sin_addr.s_addr=inet_addr("127.0.0.1");
	  setsockopt(receiver, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,
		               sizeof(opt));
	  bind(receiver,(struct sockaddr*)&receiv,sizeof(receiv));
	  listen(receiver,3);
	  sende=accept(receiver,(struct sockaddr*)&sender,&len);
	  
	  i= read(sende,buffer,1023);
	  buffer[i]='\0';
	  printf("Received %s\n",buffer);
	  send(sende,"hai",strlen("hai"),0);
	  printf("sent hai\n");
	  i=1;
	  while(i<=10)
	  {	
	  		r=read(sende,(char*) &p,sizeof(p));
			x=rand()%6;
			send(sende,(char *)&x,sizeof(x),0);
		    if(x==0)
					printf("Received Packet data %d with seq %d sending ack\n\n\n packet duplicated: ",p.data,p.seq);
		    else if (x!=1)	
			{	 i++;	printf("Received Packet data %d with seq %d sending ack\n",p.data,p.seq);}

	  }       
close(receiver);
}
