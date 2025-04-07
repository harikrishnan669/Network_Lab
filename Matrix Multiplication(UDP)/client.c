#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 2121
#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define size 2

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    printf("Socket created Successfully...\n");

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    int A[size][size], B[size][size], result[size][size];

    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    sendto(sockfd, A, sizeof(A), 0, (struct sockaddr *) &server_addr, addr_len);
    sendto(sockfd, B, sizeof(B), 0, (struct sockaddr *) &server_addr, addr_len);

    recvfrom(sockfd, result, sizeof(result), 0, (struct sockaddr *) &server_addr, &addr_len);

    printf("The resultant matrix is: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    close(sockfd);
    return 0;
}
