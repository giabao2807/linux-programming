#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

void *hello(void *pthreadid)
{
    cout << "\nHello! Thread ID la: " << pthreadid << endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[4];
    int rc;
    int i;
    for (i = 0; i < 4; i++)
    {
        cout << "Dang tao thread thu: " << i << endl;
        rc = pthread_create(&threads[i], NULL, &hello, (int *)i);
        if (rc)
        {
            cout << "\n Error: Khong the tao thread!!" << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}