#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main(int agrc, char ** argv)
{
    int child_pid =2;
    cout<<"Chuong trinh chinh co ID cua tien trinh la: "<< getpid()<<endl;
    child_pid = fork();
    if (child_pid<0)
    {
        cout<<"Loi tao tien trinh con"<<endl;
    }
    else if (child_pid> 0) 
    {
        cout<<"Day la tien trinh cha voi ID la: "<<getpid()<<endl;
        cout<<"Tien trinh con voi ID la: " << child_pid<<endl;
        int status;
        wait(&status);

        cout<<"Doi thang con"<<status<<endl;
    }
    else
    {
        cout<<"Day la tien trinh con voi ID la: "<<getpid()<<" "<<child_pid<<endl;
        system("pwd");
    }

}