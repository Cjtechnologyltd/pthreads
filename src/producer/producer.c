/* producer.c */
#include "producer.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

static int pipe_fd = 0;

static void* producer_thread(void* a) {
    int* fd = (int*)a;
    while(1) {
        printf("%s\n", __FUNCTION__);
        usleep(500000);
        write(*fd, "hello", sizeof("hello"));
    }
}

void producer_init(int fd) {
    printf("%s\n", __FUNCTION__);
    pipe_fd = fd;
    pthread_t producer_thread_id;
    int err = pthread_create( &producer_thread_id, NULL, producer_thread, &pipe_fd);
    printf("pthread_create %d\n", err);
}