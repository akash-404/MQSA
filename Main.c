#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int no_of_processes = 0; 
int counter=1,timer = 0;
int n;




typedef struct p_info
{
	int pid;
	int priority;
	int burst_time;
	int waiting_time;
	int turnaround_time;
	int remaining_time;
	int completion_time;
	int arrival_time;
	int priority_group;
	int flag;
}P;

P p_arr[10];

//List of functions used
void input(int);
void FCFS();
void PriorityScheduling();
void RoundRobin();
void show();
void check();




void input(int no_of_processes)
{
	int i = 0;
	
	
	for(i=0; i<no_of_processes; i++)
	{
		bool flag = true;
		printf("\nEnter process id:\t");
		scanf("%d", &p_arr[i].pid);
		printf("Enter details for process\n");
		while(flag==true)
		{
			printf("Enter priority(from 1 to 10): ");
			scanf("%d", &p_arr[i].priority);
			int a = p_arr[i].priority;
			if(a>=1 && a<=10)
				flag = false;
		}
		printf("Enter burst time: ");
		scanf("%d", &p_arr[i].burst_time);
		p_arr[i].remaining_time = p_arr[i].burst_time;
		printf("Enter arrival time: ");
		scanf("%d", &p_arr[i].arrival_time);
		
		
	///////////// assigning priority group	///////////////	
		if(p_arr[i].priority<4)
		{
			p_arr[i].priority_group = 1;
		}
		else if(p_arr[i].priority>3 && p_arr[i].priority<7)
		{
			p_arr[i].priority_group = 2;
		}
		else if(p_arr[i].priority>7 && p_arr[i].priority<11)
		{
			p_arr[i].priority_group = 3;
		}
		

	}



	///////////////	sorting	according to arrival time//////////
	int j;
	for(i=0;i<no_of_processes-1;i++)
	{
		for(j=0; j<no_of_processes;j++)
		{
			if(p_arr[j].arrival_time > p_arr[i].arrival_time)
			{
				struct p_info temp = p_arr[j];
				p_arr[j] = p_arr[j+1];
				p_arr[j+1] = temp;
			}
		}	
	}
	timer = p_arr[0].arrival_time;


}


void show()
{
	printf("Process ID  Priority  Burst Time  Arrival Time  Priority_Group  Remaining Time  flag\n");
	int i = 0;
	for(i=0; i<n; i++)
	{		
		printf("%d \t", p_arr[i].pid);
		printf("%d ", p_arr[i].completion_time);
	}
}




void RoundRobin()
{
	int time_quantum = 4;
	int i = 0, time = 10;
	for(i=0;i<no_of_processes;i++)
	{
		if(p_arr[i].priority_group == 1 && p_arr[i].arrival_time <= timer)
		{
			int rt = p_arr[i].remaining_time;
			if(rt <= time_quantum && rt>0)
			{
				timer+=rt;
				time += rt;
				rt = 0;
				p_arr[i].remaining_time = 0;
				p_arr[i].flag = 1;
			}
			else
			{
				rt = rt-time_quantum;
				p_arr[i].remaining_time -= time_quantum;
				time+=time_quantum;
				timer += time_quantum;

			}

			if(rt==0 && p_arr[i].flag == 1)
			{
				no_of_processes -= 1;
				p_arr[i].completion_time = timer;
			}
		}
	}
	check();
	FCFS();
	
	
	
}






void PriorityScheduling()
{
	int i;
	int time = 10;
	for(i=0;i<no_of_processes;i++)
	{
		if(p_arr[i].priority_group == 2 && p_arr[i].arrival_time <= timer)
		{
			int j;
			for(i=0;i<no_of_processes-1;i++)
			{
				for(j=0; j<no_of_processes;j++)
					{
						if(p_arr[j].priority > p_arr[i].priority)
						{
							struct p_info temp = p_arr[j];
							p_arr[j] = p_arr[j+1];
							p_arr[j+1] = temp;
						}
					}	
			}
			
			int rt = p_arr[i].remaining_time;
			if(rt>0 && rt<=10)
			{
				timer+=rt;
				time -= rt;
				rt = 0;
				p_arr[i].remaining_time = 0;
				p_arr[i].flag = 1;
			}
			else
			{
				timer+=10;
				time -=10;
				p_arr[i].remaining_time = p_arr[i].remaining_time-10;
			}

			if(rt==0 && p_arr[i].flag == 1)
			{
				no_of_processes -= 1;
				p_arr[i].completion_time = timer;
			}
		}
	}
	
	
	
}







void FCFS()
{
	int i;
	int time = 10;
	for(i=0;i<no_of_processes;i++)
	{
		if(p_arr[i].priority_group == 3 && p_arr[i].arrival_time <= timer)
		{
			int rt = p_arr[i].remaining_time;
			if(rt>0 && rt<=10)
			{
				timer+=rt;
				time -= rt;
				rt = 0;
				p_arr[i].remaining_time = 0;
				p_arr[i].flag = 1;
			}
			else
			{
				timer+=10;
				time -=10;
				p_arr[i].remaining_time = p_arr[i].remaining_time-10;
			}

			if(rt==0 && p_arr[i].flag == 1)
			{
				no_of_processes -= 1;
				p_arr[i].completion_time = timer;
			}
		}
	}	
	

	check();
	PriorityScheduling();
}



















void check()
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(p_arr[i].remaining_time==0)
		{
			count = count+1;
		}
	}
	if(count==n)
	{
		show();
	}
	else
	{
		if(counter == 1)
			RoundRobin();
		else if(counter == 2)
			PriorityScheduling();
		else if(counter == 3)
			FCFS();

	}
}
















void main()
{
	printf("Enter total number of processes : ");
	scanf("%d",&no_of_processes);
	n = no_of_processes;
	input(no_of_processes);
	check();
}


