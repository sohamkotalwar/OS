#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int mat1[10][10];
int mat2[10][10];
int mat3[10][10];

int r1 , c1 , r2 , c2;

void *mat_mul(void *p);

int main()
{
	pthread_t tid;
	int i , j , k;
	

	printf("\n enter no of rows for 1st matrix :\n");
	scanf("%d",&r1);
	printf("\n enter no of columns for 1st matrix :\n");
	scanf("%d",&c1);

	
	for(i=0 ; i < r1 ; i++)
	{
	
		for(j=0 ; j < c1 ; j++)
		{
		
			printf("enter mat[%d][%d] : ",i,j);
			scanf("%d",&mat1[i][j]);
		
		
			printf("\n");
			
		}
	
	}


	printf("\n");
	
	
	printf("\n enter no of rows for 2nd matrix :\n");
	scanf("%d",&r2);
	printf("\n enter no of columns for 2nd matrix :\n");
	scanf("%d",&c2);

	
	
	
	for(i=0 ; i < r2 ; i++)
	{
	
		for(j=0 ; j < c2 ; j++)
		{
		
			printf("enter mat[%d][%d] : ",i,j);
			scanf("%d",&mat2[i][j]);
		
			printf("\n");
		
		}
		
		
	
	}

	if(c1!=r2)
	{
		printf("\n multiplication not possible\n");
	}
	else
	{
	
		for(i=0 ; i < r1 ; i++)
		{
		
			for(j=0 ; j < c2 ; j++)
			{
				printf("Thread %d-%d created",&i,&j);
				mat3[i][j] = 0;
			
			}
		
		}
		
		
		pthread_create(&tid,NULL,mat_mul,NULL);
		pthread_join(tid , NULL);
	
	
	}
	
	
	printf("\n 1st matrix :\n");
	
	for(int i=0 ; i < r1 ; i++)
	{
	
		for(j=0 ; j < c1 ; j++)
		{
		
			printf("%d \t",mat1[i][j]);
		
		}
		
		printf("\n");
	
	}
	
	
	printf("\n 2nd matrix :\n");
	
	for(int i=0 ; i < r2 ; i++)
	{
	
		for(j=0 ; j < c2 ; j++)
		{
		
			printf("%d \t",mat2[i][j]);
		
		}
		
		printf("\n");
	
	}
	
	
	printf("\n multiplication :\n");
	
	for(i=0 ; i < r1 ; i++)
	{
	
		for(j=0 ; j < c2 ; j++)
		{
		
			printf("%d \t",mat3[i][j]);
		
		}
		
		printf("\n");
	
	}
	
	return 0;

}


void *mat_mul(void *p)
{
	
	int i , j , k;

	for(i=0;i < r1 ; i=i+1)
	{
	
		for(j=0 ; j < c2 ; j++)
		{
			    mat3[i][j]=0;
			
			for(k=0 ; k < c1 ; k++)
			{
				mat3[i][j]+=mat1[i][k] * mat2[k][j];				
			}
		}
	
	}
	
	pthread_exit(NULL);

}
