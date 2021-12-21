#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;
void *compute_prime(void *arg)
{

    int pri = 2;
    int n = *((int *)arg);
    int m = n;
    cout << "Thread id " << pthread_self() << " dang xu ly " << n << "  ";
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
            if (--n == 0)
            {
                cout << " Ket qua so nguyen to thu " << m << " la " << pri << endl;
                return (void *)pri;
            }
        }
        ++pri;
    }
    return NULL;
}

int main()
{
    int n;
    int rc;
    int prime;

    cout << endl
         << ">> Nhap n: ";
    cin >> n;

    pthread_t threadid;
    int *a = new int;
    *(a) = n;
    rc = pthread_create(&threadid, NULL, &compute_prime, a);
    if (rc)
    {
        cout << "\n Error: Khong the tao thread! " << rc << endl;
        exit(-1);
    }

    pthread_join(threadid, (void **)&prime);
    if (rc)
    {
        cout << "\n Error: Khong the ket hop!! " << rc << endl;
        exit(-1);
    }

    cout << "Ket qua la: " << prime << endl;

    pthread_exit(NULL);
}