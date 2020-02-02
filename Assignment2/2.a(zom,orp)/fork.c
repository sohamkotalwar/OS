#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>

int main()
{
	int id;
	id=fork();

	if(id==0)
	{
		printf("\nChild Process has Started !\n");
		printf("\nChild process ID:%d\n",getpid());
		printf("\nChild's Parent process ID:%d\n",getppid());
		printf("\nChild process sleeping now .............\n");
		sleep(10);
		printf("\nChild process resumed ...........\n");
		printf("\nChild process Exiting .........\n");
		exit(0);
	}
	
	else
	{
		printf("\nParent Process Started !\n");
		printf("\nParent process ID:%d\n",getpid());
		printf("\n(i.e. BASH) process ID:%d\n",getppid());
		wait();
		printf("\nParent process resumed ...........\n");
		printf("\nParent process Exiting .........\n");
		exit(0);
	}
	
	exit(0);
}
