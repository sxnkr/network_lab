#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
int main()
{
  int server,client;
  char buffer[1024];
  char s[1024];
  int PORT=1026;
  struct sockaddr_in servaddr,clientaddr;
  int addrlen = sizeof(clientaddr);
  server=socket(AF_INET,SOCK_STREAM,0);
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("172.20.3.51");
  servaddr.sin_port = htons( PORT );
  int b=bind(server,(struct sockaddr*)&servaddr,sizeof(servaddr));
  listen(server,3);
  client=accept(server,(struct sockaddr*)&clientaddr,&addrlen);
  int n= read(client,buffer,1024);
  buffer[n]='\0';
  printf("file name recieved is %s",buffer);
  FILE *fp;
  fp=fopen(buffer,"r");
  if(fp==NULL)
  {
    send(client,"file not present",strlen("file not present"),0);
  }
  else
  {
    while(fgets(buffer,1024,fp) != NULL)
    {
      send(client,buffer,strlen(buffer),0);
    }
  }
  fclose(fp);
  close(client);
  close(server);
  
}

