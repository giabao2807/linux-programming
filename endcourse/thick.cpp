#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;
#define NUM_THREADS 4

void *execute(void *arg)
{
    int rs = 1023;
    int n = *((int *)arg);
    long long start = n * 1024;
    long long end = n * 1024 + 1024 - 1;

    cout << "\nThread " << n << " xu ly cac phan tu: " << start << " den " << end;
    long long sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += i;
    }
    if (sum != 0)
    {
        return (void *)sum;
    }
    return NULL;
}
int main()
{
    cout << "*************************************************" << endl;
    cout << "* Ho va ten : Dinh Gia Bao                      *" << endl;
    cout << "* Nhom : 19Nh10                                 *" << endl;
    cout << "* MSSV: 102190252                               *" << endl;
    cout << "* De so: 05                                     *" << endl;
    cout << "*************************************************" << endl;

    int n = NUM_THREADS;
    int rc;
    pthread_t threads[n];

    int rs_arr[n];

    for (int i = 1; i <= n; i++)
    {
        int *a = new int;
        *(a) = i - 1;
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

    cout << "\n********************************\n";
    cout << "\nThread sum for a thread!! \n";
    for (int i = 0; i < n; i++)
        cout << "Sum thread " << i << " = " << rs_arr[i] << "\n";
    cout << endl;

    cout << "\n********************************\n";
    cout << "Sum of all sumthread!! \n";
    long long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (long long)rs_arr[i];

    cout << "Result= " << sum << endl;
    cout << "\n**************END***************\n";
    pthread_exit(NULL);
}