
#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;

void *execute(void *arg)
{

    int rs = 6;
    int n = *((int *)arg);
    int m = n;
    cout << "Thread id " << pthread_self() << " dang xu ly " << n << "  ";
    while (1)
    {
        int check = 0;
        int i = 1;
        int sum = 0;
        while (i < rs)
        {
            if (rs % i == 0)
            {
                sum += i;
            }
            i++;
        }
        if (sum == rs)
        {
            check = 1;
        }
        if (check)
        {
            if (--n == 0)
            {
                cout << " Ket qua so hoan hao thu " << m << " la " << sum << endl;
                return (void *)sum;
            }
        }
        ++rs;
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

    pthread_t threads[n];
    int rs_arr[n];
    for (int i = 1; i <= n; i++)
    {
        int *a = new int;
        *(a) = i;
        rc = pthread_create(&threads[i - 1], nullptr, &execute, a);
        if (rc)
        {
            cout << "\n Error: Khong the tao thread! " << rc << endl;
            exit(-1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        rc = pthread_join(threads[i - 1], (void **)&rs_arr[i - 1]);
        if (rc)
        {
            cout << "\n Error: Khong the ket hop!! " << rc << endl;
            exit(-1);
        }
    }

    for (int i = 0; i < n; i++)
        cout << rs_arr[i] << "   ";
    cout << endl;

    pthread_exit(NULL);
}