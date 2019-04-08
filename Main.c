#include<stdio.h>
#include<stdlib.h>

int no_of_processes = 0; 

struct p_info
{
	int pid;
	int priority;
	int burst_time;
	int waiting_time;
	int turnaround_time;
	int remaining_time;
	int arrival_time;
};

//List of functions used
void FCFS();
void PriorityScheduling();
void RoundRobin();


void input()
{
	printf("Enter total number of processes : ");
	scanf("%d",&no_of_processes);
	ptr = (struct p_info*) malloc (no_of_processes * sizeof(struct p_info));
	int i;
	bool flag = true;
	for(i=0; i<no_of_processes; i++)
	{
		printf("Enter process id:\t");
		scanf("%d", &(ptr+i)->pid);
		printf("Enter details for process\n");
		while(flag)
		{
			printf("Enter priority(from 1 to 10)");
			scanf("%d", &(ptr+i)->priority);
			int a = (ptr+i)->priority
			if(a>=1 && a<=10)
				flag = false;
		}

		scanf("%d", &(ptr+i)->pid);
		printf("Enter burst time");
		scanf("%d", &(ptr+i)->burst_time);
		printf("Enter arrival time");
		scanf("%d", &(ptr+i)->arrival_time);
		

	}


}

void main()
{
	input();
	int i = 3;
	while(no_of_processes>0)
	{
		switch(i)
		{
			case 1:
				RoundRobin();	//top priority
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
