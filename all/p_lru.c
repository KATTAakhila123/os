#include<stdio.h>
#include<stdlib.h>
int s[100],a[10],temp[10],n,f;
void lru()
{
	int npf=0,nph=0,i,j,c=100,l,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=f;j++)
		{
			if(a[j]==-1)
			{
				a[j]=s[i];
				npf++;
				c=c-1;
				temp[j]=c;
				break;
			}
			else if(a[j]==s[i])
			{
				nph++;
				c=c-1;
				temp[j]=c;
				break;
			}
		}
		if(j>f)
		{
			int max=INT_MIN;
			int maxid;
			for(l=1;l<=f;l++)
				{
					if(max<temp[l])
					{
						max=temp[l];
						maxid=l;
					}
	
				}
				a[maxid]=s[i];
				c=c-1;
				temp[maxid]=c;
				npf++;
		}
		for(l=1;l<=f;l++)
		{
					printf("\t %d",a[l]);
		}
		printf("\n");	
		}
	printf("\n number of page faults= %d and page hits= %d are",npf,nph);
}
int main()
{
	int i,j;
	printf("\n enter number of elements in referenced string");
	scanf("%d",&n);
	printf("\n neter number of frames");
	scanf("%d",&f);
	printf("\n enter referenced string");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(i=1;i<=f;i++)
	{
		a[i]=-1;
		temp[i]=0;
	}
	lru();
}
