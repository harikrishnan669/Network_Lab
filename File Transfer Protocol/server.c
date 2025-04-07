#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void receiveFile(int sock) {
    char buffer[4096];
    int len = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (len <= 0) return;

    buffer[len] = '\0';

    // Reverse the buffer
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }
    FILE *fp = fopen("output.txt", "w");
    if (fp) {
        fprintf(fp, "%s", buffer);
        fclose(fp);
    }

    printf("Reversed content saved to output.txt:\n%s\n", buffer);
}
int main() {
    int server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0) return 1;

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1111);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(server, (struct sockaddr*)&addr, sizeof(addr)) < 0) return 1;
    if (listen(server, 1) < 0) return 1;

    printf("Server listening on 127.0.0.1:Port 1111...\n");

    int client = accept(server, NULL, NULL);
    if (client >= 0) {
        receiveFile(client);
        close(client);
    }

    close(server);
    return 0;
}
