#include<stdio.h>
#include<stdlib.h>
int s[100],a[10],temp[10],n,f;
void optimalpage()
{
	int npf=0,nph=0,i,j,l,k,count=0,c[10],v=0,id,min,max;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=f;j++)
		{
			if(a[j]==-1)
			{
				a[j]=s[i];
				npf++;
				count=count+1;
				c[j]=count;
				break;
			}
			else if(a[j]==s[i])
			{
				nph++;
				break;
			}
		}
		if(j>f)
		{
				for(l=1;l<=f;l++)
				{
					for(k=i+1;k<=n;k++)
					{
						if(a[l]==s[k])
						{
							temp[l]=k;//for storing the indexes from the refereced string 
							break;
						}
					}
					if(k>n)
					{
						temp[l]=INT_MAX;//if not there
					}
				}
			for(l=1;l<=f;l++)
				{
					if(temp[l]==INT_MAX)
					{
						v++;
					}
			}
			//when there is no more than one INT_MAX 
			if(v==0 || v==1)
			{
				max=INT_MIN;
				for(l=1;l<=f;l++)
				{
					if(max<temp[l])
					{
						max=temp[l];
						id=l;
					}
	
				}
			}
			//when there are more than one INT_MAX
			else
			{
					min=INT_MAX;
					for(l=1;l<=f;l++)
					{
						if(temp[l]==INT_MAX)
						{
							if(min>c[l])
							{
							min=c[l];
							id=l;
							}
						}	
	
					}
			}
			a[id]=s[i];
			count=count+1;
			c[id]=count;
			npf++;
			for(l=1;l<=f;l++)
			{
				temp[l]=0;
			}	
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
	optimalpage();
}
