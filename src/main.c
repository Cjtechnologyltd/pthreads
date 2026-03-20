/* main.c */
#include <stdio.h>
#include "consumer.h"
#include "producer.h"

int main (int argc, char* argv[]) {
    printf("%s\n", __FUNCTION__);
    consumer_init();
    producer_init();
    return 0;
}