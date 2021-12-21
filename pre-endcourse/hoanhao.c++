#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;
void *execute(void *arg)
{
    int count = 0;
    int rs;
    int n = *((int *)arg);
    int m = n;
    cout << "Thread id " << pthread_self() << " dang xu ly " << n << "  ";

    int i = 1;
    int sum = 0;
    while (i < m)
    {
        if (m % i == 0)
        {
            sum += i;
        }
        i++;
    }
    if (sum == m)
    {
        cout << " Day la so hoan hao" << endl;
        return (void *)1;
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
    rc = pthread_create(&threadid, NULL, &execute, a);
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

    cout << "Ket qua la: " << (prime == 1 ? " so hoan hao" : "khong phai so hoan hao") << endl;

    pthread_exit(NULL);
}