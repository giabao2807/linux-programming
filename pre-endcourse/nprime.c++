
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

    cout << endl
         << ">> Nhap n: ";
    cin >> n;

    pthread_t *pthread_arr = new pthread_t[n];
    int *prime_arr = new int[n];
    for (int i = 1; i <= n; i++)
    {
        int *a = new int;
        *(a) = i;
        rc = pthread_create(pthread_arr + i - 1, nullptr, &compute_prime, a);
        if (rc)
        {
            cout << "\n Error: Khong the tao thread! " << rc << endl;
            exit(-1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        rc = pthread_join(*(pthread_arr + i - 1), (void **)(prime_arr + i - 1));
        if (rc)
        {
            cout << "\n Error: Khong the ket hop!! " << rc << endl;
            exit(-1);
        }
    }

    for (int i = 0; i < n; i++)
        cout << prime_arr[i] << "   ";
    cout << endl;

    pthread_exit(NULL);
}