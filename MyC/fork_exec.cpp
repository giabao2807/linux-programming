#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;


int spawn(char * program, char** arg_list)
{
    int child_pid = fork();
    if (child_pid<0)
    {
        cout<< "Loi tao tien trinh con";
    }
    else if (child_pid > 0)
    {
        cout<< "";
    }
    else
    {
        execvp(program,arg_list);
        fprintf(stderr,"Loi xay ra trong execvpn");
        abort();
    }

}
int main(int agrc, char ** argv)
{
    char * args[] = {"ls","-i","-o",NULL};
    spawn("ls",args);


}   