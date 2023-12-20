#include<stdio.h>
#include<limits.h>
int a[20],b[20],c[20],p,visit[20],sec=0,pr[20],temp[20];
int FindMin()
{
	int i,v=0,k=0,process=0, min=INT_MAX,pmin=INT_MAX;		
	for(i=0;i<p;i++)
	{
		if(a[i]<=sec && visit[i]!=1)
		{
			v++;
		}
	}	
	if(v==0)						
	{
		for(i=0;i<p;i++)
		{
			if(visit[i]!=1 && a[i]<min)
			{
				k=i;
				min=a[i];	
			}
			else if(visit[i]!=1 && a[i]==min)
			{
				if(pr[i]<pr[k])
				{
					min=a[i];
					k=i;
				}
			}
		}
		return k;
	}
	else
	{
		for(i=0;i<p;i++)
		{
			if(visit[i]!=1 && pr[i]<pmin && a[i]<=sec)
			{
				process=i;
				pmin=pr[i];
			}
			else if(visit[i]!=1 && pr[i]==pmin && a[i]<=sec)
			{
				if(a[i]<a[process])
				{
					process=i;
					pmin=pr[i];
				}
			}
		}
	}
	return process;
}
void priority()
{
	int i,k=0,TAT[20],WT[20],x,totwt=0,totta=0;
	float awt,ata;
	for(i=0;i<p;i++)
	{
		x=FindMin();
		//ideal case
		if(a[x]>sec)
		{
			temp[k++]=100;
			sec=sec+(a[x]-sec);
		}
		visit[x]=1;
		temp[k++]=x+1;
		sec=sec+b[x];
		c[x]=sec;
	}
	for(i=0;i<p;i++)
	{
		TAT[i]=c[i]-a[i];
		WT[i]=TAT[i]-b[i];
	}
	printf("\nP\tpr\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<p;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",i+1,pr[i],a[i],b[i],c[i],TAT[i],WT[i]);
	}
	printf("\n gantt chart is\n");
	for(i=0;i<k;i++)
	{
		printf("%d ",temp[i]);
	}
	for(i=0; i<p; i++)
    {
    	totwt=totwt+WT[i];
    	totta=totta+TAT[i];
    }
	awt=(float)totwt/p;
    ata=(float)totta/p;
	printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);	
}
void main()
{
	int i;
	printf("Enter no.of processes: ");
	scanf("%d",&p);
	printf("Enter prority no(pr) ,Arrival times(AT) and Burst times(BT) of processes\n");
	for(i=0;i<p;i++)
	{
		scanf("%d %d %d",&pr[i],&a[i],&b[i]);
	}
	for(i=0;i<p;i++)
	{
		visit[i]=0;
	}
	priority();
}
