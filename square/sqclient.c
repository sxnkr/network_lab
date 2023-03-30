#include<stdio.h>
#include <unistd.h>
#include<string.h>
#include <netinet/in.h>
 #include <arpa/inet.h>
int main()
{   int client;
   struct sockaddr_in serveraddr;
  char buffer[1024];
  char s[1024];
   int port=1026;
    client=socket(AF_INET,SOCK_STREAM,0);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=inet_addr("172.20.3.51");
    serveraddr.sin_port = htons( port );
   if(connect(client,(struct sockaddr*)&serveraddr,sizeof(serveraddr))>0)
    printf("connected");

    while(1)
	{ printf("Enter the Data to send ");
	 scanf("%s",s);
	send(client,s,strlen(s),0);
        if (strcmp(s,"stop")==0)
          break;
       int n=read(client,buffer,1023);
     buffer[n]='\0';
    
    printf("Received %s\n",buffer);
}

}
