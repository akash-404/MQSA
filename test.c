#include<stdio.h>

int main()
{
      int i, n , total = 0, x, counter = 0, time_quantum=2,j;

      int wait_time = 0, turnaround_time = 0,pos,z,p[10],priority[10], arrival_time[10], burst_time[10], temp[10],b;

      float average_wait_time, average_turnaround_time;

      printf("\nEnter Total Number of Processes:");

      scanf("%d", &n);

      x = n;
      for(i = 0; i < n; i++)
      {
        p[i]=i+1;

        priority[i]=0;
            printf("\nEnter total Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]);
            temp[i] = burst_time[i];
      }


      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(total = 0, i = 0; x != 0;)
      {

            for(z=0;z<n;z++)
            {
            int temp1;
            pos=z;
            for(j=z+1;j<n;j++)
            {
                if(priority[j]<priority[pos])
                pos=j;
            }

        temp1=priority[z];

        priority[z]=priority[pos];

        priority[pos]=temp1;

            temp1=burst_time[z];
            burst_time[z]=burst_time[pos];
            burst_time[pos]=temp1;
                    temp1=arrival_time[z];
                arrival_time[z]=arrival_time[pos];
            arrival_time[pos]=temp1;

            temp1=p[z];
                p[z]=p[pos];
            p[pos]=temp1;

            temp1=temp[z];
                temp[z]=temp[pos];
            temp[pos]=temp1;
            }
        {
        }

            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }

            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }

    for(b=0;b<n;b++)
        {
            if(b==i)
            priority[b]+=1;
            else
            priority[b]+=2;
        }

            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t%d", p[i], burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i],priority[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == n - 1)
            {
                  i = 0;

            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;

            }
            else
            {
                  i = 0;

            }
      }
      return 0;
}
