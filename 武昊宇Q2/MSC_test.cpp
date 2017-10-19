#include<cstdio>
#include<cstring>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int pos[8];
int car[21];
int que[2];
int abs(int x)
{
	if(x>=0)return x;
	else return -x;
}
int main()
{
	memset(pos,0,sizeof(pos));
	memset(car,0,sizeof(car));
	srand((unsigned)time(NULL));
	int x;
	for(int i=0;i<=1;i++)
	{
		while(1)
		{
			x=rand()%20+1;
			if(car[x]>0)continue;
			else
			{
				que[i]=x;
				car[x]=99999;//在队列中
				break; 
			}
		}
	}
	for(int i=1;i<=7;i++)
	{
		while(1)
		{
			x=rand()%20+1;
			if(car[x]>0)continue;
			else
			{
				car[x]=i;
				pos[i]=x;
				break;
			} 
		}
	}
	printf("car %d %d was in line\n",que[0],que[1]);
	for(int i=1;i<=7;i++)
		printf("pos[%d]=%d\n",i,pos[i]); 
	int T=2;
	while(T--)
	{
		printf("it's the %d time to do\n",2-T);
		while(1)
		{
			x=rand()%20+1;
			if(car[x]>0)continue;
			else break;
		} 
		int a=abs(que[0]-x),b=abs(que[1]-x),in;
		if(a>b)in=1;
		else in=0;
		int outid=0,outpos=0,temp=99999;
		for(int i=1;i<=7;i++)
		{
			if(temp>abs(pos[i]-x))
			{
				temp=abs(pos[i]-x);
				outid=pos[i];
				outpos=i;
			}	
		}
		printf("car %d out\ncar %d in\n",outid,que[in]);
		car[outid]=que[in];
		car[outid]=0;
		pos[outpos]=que[in];
		for(int i=1;i<=7;i++)
		{
			printf("pos[%d]=%d\n",i,pos[i]);
		}
		while(1)
		{
			x=rand()%20+1;
			if(car[x]>0)continue;
			else break;
		}
		que[in]=x;
	}
	return 0;
} 
