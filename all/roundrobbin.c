#include<stdio.h>
#include<stdlib.h>
#define max 100
int q[max];
int f=-1;
int r=-1;
int check_rq(int k)
{
	int i;
	for(i=f+1;i<=r;i++) 
	{
		if(q[i]==k)
		{
			return 1;
		}
	}
	if(i>r)
	{
		return 0;
	}
}
int check_g(int k,int g[],int j)
{
	if(j!=0)
	{
		if(g[j-1]!=100)
		{
			if(g[j-1]==k)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}	
}
void enq(int data)
{
	if(r>=max)
	{
		printf("\nqueue overflow:");
	}
	else
	{
		r++;
		q[r]=data;
	}
}
int deq()
{
	if(r==-1 || f>=r)
	{
		printf("\nqueue underflow");
	}
	else
	{
		f++;
		return q[f];
	}
}
void display()
{
	int i;
	printf("\nqueue=");
	for(i=f+1;i<=r;i++)
	{
		printf(" %d ",q[i]);
	}
}
void swap(int a[],int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int main()
{
	int n,i,j;
	printf("\nenter no of processes:");
	scanf("%d",&n);
	int p[n],at[n],bt[n],ct[n],tat[n],wt[n],visit[n],g[100],t[n];
	printf("\nProcess_ID  AT	BT\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&p[i],&at[i],&bt[i]);
		visit[i]=0;
	}
	for(i=0;i<n;i++)
	{
		t[i]=bt[i];
	}
	int tq;
	printf("\nenter time quantum:");
	scanf("%d",&tq);	
	for(i=0;i<n-1;i++)
	{
		for(j=1;j<n;j++)
		{
			if(at[j-1]>at[j])
			{
				swap(at,j-1,j);
				swap(bt,j-1,j);
				swap(p,j-1,j);
			}
		}
	}
	printf("\n");
	int count=0,c=0;
	j=0;
	while(count!=n)
	{
		int min=INT_MAX;
		int idle=INT_MAX;
		int flag=0;
		for(i=0;i<n;i++)
		{
			if(at[i]<=c && visit[i]!=1)
			{
				flag=1;
				if(check_rq(i)!=1 && check_g(i,g,j)!=1)
				{
					enq(i);
				}
			}
			else if(visit[i]!=1)
			{
				if(idle>at[i])
				{
					idle=at[i];
				}
			}
		}
		if(j!=0 && g[j-1]!=100)
		{
			if(visit[g[j-1]]!=1)
			{
				enq(g[j-1]);

			}
		}
		if(flag==0)
		{
			c=idle;
			g[j++]=100;
		}
		else
		{
			int k;
			k=deq();
			g[j++]=k;
			if(bt[k]<=tq)
			{
				visit[k]=1;
				count++;
				c=c+bt[k];
				bt[k]=0;
				ct[k]=c;
			}
			else
			{
				bt[k]=bt[k]-tq;
				c=c+tq;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
	}
	for(i=0;i<n;i++)
	{
			wt[i]=tat[i]-t[i];
	}
	int ttat=0,twt=0;
	for(i=0;i<n;i++)
    {
		ttat=ttat+tat[i];
    }
    for(i=0;i<n;i++)
    {
    	twt=twt+wt[i];
	}
    float awt=0.0,atat=0.0;
    atat=(float)ttat/n;
    awt=(float)twt/n;
	printf("\n");printf("\nProcess_ID   AT	BT	CT	TAT	WT	");
	for(i=0;i<n;i++)
	{
		printf("\n %d  	%d	%d	%d  %d	%d",p[i],at[i],t[i],ct[i],tat[i],wt[i]);
	}
	printf("\n");
	printf("\nGanTT CharTT:\n");
	for(i=0;i<j;i++)
	{
		if(g[i]==100)
		{
			printf("idle");
		}
		else
			printf(" %d ",p[g[i]]);
	}
	printf("\nAvg Waiting time %f",awt);
	printf("\nAvg turn around time is %f",atat);
}
