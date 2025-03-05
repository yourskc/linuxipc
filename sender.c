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

    // Define message queue attributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    // Create or open a message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("Failed to open message queue");
        exit(EXIT_FAILURE);
    }

    // Send messages
    for (int i = 0; i < 5; i++) {
        snprintf(message, MAX_SIZE, "Message %d from C program", i + 1);
        if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
            perror("Failed to send message");
            exit(EXIT_FAILURE);
        }
        printf("Sent: %s\n", message);
        sleep(1);
    }

    // Close and unlink message queue
    mq_close(mq);
    mq_unlink(QUEUE_NAME);
    return 0;
}


