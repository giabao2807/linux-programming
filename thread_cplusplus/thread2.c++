#include <iostream>
#include <cstdlib>
#include <pthread.h>
#define THREAD_NUMBER 5

using namespace std;

struct dulieu
{
    int id;
    char *thongdiep;
};

void *hello(void *params)
{
    struct dulieu *data;
    data = (struct dulieu *)params;
    cout << "\n Thread ID: " << data->id;
    cout << "\n Message: " << data->thongdiep << endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[THREAD_NUMBER];
    struct dulieu td[THREAD_NUMBER];
    int rc;
    int i;
    for (i = 1; i <= THREAD_NUMBER; i++)
    {
        cout << "\n Dang tao thread thu " << i << endl;
        td[i].id = i;
        td[i].thongdiep = "Thong diep!!";

        rc = pthread_create(&threads[i], NULL, &hello, (void *)&td[i]);
        if (rc)
        {
            cout << "\n Error: Khong the tao thread! " << rc << endl;
            exit(-1);
        }
        }
    pthread_exit(NULL);
}