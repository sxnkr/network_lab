#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
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
	int n= read(sqclient,buffer,1023);
	int x;
	buffer[n]='\0';
	printf("received %s\n",buffer);
        if (strcmp(buffer,"stop")==0)
	   break;
	else
	{
	 sscanf(buffer,"%d",&x);
	 x=x*x;
  	 sprintf(buffer,"%d",x);	
 	 send(sqclient,buffer,strlen(buffer),0);
 	}
  }
	
	
}
  
  //accept
  
  //if stop break
  
  //else writ to 
  
  //sscanf(buffer,"%d",&x);
  
  //sprint(buffer,"%d",x);
  
  //send(client,buffer,strlen(buffer,0));
  
  
  

