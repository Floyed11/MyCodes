#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<dispatch/dispatch.h>

// sem_t sem_A, sem_B, sem_C;
dispatch_semaphore_t sem_A, sem_B, sem_C;

void *A(){
    printf("A\n");
    // sem_post(&sem_A);
    dispatch_semaphore_signal(sem_A);
    return NULL;
}

void *B(){
    // sem_wait(&sem_A);
    dispatch_semaphore_wait(sem_A, DISPATCH_TIME_FOREVER);
    printf("B\n");
    // sem_post(&sem_B);
    dispatch_semaphore_signal(sem_A);
    dispatch_semaphore_signal(sem_B);
    return NULL;
}

void *C(){
    // sem_wait(&sem_A);
    dispatch_semaphore_wait(sem_A, DISPATCH_TIME_FOREVER);
    printf("C\n");
    // sem_post(&sem_C);
    dispatch_semaphore_signal(sem_A);
    dispatch_semaphore_signal(sem_C);
    return NULL;
}

void *D(){
    // sem_wait(&sem_B);
    // sem_wait(&sem_C);
    dispatch_semaphore_wait(sem_B, DISPATCH_TIME_FOREVER);
    dispatch_semaphore_wait(sem_C, DISPATCH_TIME_FOREVER);
    printf("D\n");
    return NULL;
}

int main(){
    pthread_t t1, t2, t3, t4;
    // sem_init(&sem_A, 0, 0);
    // sem_init(&sem_B, 0, 0);
    // sem_init(&sem_C, 0, 0);
    sem_A = dispatch_semaphore_create(0);
    sem_B = dispatch_semaphore_create(0);
    sem_C = dispatch_semaphore_create(0);
    pthread_create(&t1, NULL, D, NULL);
    pthread_create(&t2, NULL, C, NULL);
    pthread_create(&t3, NULL, A, NULL);
    pthread_create(&t4, NULL, B, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    // sem_destroy(&sem_A);
    // sem_destroy(&sem_B);
    // sem_destroy(&sem_C);
    return 0;
}