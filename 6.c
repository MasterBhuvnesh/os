 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <pthread.h>
 
// Thread function to print numbers
 void* thread_function(void *arg) {
    printf("Inside Thread \n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i + 1);
        sleep(1); // Sleep for a second
    }
    return NULL;
 }
 
// Thread function to calculate factorial
 void* factorial(void *arg) {
    int n = *(int*)arg; // Get the number from the argument
    int result = 1;
 
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
 
    printf("Factorial of %d is: %d\n", n, result);
    return NULL;
 }
 
int main() {
    pthread_t a_thread; // Thread declaration
    
    // Create the number thread
    pthread_create(&a_thread, NULL, thread_function, NULL);
    
    // Wait for the number thread to finish
    pthread_join(a_thread, NULL);
 
    pthread_t fact_thread;
    int num = 5; // Number for which we want the factorial
 
    // Create the factorial thread
    pthread_create(&fact_thread, NULL, factorial, &num);
 
    // Wait for the factorial thread to finish
    pthread_join(fact_thread, NULL);
 
    printf("Inside Main Program\n");
 
    return 0;
 }
