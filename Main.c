#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int no_of_processes = 0; 
int counter=1;
int q1_no,q2_no,q3_no;
struct p_info
{
	int pid;
	int priority;
	int burst_time;
	int waiting_time;
	int turnaround_time;
	int remaining_time;
	int arrival_time;
	int priority_group;
	int remaining_time;
	int flag = 0;
};

//List of functions used
void input();
void FCFS();
void PriorityScheduling();
void RoundRobin();
void show();


void check algo()
{
	if(counter==1)
		RoundRobin();
	else if(counter == 2)
		
}




void input()
{
	printf("Enter total number of processes : ");
	scanf("%d",&no_of_processes);
	
	struct p_info* ptr;
	ptr = (struct p_info*) malloc (no_of_processes * sizeof(struct p_info));
	int i;
	
	for(i=0; i<no_of_processes; i++)
	{
		bool flag = true;
		printf("Enter process id:\t");
		scanf("%d", &(ptr+i)->pid);
		printf("Enter details for process\n");
		while(flag==true)
		{
			printf("Enter priority(from 1 to 10): ");
			scanf("%d", &(ptr+i)->priority);
			int a = (ptr+i)->priority;
			if(a>=1 && a<=10)
				flag = false;
		}
		printf("Enter burst time: ");
		scanf("%d", &(ptr+i)->burst_time);
		printf("Enter arrival time: ");
		scanf("%d", &(ptr+i)->arrival_time);
		if((ptr+i)->priority<4)
		{
			(ptr+i)->priority_group = 1;
		}
		else if((ptr+i)->priority>3 && (ptr+i)->priority<7)
		{
			(ptr+i)->priority_group = 2;
		}
		else if((ptr+i)->priority>7 && (ptr+i)->priority<11)
		{
			(ptr+i)->priority_group = 3;
		}
		

	}


}


void show()
{
	int i = 0;
	struct p_info* ptr;
	for(i=0; i<no_of_processes; i++)
	{
		printf("Process ID: %d\t",(ptr+i)->pid);
		printf("priority : %d\t",(ptr+i)->priority);
		printf("burst time: %d\t", (ptr+i)->burst_time);
		printf("arrival time: %d\t",(ptr+i)->arrival_time);
		printf("Priority Group: %d",(ptr+i)->priority_group);
		printf("\n");		

	}

	
}


void RoundRobin()
{

	struct p_info* ptr;
	int i = 0;
	for(i=0;i<n;i++)
	{
		if((ptr+i)->)
	}
}



void main()
{
	input();
	int i = 3;
	while(no_of_processes>0)
	{
		check_algo();
	}
	show();
}
