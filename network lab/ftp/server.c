#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
    int serv,len,client;
	char buffer[1024];
	struct sockaddr_in servaddr,clientaddr;
	serv=socket(AF_INET,SOCK_STREAM,0);
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("192.168.1.139");	
	servaddr.sin_port=htons(1050);
	
	bind(serv,(struct sockaddr*)&servaddr,sizeof(servaddr));
	listen(serv,3);
	client=accept(serv,(struct sockaddr*)&clientaddr,&len);  
	
	
	 	int n= read(client,buffer,1024);
	 	buffer[n]='\0';
	 	printf(" %s\n",buffer);
	 	FILE *fp;
	 	fp=fopen(buffer,"r");
	 	if(fp==NULL)
	 		send(client,"File not present",strlen("File not present"),0);
	 	else
	 	{
	 		while(fgets(buffer,1024,fp)!=NULL)
	 			send(client,buffer,strlen(buffer),0);
	 	}
	 close(serv);
}
	 
	 
	 
