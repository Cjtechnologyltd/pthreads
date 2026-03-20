/* consumer.c */
#include "consumer.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static void* consumer_thread(void* a) {
    while(1) {
        printf("%s\n", __FUNCTION__);
        sleep(1);
    }
}

void consumer_init(void) {
    printf("%s\n", __FUNCTION__);

    pthread_t consumer_thread_id;
    int err = pthread_create( &consumer_thread_id, NULL, consumer_thread, NULL);
    printf("pthread_create %d\n", err);
}