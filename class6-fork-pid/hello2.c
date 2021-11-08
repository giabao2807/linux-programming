#include <stdio.h>
int main(int argc,char *argv[])
{
	int i=0;
	printf("Hello, Giabaone\n");
	printf("Number of arguments to the main function: %d\n",argc);
	for (i=0;i<argc;i++) printf("Argument number %d is %s \n", i, argv[i]);
	return 0;
}