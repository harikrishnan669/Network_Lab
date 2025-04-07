#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<ctype.h>
#include<arpa/inet.h>
#define MAX 80
#define PORT 4000

#define SA struct sockaddr
#define SAI struct sockaddr_in
int isnumber(char* str)
{
   for(int i =0;str[i]!='\0';i++)
   {
	if(!isdigit(str[i])&&str[i]!='\n')
		return 0;
   }
   return 1;
}
void factors(int num,char* result)
{
   strcpy(result,"Factors are: ");
   char temp[20];
   for(int i=1;i<=num;i++)
   {
	if(num%i==0)
	{
	   sprintf(temp,"%d",i);
	   strcat(result,temp);
	   strcat(result,",");
	}
   }
}
int isprime(int num)
{
   if(num<=1)return 0;
   for(int i=2;i*i <= num;i++)
   {
 	if(num%i==0)return 0;
   }
   return 1;
}


void chat(int sockfd,SAI client)
{
   printf("\nServer is ready..............\n");
   char buff[MAX],result[MAX];
   int n,len=sizeof(client);
   while(1)
   {
        bzero(buff,sizeof(buff));
	recvfrom(sockfd,buff,sizeof(buff),0,(SA*)&client,(socklen_t*)&len);
        printf("\nClient:%s",buff);
        n=0;
	if(isnumber(buff))
        {
	   int num=atoi(buff);
 	   if(isprime(num))
		{
			sprintf(result,"%d is a prime.\n",num);
		}
	   else
	   {
		factors(num,result);
	   }
	}
        else
	{
	   strcpy(result,"Invalid input.");
	}
        //while((buff[n++]=getchar())!='\n');
        sendto(sockfd,result,sizeof(result),0,(SA*)&client,len);
        if(strncmp(buff,"exit",4)==0)
        {
           printf("Server has exited the chat.......\n");
           break;

        }
   }
}
int main()
{
   SAI server,client;
   int sockfd;
   sockfd=socket(AF_INET,SOCK_DGRAM,0);
   server.sin_family=AF_INET;
   server.sin_addr.s_addr=htonl(INADDR_ANY);
   server.sin_port=htons(PORT);
   if((bind(sockfd,(SA*)&server,sizeof(server)))==0)
	printf("Socket Successfully Binded.\n");
   chat(sockfd,client);
 return 0;
}
