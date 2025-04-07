#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SIZE 5  // Change as needed

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int numbers[SIZE];
    char results[SIZE][10];  // Array to store "Even" or "Odd"

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Socket created Successfully...\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Binding successfully created\n");

    recvfrom(sockfd, numbers, sizeof(numbers), 0, (struct sockaddr *)&client_addr, &addr_len);

    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] % 2 == 0) 
            strcpy(results[i], "Even");
        else 
            strcpy(results[i], "Odd");
    }

    sendto(sockfd, results, sizeof(results), 0, (struct sockaddr *)&client_addr, addr_len);

    close(sockfd);
    return 0;
}
