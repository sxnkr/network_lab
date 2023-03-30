#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<math.h>
#include<stdlib.h>
int main()
{
  int sqserver,sqclient;
  char buffer[1024];
  char s[1024];
  int PORT=1026;
  struct sockaddr_in servaddr,clientaddr;
  int addrlen = sizeof(clientaddr);
  sqserver=socket(AF_INET,SOCK_STREAM,0);
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("172.20.3.51");
  servaddr.sin_port = htons( PORT );
  int b=bind(sqserver,(struct sockaddr*)&servaddr,sizeof(servaddr));
  listen(sqserver,3);
  sqclient=accept(sqserver,(struct sockaddr*)&clientaddr,&addrlen);
  printf("connected");
  while(1)
  {
	int n = read(sqclient,buffer,1023);
	int x;
	buffer[n]='\0';
	printf("received %s\n",buffer);
        if (strcmp(buffer,"stop")==0)
	{
		break;
	}
	else
	{
		sscanf(buffer,"%d",&x);
		int flag=1;
		for(int i=2;i<x;i++)
		{
			if (x % i == 0)
			{
				flag=0;
				break;
			}
		}
		if(x<=1)
		{
			flag=0;
		}
		if(flag==1)
		{
			printf("%d is a prime number\n",x);
		}
		else
		{
			printf("%d is not  a prime number\n",x);
		}
		sprintf(buffer,"%d",x);
		send(sqclient,buffer,strlen(buffer),0);
	}
  }
}
