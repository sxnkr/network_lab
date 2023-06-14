#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include <arpa/inet.h>
#include<time.h>
void main()
{
	int servsock,len;
  	char buffer[1024];
  	char str[3];
  	int opt=1;
 	struct sockaddr_in clientaddr,servaddr;
  	servsock=socket(AF_INET,SOCK_DGRAM,0);
  	servaddr.sin_family=AF_INET;
  	servaddr.sin_port=htons(2040);
  	servaddr.sin_addr.s_addr=INADDR_ANY;
  	setsockopt(servsock, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt));
  	bind(servsock,(struct sockaddr*)&servaddr,sizeof(servaddr));  
  	int i;
	while(1)
	{
		i=recvfrom(servsock,buffer,1024,0,(struct sockaddr*)&clientaddr,&len);  
  		buffer[i]='\0';
  		printf("received %s\n",buffer);
  		if (strcmp(buffer,"stop")==0)
			break;
  		printf("Enter the message");
  		scanf("%s",str);  
 		int x= sendto(servsock,str,strlen(str),MSG_CONFIRM,(struct sockaddr *)&clientaddr,sizeof(clientaddr));
	}
	close(servsock);
}
