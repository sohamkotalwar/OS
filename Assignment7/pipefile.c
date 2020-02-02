/*
Following are some example programs.

Example program 1 − Program to write and read two messages using pipe.
Algorithm

Step 1 − Create a pipe.

Step 2 − Send a message to the pipe i.e filename

Step 3 − Retrieve the message from the pipe through filename and write it to the standard output.

Note − Retrieving messages can also be done after sending all messages.

Source Code: simplepipe.c (single message)
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main() {
   int pipefds[2],pipefds1[2];
   int returnstatus;
   char writemessages[20]={"7.txt"};
   char readmessage[20];
   returnstatus = pipe(pipefds);
    FILE *fptr;
    int pid;
    char filename[100], c;  
    
   if (returnstatus == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   
   pid = fork();
   if(pid!=0)
   {
   printf("Writing to pipe - Message 1 is %s\n", writemessages);
   write(pipefds[1], writemessages, sizeof(writemessages));
   
   }
   else
   {
   printf("Reading from pipe – Message 1 is \n");
   read(pipefds[0], readmessage, sizeof(readmessage));
   strcpy(filename,writemessages);
   fptr = fopen(filename, "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 
   
   }
   return 0;
   }
