/*
================================================================================================
 Name        	   : b_binarysearch.c
 Author      	   : soham k	
 Roll No.	 	   : 33125
 Problem Statement : Process control system calls: The demonstration of fork, execve and
			   		 wait system calls along with zombie and orphan states.
			   
					 b. Implement the C program in which main program accepts an integer array. 
			   	 		Main program uses the fork system call to create a new process called a 
			   	 		child process. Parent process sorts an integer array and passes the sorted
			   	 		array to child process through the command line arguments of execve system 
			   	 		call. The child process uses execve system call to load new program that 
			   	 		uses this sorted array for performing the binary search to search the 
			   	 		particular item in the array.				  	
================================================================================================
*/

#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h>    
#include <stdlib.h>    
#include <unistd.h>  

void binarysearch(long int [10], int n);

void main(int argc, char *argv[],char *envp[])
{
	int i, n=0;
	long ret[10];
	
	for(i=1; argv[i]!=NULL; i++)
	{
		ret[i] = strtol(argv[i], NULL, 10);
		n++;
	}
		
	printf("SEARCH: In second child process. My process-id is %d.\n", getpid());
	printf("SEARCH: My parent's process-id is %d.\n\n", getppid());

	binarysearch(ret, n);
}

void binarysearch(long int a[10], int n)
{
	int c, first, last, middle, search;
   
	printf("Enter value to search: \n");
	scanf("%d",&search);
	
 	printf("\n\n=================In Binary Search Program=================== \n");
	first = 0;
	last = n - 1;
	middle = (first+last)/2;

	while( first <= last )
	{
		if ( a[middle] < search )
	 		first = middle + 1;    
		else if ( a[middle] == search ) 
		{
	 		printf("%d found at location %d.\n", search, middle);
	 		break;
		}
		else
		last = middle - 1;

		middle = (first + last)/2;
	}
	if ( first > last )
	printf("%d is not present in the list.\n", search);
   
}
