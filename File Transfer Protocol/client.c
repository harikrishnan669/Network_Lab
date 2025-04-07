#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void sendFile(int sock) {
    char buffer[4096], filename[128];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("File open error");
        return;
    }

    int bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), fp)) > 0)
        send(sock, buffer, bytesRead, 0);

    fclose(fp);
    printf("File \"%s\" sent successfully.\n", filename);
}
int main() {
    int client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0) return 1;

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1111);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Connection failed");
        return 1;
    }
    printf("Connected to server.\n");
    sendFile(client);
    close(client);
    return 0;
}
