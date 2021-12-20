// Create a thread

#include <stdio.h>
#include <pthread.h>

void *printx(void *unsused)
{
    while (1)
    {
        fputc('2', stdout);
    }
    return NULL;
}

int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &printx, NULL);
    while (1)
    {
        fputc('1', stdout);
    }
    return 0;
}