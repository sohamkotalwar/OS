#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

void takefork(int i);
void putfork(int i);
void test1(int i);
void* philosopher(void *arg);

sem_t s[5];
pthread_mutex_t mutex;
int nPhilosophers;
enum stateOfP *state;

enum stateOfP //philosopher's state 
{
	THINKING,HUNGRY,EATING
};

void main()
{
	int iterator_t,counter1,check;
	pthread_t *thread1;
	
	int index[10] = {0,1,2,3,4,5,6,7,8,9};
	
	printf("\nENTER THE NUMBER OF PHILOSOPHERS :  ");
	scanf("%d",&nPhilosophers);
	
	state = (enum stateOfP*)malloc(sizeof(enum stateOfP) * nPhilosophers);
	
	for(counter1 = 0 ; counter1 < nPhilosophers ; counter1++)
	{
		check = sem_init(&s[counter1],0,0);
		if(check == -1)
		{
			printf("\nERROR IN SEMAPHORE INITIALIZATION\n");
		}
	}
	
	check = pthread_mutex_init(&mutex,NULL);
	if(check == -1)
	{
		printf("\nERROR IN MUTEX INITIALIZATION\n");
	}
	
	for(counter1 = 0 ; counter1 < nPhilosophers ; counter1++)
	{
		state[counter1] = THINKING;
	}		
	
	thread1= (pthread_t *)malloc(nPhilosophers * sizeof(pthread_t));
	
	for(iterator_t=0;iterator_t<nPhilosophers;iterator_t++)
	{
		check=pthread_create(&thread1[iterator_t],NULL,philosopher,(void *)&index[iterator_t]);
		if(check!=0)
				printf("\nError in thread creating!\n");
	}
	
	
	for(iterator_t=0;iterator_t<nPhilosophers;iterator_t++)
	{
		check=pthread_join(thread1[iterator_t],NULL);
		if(check!=0)
				printf("\nError in thread joining!\n");
	}

}

void* philosopher(void *arg)
{
	int* count = (int *)arg,num;
	do
	{
		printf("\nPHILOSOPHER %d IS THINKING\n",*count+1);
		num = rand();
		sleep(num%10);
		takefork(*count);
		printf("\nPHILOSOPHER %d IS EATING\n",*count+1);
		putfork(*count);
	}while(1);	
}
	
void takefork(int i)
{
	pthread_mutex_lock(&mutex);
	state[i] = HUNGRY;
	printf("\nPHILOSOPHER %d IS HUNGRY\n",i+1);
	test1(i);
	pthread_mutex_unlock(&mutex);
	sem_wait(&s[i]);
}	

void putfork(int i)
{
	printf("\nPHILOSOPHER %d FINISHED EATING\n",i+1);
	pthread_mutex_lock(&mutex);
	state[i] = THINKING;
	test1((i+(nPhilosophers-1)) % nPhilosophers);	
	test1((i+1) % nPhilosophers);	
	pthread_mutex_unlock(&mutex);	
}

void test1(int i)
{
	if(state[i] == HUNGRY && state[(i+(nPhilosophers-1)) % nPhilosophers] != EATING && state[(i+1) % nPhilosophers] != EATING)
	{
		state[i] = EATING;
		sem_post(&s[i]);
	}
	else
	{
		printf("\nPHILOSOPHER %d IS BLOCKED\n",i+1);
	}
}	
