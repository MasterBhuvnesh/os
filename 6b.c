 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <pthread.h>
 
void* fibonacci(void *arg) {
    int n = *(int*)arg; 
    int a = 0, b = 1, c;
 
    printf("Fibonacci Series:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b; 
        a = b;
        b = c;
        sleep(1);
    }
    printf("\n");
    return NULL;
 }
 
void* count_digits(void *arg) {
    int number = *(int*)arg;
    int count = 0;
 
    while (number != 0) {
        number /= 10;
        count++;
    }
 
    printf("Number of digits: %d\n", count);
    return NULL;
 }
 
int main() {
    pthread_t fib_thread;
    pthread_t count_thread;
    int n = 10;
    int num = 12345;
    pthread_create(&fib_thread, NULL, fibonacci, &n);pthread_join(fib_thread, NULL);
    pthread_create(&count_thread, NULL, count_digits, &num);pthread_join(count_thread,
 NULL);
 
    return 0;
}