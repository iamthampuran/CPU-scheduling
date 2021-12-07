#include<stdio.h>

struct process{
 int pid,tat,bt,wt,at,pr,bt_rem,completed;
 }a[10];

 int queue[20],r=-1,f=-1;

 void enqueue(int i)
 {
	  if (r == 19)
        printf("Queue full");

    if (f == -1 && r == -1)
    {
        f = r = 0;
        queue[r] = i;
    }
    else
    {
        r++;
        queue[r] = i;
    }
 }

int dequeue()
{
    if (f == -1 && r == -1)
        return -1;
    if (f == r)
    {
        int data = queue[f];
        f =  r= -1;
        return data;
    }
    else
    {
        return queue[f++];
    }
}

int exists_in_Queue(int p)
{
    for (int i = f; i <= r; i++)
    {
        if (queue[i] == p)
            return 1;
    }
    return 0;
}



 void swap(int i, int j)
 {
 	struct process temp;
 	temp = a[i];
 	a[i] = a[j];
 	a[j] = temp;
 }	
 
 
 void fcfs()
 {
 	printf("\nFCFS\n____\n");
 	int i,j,n;
	 printf("Enter the no of processes(max 10): ");
	scanf("%d",&n);
	printf("Enter: \n");
	for(i=0;i<n;i++)
	{
		a[i].pid = i+1;
		printf("P%d\n",i+1);
		printf("Burst Time: ");
		scanf("%d",&a[i].bt);
		printf("Arrival Time: ");
		scanf("%d",&a[i].at);
		a[i].bt_rem = a[i].bt;

	}
 	for(i=0;i<n-1;i++)
 		for(j=0;j<n-i-1;j++)
 		{
 			if(a[j+1].at<a[j].at)
 				swap(j,j+1);
 		}
 	a[0].wt = 0;
 	a[0].tat = a[0].bt;
 		
 	for(i=1;i<n;i++)
 	{
		if(a[i].at==a[i-1].at)
			a[i].wt = a[i-1].tat;
		else	
 			a[i].wt = a[i-1].tat - a[i].at;
 		a[i].tat = a[i].bt + a[i].wt;
 	}	
 		
 	printf("Pid\tBurst Time\tWaiting Time\tArrival Time\tTurn around time\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",a[i].pid,a[i].bt,a[i].wt,a[i].at,a[i].tat);
	}
	
}	
	
void sjf()
{
	printf("\nSJF\n___\n");
 	int i,j,n;
	 printf("Enter the no of processes(max 10): ");
	scanf("%d",&n);
	printf("Enter: \n");
	for(i=0;i<n;i++)
	{
		a[i].pid = i+1;
		printf("P%d\n",i+1);
		printf("Burst Time: ");
		scanf("%d",&a[i].bt);
		a[i].bt_rem = a[i].bt;

	}
 	for(i=0;i<n-1;i++)
 		for(j=0;j<n-i-1;j++)
 		{
 			if(a[j+1].bt<a[j].bt)
 				swap(j,j+1);
 		}
 	
 	a[0].wt = 0;
 	a[0].tat = a[0].bt;
 		 		
 	for(i=1;i<n;i++)
 	{
		a[i].wt = a[i-1].tat;
 		a[i].tat = a[i].bt + a[i].wt;
 	}	
 	
 	printf("Pid\tBurst Time\tWaiting Time\tTurn around time\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t\t%d\t\t%d\n",a[i].pid,a[i].bt,a[i].wt,a[i].tat);
	}
 		
 		
}
void prio()
{
	printf("\nPRIORITY\n--------\n");
	int i,j,n;
	 printf("Enter the no of processes(max 10): ");
	scanf("%d",&n);
	printf("Enter: \n");
	for(i=0;i<n;i++)
	{
		a[i].pid = i+1;
		printf("P%d\n",i+1);
		printf("Burst Time: ");
		scanf("%d",&a[i].bt);
		a[i].bt_rem = a[i].bt;
		printf("Enter the priority of P%d (burst time = %d): ",a[i].pid,a[i].bt);
		scanf("%d",&a[i].pr);

	}
	
	for(i=0;i<n-1;i++)
 		for(j=0;j<n-i-1;j++)
 		{
 			if(a[j+1].pr<a[j].pr)
 				swap(j,j+1);
 		}
 	
 	a[0].wt = 0;
 	a[0].tat = a[0].bt;
 		 		
 	for(i=1;i<n;i++)
 	{
		a[i].wt = a[i-1].tat;
 		a[i].tat = a[i].bt + a[i].wt;
 	}	
 	
 	printf("Pid\tBurst Time\tWaiting Time\tTurn around time\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t\t%d\t\t%d\n",a[i].pid,a[i].bt,a[i].wt,a[i].tat);
	}
	
}


void rr()
{
	int i,j,n,k,tq,timer,avg_t_time = 0, avg_w_time = 0;
	printf("\nROUND ROBIN\n-----------\n");
	printf("Enter the no of processes(max 10): ");
	scanf("%d",&n);
	printf("Enter: \n");
	for(i=0;i<n;i++)
	{
		a[i].pid = i+1;
		printf("P%d\n",i+1);
		printf("Burst Time: ");
		scanf("%d",&a[i].bt);
		printf("Arrival Time: ");
		scanf("%d",&a[i].at);
		a[i].bt_rem = a[i].bt;

	}
	for(i=0;i<n-1;i++)
 		for(j=0;j<n-i-1;j++)
 		{
 			if(a[j+1].at<a[j].at)
 				swap(j,j+1);
 		}
	printf("Enter the time quantumn: ");
	scanf("%d",&tq);
	    enqueue(0);

    timer = a[0].at;
    while (1)
    {
        int i = dequeue();
        if (i == -1)
            break;

        if (a[i].bt_rem <= tq)
        {

            timer += a[i].bt_rem;
            a[i].bt_rem = 0;
            a[i].completed = 1;

            a[i].wt = timer - a[i].at - a[i].bt;
            a[i].tat = timer - a[i].at;

            avg_t_time += a[i].tat;
            avg_w_time += a[i].wt;

            for (int j = 0; j < n; j++)
            {
                if (a[j].at <= timer && a[j].completed != 1 && exists_in_Queue(j) != 1)
                {
                    enqueue(j);
                }
            }
        }
        else
        {
            timer += tq;
            a[i].bt_rem -= tq;

            for (int j = 0; j < n; j++)
            {
                if (a[j].at <= timer && a[j].completed != 1 && i != j && exists_in_Queue(j) != 1)
                {
                    enqueue(j);
                }
            }
            enqueue(i);
        }
    }
		
 	printf("Pid\tBurst Time\tWaiting Time\tArrival Time\tTurn around time\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",a[i].pid,a[i].bt,a[i].wt,a[i].at,a[i].tat);
	}
	

		
}
	 				

int main()
{
	int ch;
	
	while(1)
  {
	printf("Which algorithm do you want? \n1.FCFS\n2.SJF\n3.Priority\n4.Round Robin\n5.Exit\nEnter your choice: ");
	scanf("%d",&ch);	
	switch(ch)
	{
		case 1: fcfs();
		break;
		case 2: sjf();
		break;
		case 3: prio();
		break;
		case 4: rr();
		break;
		case 5: return 0;
		default: printf("Wrong choice!!!! \n");
	}
   }
  }	
