#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int child_pid;
    child_pid = fork();
    if (child_pid > 0)
    {
        printf("Day la tien trinh cha. sleep 1p \n");
        sleep(60);
    }
    else
    {
        printf("Day la tien trinh con. Ket thuc\n");
        exit(0); /*Day la tien trinh con.Ket thuc */
    }
    return 0;
}