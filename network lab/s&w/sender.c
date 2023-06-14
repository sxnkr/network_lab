#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <arpa/inet.h>
struct packet
{	int data;
	int seq;
};
void main()
{
  int sender,len,i,r,flag;
  int ack;
  char buffer[1024];
  int opt=1;
  struct packet p;
  struct sockaddr_in receiver,sendadr;
  sender=socket(AF_INET,SOCK_STREAM,0);
  receiver.sin_family=AF_INET;
  receiver.sin_port=htons(2065);
  receiver.sin_addr.s_addr=inet_addr("127.0.0.1");
  if( connect(sender,(struct sockaddr*)&receiver,sizeof(receiver))>0)
    printf("connected");


 int x= send(sender,"hai",strlen("hai"),0);
 
  printf("sent hai\n");
  i=read(sender,buffer,1023);
  buffer[i]='\0';
  printf(" Received %s\n",buffer);
	i=1;
	flag=0;
  while(i<10)
  {	if (flag==0)
	{printf("Sender : Enter the data to sent:");
	scanf("%d",&p.data);
	p.seq=i;
	}
  	send(sender,(char*)&p,sizeof(p),0);
	printf("send packet with data %d with seq no: %d\n",p.data,p.seq);
	r=read(sender,(char*)&ack,sizeof(ack));
	 if(ack==0 || ack==1)
             { sleep(3); printf("\n\ntime expired resending the packet\n");flag=1;}
	else
		{ printf("Received ack\n"); i++;flag=0;}
}
close(sender);
}
	
	
	
	
	
	
	
	
	
	
