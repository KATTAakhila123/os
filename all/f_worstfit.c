#include<stdio.h>
#include<stdlib.h>
int sum(int sb[],int v[],int b)
{ 
    int i,s=0;
	for(i=0;i<b;i++)
	{
		if(v[i]==0)
		{
			s = s+ sb[i];
		}
	}
	return s;
}
void main()
{
	int p,b,sp[10],sb[10],v[10],i,j,inf=0,max,indexi,indexj,total;
	printf("enter no of processes: ");
	scanf("%d",&p);
	printf("enter no of blocks: ");
	scanf("%d",&b);
	printf("enter size of processes: \n");
	for(i=0;i<p;i++)
	{
		scanf("%d",&sp[i]);
	}
	printf("enter size of blocks: \n");
	for(i=0;i<b;i++)
	{
		scanf("%d",&sb[i]);
		v[i]=0;
	}
	for(i=0;i<p;i++)
	{
	    max=INT_MIN;
	    int flag=0;
		for(j=0;j<b;j++)
		{
			if(sp[i]<=sb[j] && v[j]!=1)
			{
				if((sb[j]-sp[i])>max)
				{
					max=sb[j]-sp[i];
					indexi=i;
					indexj=j;
					flag=1;
				}
			}
		}
		if(flag==1)
		{
			printf("\np%d -b%d",indexi+1,indexj+1);
			inf=inf + sb[indexj]-sp[indexi];
			v[indexj]=1;
		}
		else
		{
		    total=sum(sb,v,b);
			if(sp[i]<=total)
			{
				printf("external fragmentation is %d",total);
			}
			else
			{
				printf("\n%d process should wait",i);
			}	
		}
	}
    printf("\ninternal fragmentation is %d",inf);
}
