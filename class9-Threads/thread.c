#include <pthread.h>
void *thread_function(void *thread_arg)
{
    /* Thực hiện công việc tại đây... */
}
int main()
{
    pthread_attr_t attr;
    pthread_t thread;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread, &attr, &thread_function, NULL);
    pthread_attr_destroy(&attr);
    /* Thực hiện công việc tại đây...*/

        /* Không cần phải tham gia đến luồng thứ hai */
    return 0;
}