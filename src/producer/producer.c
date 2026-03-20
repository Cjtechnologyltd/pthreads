/* producer.c */
#include "producer.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

static void* producer_thread(void* a) {
    const int* fd = (const int*)a;
    while(1) {
        printf("%s\n", __FUNCTION__);
        usleep(500000);
        write(*fd, "hello", sizeof("hello"));
    }
}

void producer_init(const int* fd) {
    printf("%s\n", __FUNCTION__);
    pthread_t producer_thread_id;
    int err = pthread_create( &producer_thread_id, NULL, producer_thread, (void*)fd);
    printf("pthread_create %d\n", err);
}