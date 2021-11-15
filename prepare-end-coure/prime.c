#include <pthread.h>
#include <stdio.h>
/*Hàm tính toán trả về n so nguyen to, n là là giá trị được trỏ bởi
*arg. */

void *compute_prime(void *arg)
{
    int pri = 2;
    int k = *((int *)arg);
    while (1)
    {
        int i;
        int nguyento = 1;
        for (i = 2; i < pri; ++i)
            if (pri % i == 0)
            {
                nguyento = 0;
                break;
            }
        if (nguyento)
        {
            if (--k == 0)
                return (void *)pri;
        }
        ++pri;
    }
    return NULL;
}

int main()
{
    int err;
    int n;
    int prime;
    pthread_t tid[21];
    printf("\nNhap n:");
    scanf("%d", &n);
    int length = n;
    /* Bắt đầu luồng tính toán số nguyên tố thứ n. */
    int i = 1;
    while (i <= length)
    {
        err = pthread_create(&(tid[i]), NULL, &compute_prime, &i);
        printf("%d", i);
        if (err != 0)
        {
            printf("\ncan't create thread :");
        }

        i++;
    }
    i = 1;
    while (i <= length)
    {
        pthread_join(tid[i], (void *)&prime);
        printf("\nprime %d is: %d \n", i, prime);
        i++;
    }
    return 0;
}