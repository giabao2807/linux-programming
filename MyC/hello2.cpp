#include<stdio.h>

int main(int argc,char **argv)
{
	printf("hello cac ban\n");
	printf("Number of arguments to the main function: %d\n",argc);
	for (int i=0;i<argc ;i++)
	{
		printf("Argument number %d is %s\n",i,argv[i]);
	}

}
