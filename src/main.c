/* main.c */
#include <stdio.h>
#include <unistd.h>
#include "consumer.h"
#include "producer.h"

int main (int argc, char* argv[]) {
    printf("%s\n", __FUNCTION__);

    int pipe_fds[2];
    if (pipe(pipe_fds) < 0) {
        perror("pipe open");
        return 1;
    }

    consumer_init(&pipe_fds[0]);
    producer_init(&pipe_fds[1]);

    while(1) {

    }
    return 0;
}