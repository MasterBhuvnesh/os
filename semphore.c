// SEMAPHORE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
int count = 5;
sem_t s;
void* p(void *arg) {
int x ;
sem_wait(&s);
x = count;
x++;
sleep(1);
count = x;
sem_post(&s);
return NULL;
}
void* c(void *arg) {
int y;
sem_wait(&s);
y = count;
y--;
sleep(1);
count = y;
sem_post(&s);
return NULL;
}
int main() {
sem_init(&s,0,1);
pthread_t p_thread;
pthread_t c_thread;
pthread_create(&p_thread, NULL, p, NULL);
pthread_create(&c_thread, NULL, c, NULL);
pthread_join(p_thread, NULL);
pthread_join(c_thread, NULL);
printf("Final count in main: %d\n", count);
return 0;
}