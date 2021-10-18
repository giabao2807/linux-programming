#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int child_pid;
    printf("Chuong trinh chinh co ID cua tien trinh la %d!\n",(int)getpid());
    child_pid=fork();
    
    if(child_pid == 0)
    {
        printf("Day la tien trinh con, voi ID la %d %d\n",(int)getpid(),child_pid);
        system("pwd");
    } else if (child_pid >0)
    {
        printf("Day la tien trinh cha, voi ID la %d!\n",(int)getpid());
        printf("ID cua tien trinh con la %d\n",child_pid);
        sleep(5);
        printf("wake up!!\n");
    } else printf("The fork system call failed!!");
    return 0;
}
