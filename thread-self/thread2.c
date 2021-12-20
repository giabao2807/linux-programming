// create 2 threads

#include <pthread.h>
#include <stdio.h>

// params to printf function

struct char_print_parms
{
    char charactor; // charactor to print
    int count;      // times to print
};

// Ham xu ly thread
// In ky tu ra man hinh, duoc cho boi tham so la mot con tro den cau truc du lieu tren

void *char_print(void *params)

{

    struct char_print_parms *p = (struct char_print_parms *)params; // ep kieu tham so truyen vao

    int i;

    int n = p->count; // Bien chua so lan in ra

    char c = p->charactor; // Bien chua ma ky tu muon in ra

    for (i = 0; i < n; i++)

        fputc(c, stdout); // Ham in 1 ky tu ra thiet ra chuan

    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t pthread1_id, pthread2_id; // 2 bien doi tuong thread
    struct char_print_parms p1, p2;     // 2 bien tham so truyen vao ham xu ly

    // Tao 1 thread 100 chu x
    p1.charactor = 'x';
    p1.count = 100;
    pthread_create(&pthread1_id, NULL, &char_print, &p1);

    // Tao 1 thread 200 chu o
    p2.charactor = 'o';
    p2.count = 200;
    pthread_create(&pthread2_id, NULL, &char_print, &p2);

    // Dambao thread1 da ket thuc
    pthread_join(pthread1_id, NULL);

    // Dambao thread2 da ket thuc
    pthread_join(pthread2_id, NULL);

    return 0;
}