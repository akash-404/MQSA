#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdbool.h>


int itr=1;
int time_track=0;
//int count=0;

typedef struct Process
{
	int process_id;
	int arrival_time;
	int burst_time;
	int remaining_time;
	int waiting_time;
	int turnaround_time;
	int completion_time;
	int queue_tag;
}pr;

int n;
int no_of_processes;

pr P[10];

void input(int);
void display();
void SRT_Algo();
void Round_Robin(int);
void scheduling();
void wt_tt();






int main()
{
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	no_of_processes = n;
	if(n>10)
	{
		printf("You have exceeded the max. limit of processes to be executed");
	}
	else
	{
		input(n);
	}
	return 0;
}





// Getting details for the process
void input(int a)
{
	int i;
	bool flag = true;
	printf("Enter the arrival time and Burst time for the processes\n"); //Taking input for burst time and arrival time
	for(i=0;i<a;i++)
	{
		printf("\tEnter for Process %d :",i+1);
		printf("Arrival Time:\t");
		scanf("%d",&P[i].arrival_time);
		printf("Burst Time:\t");
		scanf("%d",&P[i].burst_time);
		
		
		while(flag==true)
		{
			printf("Enter priority:\t1(High)    or    2(Low):\t");
			scanf("%d", &P[i].queue_tag);
			int a = P[i].queue_tag;
			if(a==1 || a==2)
				flag = false;
		}
		
		P[i].remaining_time = P[i].burst_time;
		P[i].process_id = i+1;
	
	}
	for(i=0;i<n;i++)
	{
		if(P[i].burst_time == 0)
		{
			P[i].completion_time = P[i].arrival_time;
		}
	}
	scheduling();
}






//schedule when to use which algorithm
void scheduling()
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(P[i].remaining_time==0)
		{
			count = count+1;
		}
	}
	if(count == n)
	{
		display();
	}
	else
	{
		SRT_Algo();
	}
}










//Shortest remaining job first algorithm
void SRT_Algo()
{
	int count_tag=0;
	int i;
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(P[j].burst_time>P[i].burst_time)
			{
				struct Process t = P[i];
				P[i] = P[j];
				P[j] = t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(P[i].queue_tag==0)
		{
			Round_Robin(i);
			count_tag = count_tag + 1;
		}
	}
	if(count_tag == 0)
	{
		if(P[i].queue_tag==1)
		{
			Round_Robin(i);
		}
	}
	scheduling();
}







//scheduling using round robin
void Round_Robin(int p_no)
{
	if(P[p_no].burst_time>=2 && P[p_no].arrival_time<=time_track)
	{
		time_track+=2;
		P[p_no].burst_time = P[p_no].burst_time-2;
			
		if(P[p_no].burst_time==0)
		{
			P[p_no].completion_time = time_track;
		}
	}
	else
	{
		if(P[p_no].arrival_time<=time_track)
		{
			time_track = P[p_no].burst_time+time_track;
			P[p_no].burst_time = 0;
			P[p_no].completion_time = time_track;
		}
		
	}	
}




//Calculating waiting time and turnaround time
void wt_tt()
{
	for(int i=0;i<n;i++)
	{
		P[i].turnaround_time = P[i].completion_time - P[i].arrival_time;
		P[i].waiting_time = P[i].turnaround_time - P[i].burst_time;
	}
}


//Display the final scheduling
void display()
{
	wt_tt();
	int avg_wt=0, avg_tat=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(P[j].process_id>P[i].process_id)
			{
				struct Process t = P[i];
				P[i] = P[j];
				P[j] = t;
			}
		}
	}
	printf("P_Id\tArrival_Time\tBurst_Time\tWaiting_Time\tTurn_Around_Time\tCompletion_Time\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",P[i].process_id,P[i].arrival_time,P[i].burst_time,P[i].waiting_time,P[i].turnaround_time,P[i].completion_time);
		avg_wt += P[i].waiting_time;
		avg_tat += P[i].turnaround_time;
	}
	printf("\n\n Average Waiting Time : %d\n Average Turn Around Time : %d",avg_wt/n,avg_tat/n);
}
























