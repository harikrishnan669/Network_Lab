#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int socket;
    char username[100];
    struct sockaddr_in clientAddr;
    socklen_t addrSize;
} Client;

void* handle_client(void* arg) {
    Client* client = (Client*)arg;
    char timeData[128];
    time_t current = time(NULL);
    strftime(timeData, sizeof(timeData), "%d-%m-%Y %H:%M:%S", localtime(&current));
    sendto(client->socket, timeData, strlen(timeData), 0, (struct sockaddr*)&client->clientAddr, client->addrSize);
    printf("%s:\t%s\n", client->username, timeData);
    free(client);
    pthread_exit(NULL);
}

int main() {
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket < 0) { perror("Socket Creation Failed"); return -1; }

    struct sockaddr_in serverAddr = { .sin_family = AF_INET, .sin_port = htons(2136), .sin_addr.s_addr = inet_addr("127.0.0.36") };
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Binding Failed");
        close(serverSocket);
        return -1;
    }

    printf("Server is listening...\nTime Request Information\n");

    while (1) {
        struct sockaddr_in clientAddr;
        socklen_t addrSize = sizeof(clientAddr);
        char username[100] = {0};

        int recvlen = recvfrom(serverSocket, username, sizeof(username), 0, (struct sockaddr*)&clientAddr, &addrSize);
        if (recvlen > 0) {
            Client* client = malloc(sizeof(Client));
            if (!client) { perror("malloc failed"); continue; }
            strcpy(client->username, username);
            client->socket = serverSocket;
            client->clientAddr = clientAddr;
            client->addrSize = addrSize;

            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, client);
            pthread_detach(tid);
        }
    }

    close(serverSocket);
    return 0;
}
