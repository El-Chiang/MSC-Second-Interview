#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main ()
{
	srand((unsigned)time (NULL));										//调用当前时间作为随机种子
	int i,new_car,new_car_place,space[20];								//20辆车存入数组space中，1-7为停车位，8，9为等候位
	void situation(int space[]);
	void swap(int *pm ,int *pn);										// 交换数组中两辆车的位置

	for(i=1;i<=20;i++){													//20辆车按序排放
		space[i]=i;
	}
	for(i=20;i>=1;i--){													//20辆车随机打乱
		swap(&space[i],&space[rand()%20+1]);
	}

	printf("刚开始停车及等候情况如下所示:\n\n");
	situation(space);
	printf("\n请输入第一个既不在停车位又不在等候位车辆的车牌号:\n");
	scanf("%d",&new_car);
	for(i=1;i<=9;i++){													//判断输入车辆是否既不在停车位又不在等候位上
		if(new_car!=space[i]) continue;
		printf("您所输入的车辆已处在停车位或者等候位上，请重新输入\n");
		scanf("%d",&new_car);
		i=1;
	}
	
	for(i=1;i<=20;i++){													//得到输入车辆在数组中的位置
		if(space[i]==new_car) new_car_place=i;
	}

	if(abs(new_car-space[8]) <= abs(new_car-space[9])){					//停车位上随机退出一辆车，等候位的车进入，输入车辆进入等候位
		swap(&space[rand()%7+1],&space[8]);
		swap(&space[8],&space[new_car_place]);
	}
	else{
		swap(&space[rand()%7+1],&space[9]);
		swap(&space[9],&space[new_car_place]);
	}
	printf("\n第一次变换后停车及等候情况如下所示:\n\n");
	situation(space);

	new_car=space[rand()%11+10];												//从数组10到20的位置随机挑选一辆车作为new_car
	printf("\n随机出的第二辆既不在停车位又不在等候位车辆的车牌号为： %d \n",new_car);
	if(abs(new_car-space[8]) <= abs(new_car-space[9])){
		swap(&space[rand()%7+1],&space[8]);
		swap(&space[8],&space[new_car_place]);
	}
	else{
		swap(&space[rand()%7+1],&space[9]);
		swap(&space[9],&space[new_car_place]);
	}

	printf("\n第二次变换后停车及等候情况如下所示:\n\n");
	situation(space);

	new_car=space[rand()%11+10];
	printf("\n随机出的第三辆既不在停车位又不在等候位车辆的车牌号为： %d \n",new_car);
	if(abs(new_car-space[8]) <= abs(new_car-space[9])){
		swap(&space[rand()%7+1],&space[8]);
		swap(&space[8],&space[new_car_place]);
	}
	else{
		swap(&space[rand()%7+1],&space[9]);
		swap(&space[9],&space[new_car_place]);
	}
	printf("\n第三次变换后停车及等候情况如下所示:\n\n");
	situation(space);

	return 0;
	
}

void swap(int *pm ,int *pn)
{
	int  temp;
	temp= *pm;
	*pm = *pn;
	*pn =temp;
}

void situation(int space[])
{
	printf("停车位 A  上所停的车牌号为 %d \n",space[1]);
	printf("停车位 B  上所停的车牌号为 %d \n",space[2]);
	printf("停车位 C  上所停的车牌号为 %d \n",space[3]);
	printf("停车位 D  上所停的车牌号为 %d \n",space[4]);
	printf("停车位 E  上所停的车牌号为 %d \n",space[5]);
	printf("停车位 F  上所停的车牌号为 %d \n",space[6]);
	printf("停车位 G  上所停的车牌号为 %d \n",space[7]);
	printf("等候位 一 上所停的车牌号为 %d \n",space[8]);
	printf("等候位 二 上所停的车牌号为 %d \n",space[9]);
}
