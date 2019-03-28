#include<stdio.h>
#include<stdlib.h>

int n = 0; 

void input()
{
	printf("Enter total number of processes : ");
	scanf("%d",&n);
}

void main()
{
	input();
	int i = 3;
	while(n>0)
	{
		switch(i)
		{
			case 1:
				RoundRobin4();	//top priority
				break;
			case 2:
				PriorityScheduling();	//medium priority
				break;
			case 3:
				FCFS;	//low priority
				break;
		}
		i++;
		sleep(10);	//time quantum for each of multilevel queue
	}
}
