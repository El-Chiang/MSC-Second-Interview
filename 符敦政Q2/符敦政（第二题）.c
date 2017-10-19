#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int parking[10],wait[3],random[20];
	int  i,t,tt,s,j,n;
	
	srand(time(0));
	printf("Parking cars: ");
	for (i=1;i<=12;i++)
	{
		n=rand()%20+1;
		for (j=0;j<i;j++)
		{
			if (n==random[j]) 
			{
				i--;
				break;
			}
		}	
		if (j>=i) random[i]=n;
	}
	for (i=1;i<=9;i++)
	{
		if (i<=7) 
		{
			parking[i]=random[i];
			printf("%02d ",parking[i]);
		}
		else wait[i-7]=random[i];
	}                                                        //随机输入数据        
	printf("\nWait cars: ");
	for (i=1;i<=2;i++) printf("%02d ",wait[i]);
	printf("\n");
	
    s=1;
    while (s<=3)
	{
		printf("\nA new car number: %02d\n",random[9+s]);
		t=99999;
    	for (i=1;i<=2;i++)
    	{
    		if (abs(random[9+s]-wait[i])<t&&wait[i]>0)       
    		{
    			t=abs(random[9+s]-wait[i]);
    			tt=i;
			}
		}                                                   //寻找编号最近的车辆 
		parking[s]=wait[tt];                  
		wait[1]=wait[2+1-tt];
		wait[2]=random[9+s];                                //替换当前车辆 
		printf("Parking cars: ");
		for (i=1;i<=7;i++)
		{
			printf("%02d ",parking[i]);
    	}
    	printf("\nWait cars: ");
		for (i=1;i<=2;i++) printf("%02d ",wait[i]);
		printf("\n");                                       //程序输出结果 
    	s++;
	}
	
	return 0;
}
