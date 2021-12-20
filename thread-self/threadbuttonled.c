
/**********************************************************

* Chuong trinh:

* main: Thuc hien dieu khien led chay duoi

* thread: Thuc hien doc trang thai (polling) nut bam de thay doi toc do led

***********************************************************/

#include <pthread.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/ioctl.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <sys/select.h>

#include <sys/time.h>

#include <errno.h>

#define ON 1

#define OFF 0

/* Bien luu thoi gian delay */

// Thay doi khi K1, K2 duoc an

static int t = 1000; // don vi la milisecond, ban dau mac dinh la 1000 ms

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

/* Ham sleep ms su dung usleep cua linux */

void sleepms(int ms)

{

    // usleep in us, sleep in second

    usleep(1000 * ms); // convert to microseconds

    return;
};

/* Cau truc du lieu se truyen tham so cho thread */

struct thread_parms

{

    char btn[6];

    int btn_fd;
};

/* Ham xu ly cua thread thuc hien doc nut K1, K2 (polling) */

void *btn_polling(void *param);

int main(int argc, char **agrv)

{

    int led_fd, button_fd; //# of device file

    struct thread_parms p; // Bien cau truc chua tham so se truyen cho ham xu ly cua thread

    pthread_t thread_id; //# of thread

    int led_no; // So hieu led 0-4

    // Mang chua gia tri trang thai 6 button se doc

    char buttons[6] = {'0', '0', '0', '0', '0', '0'};

    int i;

    // Mo thiet bi (led port), can kiem tra chinh xac ten trong /dev

    led_fd = open("/dev/leds", 0);

    if (led_fd < 0)
    {

        perror("open device leds");

        exit(1);
    }

    else
        printf("open device led ok\n");

    // Mo thiet bi (button port)

    button_fd = open("/dev/buttons", 0); // mo button port

    if (button_fd < 0)

    {

        perror("open device buttons");

        exit(1);
    }

    else
        printf("open device button ok\n");

    // Chuan bi tham so truyen vao cho ham xu ly cua thread

    p.btn_fd = button_fd; // button device file number

    // memset(p.btn, '0', sizeof(p.btn)); //khoi tao buffer

    for (i = 0; i < 6; i++)
        p.btn[i] = '0'; // buffer to read button status (K1-K6)

    // Tao thread thuc hien polling button

    thread_id = pthread_create(&thread_id, NULL, &btn_polling, &p);

    // Chuong trinh chinh (master thread) thuc hien hieu ung led duoi

    // voi thoi gian delay chua trong bien t

    // Ban dau tat ca cac led deu off

    for (i = 0; i < 4; i++)
        ioctl(led_fd, OFF, i);

    led_no = 0;

    while (1)

    {

        // Bat led led_no

        ioctl(led_fd, ON, led_no);

        // Sleep in t ms

        sleepms(t);

        // Tat led led_no va chuan bi bat luon led ke tiep

        ioctl(led_fd, OFF, led_no);

        led_no++;

        if (led_no == 4)
            led_no = 0;
    }

    close(button_fd);

    close(led_fd);

    return 0;
}

void *btn_polling(void *param)

{

    struct thread_parms *p = (struct thread_parms *)param;

    char cur_btn[6], old_btn[6];

    int btn_fd;

    int i;

    for (i = 0; i < 6; i++)
        old_btn[i] = p->btn[i];

    btn_fd = p->btn_fd;

    for (;;) // Lien tuc tham do trang thai nut bam (K1, K2 co duoc an)

    {

        int num = read(btn_fd, cur_btn, sizeof(cur_btn));

        if (num != sizeof(cur_btn))

        {

            perror("read buttons:");

            exit(1);
        }

        // Chi can doc K1, K2 tuong ung voi tang/giam led speed

        // Doc K1

        if (old_btn[0] != cur_btn[0])

        {

            old_btn[0] = cur_btn[0];

            printf("K1 is pressed/released\n");

            // Can dung mutex cho bien t ?

            pthread_mutex_lock(&mutex1);

            t = t + 50; // tang thoi gian delay

            pthread_mutex_unlock(&mutex1);
        }

        // Doc K2

        if (old_btn[1] != cur_btn[1])

        {

            old_btn[1] = cur_btn[1];

            printf("K2 is pressed/released\n");

            // Can dung mutex cho bien t ?

            pthread_mutex_lock(&mutex1);

            t = t - 50; // giam thoi gian delay

            if (t < 100)
                t = 100;

            pthread_mutex_unlock(&mutex1);
        }
    }

    return NULL;
}