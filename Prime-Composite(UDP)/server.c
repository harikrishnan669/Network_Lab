#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SIZE 5  // Change this as needed

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int numbers[SIZE];
    char results[SIZE][20];  

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));


    recvfrom(sockfd, numbers, sizeof(numbers), 0, (struct sockaddr *)&client_addr, &addr_len);


    for (int i = 0; i < SIZE; i++) {
        if (is_prime(numbers[i])) 
            strcpy(results[i], "Prime");
        else 
            strcpy(results[i], "Composite");
    }


    sendto(sockfd, results, sizeof(results), 0, (struct sockaddr *)&client_addr, addr_len);

    close(sockfd);
    return 0;
}
