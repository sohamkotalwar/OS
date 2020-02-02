#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    int id;
    id=fork();
    
    if(id!=0)
    {
    	printf("\n\nParent process Started !!\n");
		printf("\n\nParent process ID: %d\n",getpid());
		printf("\n\n(BASH) Process ID: %d\n",getppid());
		while(1)
		{
			/*
			
			*/		
		}
		printf("\n\nExiting Parent .....\n");
		exit(-1);
    }
    
    else
    {
    	printf("\n\nChild Process Started !!\n");
		printf("\n\nChild Process ID: %d\n",getpid());
		printf("\n\nChild's Parent Process ID: %d\n",getppid());
		printf("\n\nChild Exiting !!\n");
		exit(0);
    }
} 
