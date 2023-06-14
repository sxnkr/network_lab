#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include <arpa/inet.h>
void main()
{
	int servsock,len;
	char buffer[1024],str[1000];
	struct sockaddr_in clientaddr,servaddr;
	servsock=socket(AF_INET,SOCK_DGRAM,0);
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(2040);
	clientaddr.sin_addr.s_addr=INADDR_ANY;
	while(1)
	{
		printf("Enter the message to send");
		scanf("%s",str);
		sendto(servsock,str,strlen(str),MSG_CONFIRM,(const struct sockaddr *)&clientaddr,sizeof(clientaddr));
		if (strcmp(str,"stop")==0)
			break;
		int i=recvfrom(servsock,buffer,1024,MSG_WAITALL,(struct sockaddr*)&clientaddr,&len);

		buffer[i]='\0';
		printf("received %s",buffer);
	}
}
