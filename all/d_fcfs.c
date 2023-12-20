#include<stdio.h>
#include<math.h>
int n,a[100],in,end,s=0,st,h=0;
void check();
int main(){	
	printf("enter number of tracks");
	scanf("%d",&n);
	printf("starting track position");
	scanf("%d",&in);
	printf("ending track position");
	scanf("%d",&end);
	while(s<n){
		printf("enter %d track",s+1);
		scanf("%d",&a[s]);
		if(a[s]>in&&a[s]<end){
			s++;
		}
		
	}
	printf("head track");
	scanf("%d",&st);
	check();
}
void check(){
	int i;
	printf("order of sequence :");
	printf("%d ",st);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	for( i=0;i<n;i++){
		h=h+abs(st-a[i]);
		st=a[i];
	}

	printf("\nnumber of heads moments:  ");
	printf("%d ",h);
}

	
	
