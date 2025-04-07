#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUCKET_SIZE 10
#define OUTPUT_RATE 3

void leaky_bucket(int n, int packets[]) {
    int bucket = 0;

    printf("Time\tIncoming\tBucket\tSent\tRemaining\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t", i + 1, packets[i]);

        if (bucket + packets[i] > BUCKET_SIZE) {
            printf("Overflow\t");
            bucket = BUCKET_SIZE;
        } else {
            bucket += packets[i];
            printf("%d\t", bucket);
        }

        int sent = (bucket < OUTPUT_RATE) ? bucket : OUTPUT_RATE;
        bucket -= sent;

        printf("%d\t%d\n", sent, bucket);
        sleep(1);
    }

    while (bucket > 0) {
        int sent = (bucket < OUTPUT_RATE) ? bucket : OUTPUT_RATE;
        printf("Drain\t--\t\t%d\t%d\t%d\n", bucket, sent, bucket - sent);
        bucket -= sent;
        sleep(1);
    }
}

int main() {
    int n, packets[25];

    printf("Enter number of time steps: ");
    scanf("%d", &n);

    printf("Enter packets arriving at each time step:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &packets[i]);
    }

    leaky_bucket(n, packets);
    return 0;
}
