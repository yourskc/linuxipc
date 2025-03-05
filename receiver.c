#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>

#define QUEUE_NAME "/my_queue"
#define MAX_SIZE 1024

int main() {
    mqd_t mq;
    struct mq_attr attr;
    char message[MAX_SIZE];
    ssize_t bytes_read;

    // Define message queue attributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    // Create or open a message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("Failed to open message queue");
        exit(EXIT_FAILURE);
    }

    // Receive messages
    while (1) {
        bytes_read = mq_receive(mq, message, MAX_SIZE, NULL);
        if (bytes_read >= 0) {
            message[bytes_read] = '\0';
            printf("Received: %s\n", message);
        } else {
            perror("Failed to receive message");
            break;
        }
    }

    // Close and unlink message queue
    mq_close(mq);
    mq_unlink(QUEUE_NAME);
    return 0;
}