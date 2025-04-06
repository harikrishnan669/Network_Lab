#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 2121
#define BUFFER_SIZE 1024
#define size 2

void multiply_matrix(int A[size][size],int B[size][size],int result[size][size])
{
  for(int i=0;i<size;i++)
  {
   for(int j=0;j<size;j++)
   {
     result[i][j]=0;
    for(int k=0;k<size;k++)
    {
      result[i][j]+=A[i][k]*B[k][j];
    }
   }
  }
}

int main()
{
int sockfd;
struct sockaddr_in server_addr,client_addr;
socklen_t addr_len=sizeof(client_addr);

sockfd=socket(AF_INET,SOCK_DGRAM,0);
server_addr.sin_family=AF_INET;
server_addr.sin_addr.s_addr=INADDR_ANY;
server_addr.sin_port=htons(PORT);
bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));

int A[size][size],B[size][size],result[size][size];

recvfrom(sockfd,A,sizeof(A),0,(struct sockaddr*)&client_addr,&addr_len);
recvfrom(sockfd,B,sizeof(B),0,(struct sockaddr*)&client_addr,&addr_len);

sendto(sockfd,result,sizeof(result),0,(struct sockaddr*)&client_addr,addr_len);
close(sockfd);
return 0;
}
