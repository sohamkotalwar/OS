#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>

int main()
{
	int id;
	id=fork();
	printf("\n");

	if(id!=0)
	{
		printf("\n\nParent process Started !!\n");
		printf("\n\nParent's process ID: %d\n",getpid());
		printf("\n\nParent's Parent (BASH) Process ID: %d\n",getppid());
		printf("\n\nExiting Parent .....\n");
	}
	
	else
	{
		printf("\n\nChild Process Started !!\n");
		printf("\n\nChild Process ID: %d\n",getpid());
		printf("\n\nChild Parent Process ID: %d\n",getppid());
		sleep(20);
		printf("\n\nChild Resumed!!\n");
		printf("\n\nChild Process ID: %d\n",getpid());
		printf("\n\nChild Parent Process ID: %d\n",getppid());
		exit(0);
	}	
}
