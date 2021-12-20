#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
using namespace std;

#define NUMBER_THREAD 5

void *wait(void *tid)
{
    int i;
    sleep(1);
    cout << "\n Dang tam dung 1 thread " << endl;
    cout << "\n Thread voi ID la: " << tid << "... dang thoat! " << endl;
    pthread_exit(NULL);
}

int main()
{
    int rc;
    int i;
    pthread_t threads[NUMBER_THREAD];
    pthread_attr_t attr;

    void *status;

    // Khoi tao va thiet lap mot thread co the ke hop
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    for (i = 1; i <= NUMBER_THREAD; i++)
    {
        cout << "\n Dang tao thread thu " << i << endl;
        rc = pthread_create(&threads[i], NULL, wait, (void *)i);
        if (rc)
        {
            cout << "\n Error: Khong the tao thread! " << rc << endl;
            exit(-1);
        }
    }

    // Giai phong thuoc tinh va doi thread khac
    pthread_attr_destroy(&attr);
    for (i = 1; i <= NUMBER_THREAD; i++)
    {
        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            cout << "\n Error: Khong the ket hop!! " << rc << endl;
            exit(-1);
        }
        cout << "\nMain: ket huc thread id :" << i;
        cout << "  va thoat voi trang thai:" << status << endl;
    }
    cout << "\nMain: thoat chuong trinh!" << endl;
    pthread_exit(NULL);
}