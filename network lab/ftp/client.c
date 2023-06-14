#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
void main()
{
	int client;
	char buffer[1024];
	
	client=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("192.168.1.139"); 
	servaddr.sin_port=htons(1050);
	
	if(connect(client,(struct sockaddr*)&servaddr,sizeof(servaddr))>-1)
	   printf("connected\n");
	else
	   printf("not connected");  
	printf("\nEnter file name to send:");
	scanf("%s",buffer);
	send(client,buffer,strlen(buffer),0);
		
	while(1)
	{
		int n= read(client,buffer,1024);
		if(n==0)
		break;
		buffer[n]='\0';
	 	printf("%s\n",buffer);
	 }
	 close(client);
}
	 
	 
	 
	 

