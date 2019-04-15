#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int no_of_processes = 0; 
int counter=1;

//Queues
int q1_no,q2_no,q3_no;
//q1 = Round Robin Scheduling algorithm
//q2 = Priority Scheduling algorithm
//q3 = FCFS scheduling algorithm


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
	int flag;
};


//List of functions used
void check_algo();
void input();
void FCFS();
void PriorityScheduling();
void RoundRobin(struct p_info[]);
void show(struct p_info[]);


/*void check_algo()
{
	if(counter==1)
		RoundRobin(struct p_info P);
	else if(counter == 2)
		PriorityScheduling();
	else if(counter == 3)
		FCFS();
		
}
*/



void input(struct p_info p_arr[])
{
	int i = 0;
	
	
	for(i=0; i<no_of_processes; i++)
	{
		bool flag = true;
		printf("Enter process id:\t");
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



	///////////////	sorting	//////////
	int j;
	for(i=0;i<no_of_processes-1;i++)
	{
		for(j=0; j<no_of_processes-i-1;j++)
		{
			if(p_arr[j].arrival_time > p_arr[j+1].arrival_time)
			{
				struct p_info temp = p_arr[j];
				p_arr[j] = p_arr[j+1];
				p_arr[j+1] = temp;
			}
		}	
	}


}


void show(struct p_info p_arr[])
{
	int i = 0;
	for(i=0; i<no_of_processes; i++)
	{
		printf("Process ID: %d\t",p_arr[i].pid);
		printf("priority : %d\t",p_arr[i].priority);
		printf("burst time: %d\t", p_arr[i].burst_time);
		printf("arrival time: %d\t",p_arr[i].arrival_time);
		printf("Priority Group: %d",p_arr[i].priority_group);
		printf("\n");		

	}

	
}


/*void RoundRobin(struct p_info P)
{
	struct p_info p_arr = P;
	int time_quantum = 4;
	struct p_info* ptr;
	int i = 0, time = 0;
	for(i=0;i<no_of_processes && time<10;i++)
	{
		if(p_arr[i].priority_group == 1)
		{
			int rt = p_arr[i].remaining_time;
			if(rt <= time_quantum && rt>0)
			{
				time+=rt;
				rt = 0;
				p_arr[i].remaining_time = 0;
				p_arr[i].flag = 1;
			}
			else if(rt>0)
			{
				rt = rt-time_quantum;
				p_arr[i].remaining_time -= time_quantum;
				time+=time_quantum;

			}

			if(rt==0 && p_arr[i].flag == 1)
			{
				no_of_processes -= 1;
			}
		}
	}
}

*/


void main()
{
	printf("Enter total number of processes : ");
	scanf("%d",&no_of_processes);
	struct p_info p_arr[no_of_processes];
	input(p_arr);
	int i = 3;
	/*sort_arrival();
	while(no_of_processes>0)
	{
		check_algo();
	}
	*/
	show(p_arr);
}
