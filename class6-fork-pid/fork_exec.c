#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int spawn(char* program,char* *arg_list)
{
    int child_pid=fork();
    if(child_pid == 0)
    {
        execvp(program, arg_list);
        fprintf(stderr,"Loi xay ra trong execvpn");
        abort();
    } else if (child_pid >0)
    {
        sleep(5);
        return child_pid;
    } else printf("The fork system call failed!!");
    return 1;
}

int main()
{
    char* arg_list[]={"ls","-l","/",NULL};
    spawn("ls",arg_list);
    printf("Ket thuc chuong trinh chinh\n");
    return 0;
}

