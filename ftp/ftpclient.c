#include<stdio.h>
#include <unistd.h>
#include<string.h>
#include <netinet/in.h>
 #include <arpa/inet.h>
int main()
{   
   int client;
   struct sockaddr_in serveraddr;
   char buffer[1024];
   char s[1024];
   int port=1026;
   client=socket(AF_INET,SOCK_STREAM,0);
   serveraddr.sin_family=AF_INET;
   serveraddr.sin_addr.s_addr=inet_addr("172.20.3.52");
   serveraddr.sin_port = htons( port );
   connect(client,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
   printf("enter the filename to be send: ");
   scanf("%s",buffer);
   send(client,buffer,strlen(buffer),0);
   while(1)
   {
     int n =read(client,buffer,1024);
     
     if(n==0)
     {
       break;
     }
     buffer[n]='\0';
     printf("Recieved..%s",buffer);
   }
   close(client);
}
