#include <stdlib.h>
#include<time.h>
#include<math.h>
#include<stdio.h>
void main( )
{int A,B,C,D,E,F,G,a,b,A1,B1,C1,D1,E1,F1,G1,a1,b1,m,X,Y,c,i;
	A=rand()%20+1;
    B=rand()%20+1;
    C=rand()%20+1;
    D=rand()%20+1;
    E=rand()%20+1;
    F=rand()%20+1;
    G=rand()%20+1;
    a=rand()%20+1;
    b=rand()%20+1;
    while (B==A)
          B=rand( )%20+1;
    while (C==B , C==A)
          C=rand()%20+1;
    while (D==A,D==B,D==C)
     D=rand()%20+1;
    while (E==A,E==B,E==C,E==D)
     E=rand()%20+1;
     while (F==A||F==B||F==C||F==D||F==E)
     F=rand()%20+1;
    while (G==A||G==B||G==C||G==D||G==E||G==F)
    G=rand()%20+1;
    while (a==A||a==B||a==C||a==B||a==C||a==D||a==E||a==F||a==G) 
     a=rand()%20+1;
     while (b==A||b==B||b==C||b==D||b==E||b==F||b==G||b==a)
     b=rand()%20+1;
	printf (" A=%d B=%d C=%d D=%d E=%d F=%d G=%d a=%d b=%d\n" ,A,B,C,D,E,F,G,a,b);
	/*以上随机构建了初始情况，a，b代表正在等的两辆车，A~G是车位，数字代表车*/
  for (i=0;i<3;i++)
    {m=rand()%20+1;
   while (m==A||m==B||m==C||m==D||m==E||m==F||m==G||m==a||m==b)
   m=rand()%20+1;//m是随机生成新车号
       A1=m-A,B1=m-B,C1=m-C,D1=m-D,E1=m-E,F1=m-F,G1=m-G,a1=m-a,b1=m-b;
	   A1= abs(A1),B1=abs(B1),C1=abs(C1),D1=abs(D1),E1=abs(E1),F1=abs(F1),G1=abs(G1),a1=abs(a1),b1=abs(b1);//求各车与新车号码差
	   if (a1<b1)
	       c=a,a=m;//c是为了统一被取代的两种情况
	   else
     	   c=b, b=m;//使等待中号码小的被新车取代
     	   X=A1;
	   if (B1<X)
    	   X=B1;
	   if (C1<X)
    	   X=C1;
	   if (D1<X)
    	   X=D1;
	   if (E1<X)
   	   X=E1;
	   if (F1<X)
    	   X=F1;
	   if (G1<X)
    	   X=G1;//以上确定了差最小为X
	   if (A1==X)
    	   A=c;
	   if (B1==X)
    	   B=c;
	   if (C1==X)
    	   C=c;
	   if (D1==X)
    	   D=c;
	   if (E1==X)
    	   E=c;
	   if (F1==X)
    	   F=c;
	   if (G1==X)
    	   G=c;//以上确定了X是哪一个车位，并被等待的车取代
	   printf(" A=%d B=%d C=%d D=%d E=%d F=%d G=%d a=%d b=%d m=%d\n",A,B,C,D,E,F,G,a,b,m);
	   }
	   return 0;
}
/*那些printf是输出了初始每个车位及等待的两辆车的车号，已经三次随机后的取代结果*/
/*学长学姐网开一面啊*/