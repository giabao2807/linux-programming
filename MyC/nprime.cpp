
#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;

void *execute(void *arg)
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
    cout << endl
         << "nhap n:";
    cin >> n;

    pthread_t *pthread_arr = new pthread_t[n];
    int *prime_arr = new int[n];
    for (int i = 1; i <= n; i++)
    {
        int *a = new int;
        *(a) = i;
        pthread_create(pthread_arr + i - 1, nullptr, &execute, a);
    }
    for (int i = 1; i <= n; i++)
    {
        pthread_join(*(pthread_arr + i - 1), (void **)(prime_arr + i - 1));
    }

    for (int i = 0; i < n; i++)
        cout << prime_arr[i] << "   ";
    cout << endl;
    return 0;
}