#include<iostream>
#include<unistd.h>
using namespace std;


int main()
{
	cout<<"Process ID: "<< getpid()<<endl;
	cout<<"Parent process ID: "<< getppid()<<endl;
	return system("ls -l");

}
