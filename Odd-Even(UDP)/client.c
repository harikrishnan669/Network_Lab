#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024
#define SIZE 5  // Change as needed

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    int numbers[SIZE];
    char results[SIZE][10];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    printf("Enter %d numbers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    sendto(sockfd, numbers, sizeof(numbers), 0, (struct sockaddr *)&server_addr, addr_len);

    recvfrom(sockfd, results, sizeof(results), 0, (struct sockaddr *)&server_addr, &addr_len);

    printf("\nResults:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d is %s\n", numbers[i], results[i]);
    }

    close(sockfd);
    return 0;
}
