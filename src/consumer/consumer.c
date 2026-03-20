/* consumer.c */
#include "consumer.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

static int pipe_fd = 0;

static void* consumer_thread(void* a) {
    int* fd = (int*)a;
    int bytes_read = 0;
    char buff [16];

    while(1) {
        printf("%s\n", __FUNCTION__);
        bytes_read = read(*fd, buff, 16);
        if (bytes_read > 0) {
            for (int i = 0; i < bytes_read; i++) {
                printf("Pipe read - %c\n", buff[i]);
            }
        }
        sleep(1);
    }
}

void consumer_init(int fd) {
    printf("%s\n", __FUNCTION__);
    pipe_fd = fd;
    pthread_t consumer_thread_id;
    int err = pthread_create( &consumer_thread_id, NULL, consumer_thread, &pipe_fd);
    printf("pthread_create %d\n", err);
}