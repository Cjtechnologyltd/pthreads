/* producer.c */
#include "producer.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static void* producer_thread(void* a) {
    while(1) {
        printf("%s\n", __FUNCTION__);
        sleep(1);
    }
}

void producer_init(void) {
    printf("%s\n", __FUNCTION__);

    pthread_t producer_thread_id;
    int err = pthread_create( &producer_thread_id, NULL, producer_thread, NULL);
    printf("pthread_create %d\n", err);
}