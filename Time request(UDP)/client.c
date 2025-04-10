#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket < 0) { perror("Socket creation failed"); return -1; }

    struct sockaddr_in serverAddr = { .sin_family = AF_INET, .sin_port = htons(2136), .sin_addr.s_addr = inet_addr("127.0.0.36") };
    socklen_t addrSize = sizeof(serverAddr);
    char buffer[1024], username[100];

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    while (1) {
        sleep(1);
        sendto(clientSocket, username, strlen(username), 0, (struct sockaddr*)&serverAddr, addrSize);
        int recvlen = recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&serverAddr, &addrSize);
        if (recvlen > 0) {
            buffer[recvlen] = '\0';
            printf("Current Time from Server: %s\n", buffer);
        }
    }

    close(clientSocket);
    return 0;
}
