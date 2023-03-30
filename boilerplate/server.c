#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
void main()
{
	int serv,client,len;
	char buffer[1024];
	struct sockaddr_in servaddr;
	serv=socket(AF_INET,SOCK_STREAM,0);
	servaddr.sin_port=htons(1028);
	servaddr.sin_addr.s_addr=inet_addr("172.20.3.51");
 	servaddr.sin_family=AF_INET;
 	bind(serv,(struct sockaddr*)&servaddr, sizeof(servaddr));
 	listen(serv,3);
 	client=accept(serv,(struct sockaddr*)&client,&len);
 	while(1)
 	{
		int n=read(client,buffer,1024);
 		buffer[n]='\0';
 		printf("received data %s",buffer);
 		printf("enter the data to sent");
 		scanf("%s",buffer);
 		send(client,buffer,strlen("buffer"),0);
 		if(strcmp(buffer,"stop")==0)
			break;
	}
}
