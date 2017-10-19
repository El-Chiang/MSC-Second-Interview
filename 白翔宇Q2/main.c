#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <string.h>
//This is the parking lot
struct ParkingLot
{
char Spaces[7];
int CarNo[9];
int Waits[2];  //waiting cars
}Lot;

int main()
{
    int Cars[20];  //all cars
    int Without9[11];//after choose 9 cars
    char GiveAlpha='A';
    int i,j;
    int Neither;
    int Compare1,Compare2;
    int temp1,temp2;
    for(i=0;i<20;i++)
    {
    Cars[i]=i+1;
    }//give cars nums
    for(i=0;i<7;i++)
    {
    Lot.Spaces[i]=GiveAlpha;
    GiveAlpha++;
    }//give parking lot Nos
    //srand((unsigned)time(NULL));
    srand((unsigned)time(NULL));
    for(i=0;i<9;i++)
    {
    Lot.CarNo[i]=rand()%20+1;
    printf("现在正在随机选取车辆，请至少等待20秒");
    system("pause");
    }//pick up 9 cars
    Lot.Waits[0]=Lot.CarNo[7];
    Lot.Waits[1]=Lot.CarNo[8];
    for(i=0;i<20;i++)
    {
         for(j=0;j<9;j++)
         {
              if(Cars[i]==Lot.CarNo[j]);
              {
                  Cars[i]=-1;
                  temp2=i;
              }
         }
    }
    j=0;
    for(i=0;i<20;i++)
    {
        if(Cars[i]!=-1)
        {
            Without9[j]=Cars[i];
            j++;
        }
    }
    srand((unsigned)time(NULL));
    for(i=0;i<3;i++)
    {
        Neither=rand()%11;//Get a int from 0-10
        Compare1=Without9[Neither]-Lot.Waits[0];
        Compare2=Without9[Neither]-Lot.Waits[1];
        if(Compare1<0)
        {
            Compare1=-Compare1;
        }
        if(Compare2<0)
        {
            Compare2=-Compare2;
        }
        //Compare1=Abs(Without9[Neither]-Lot.Waits[0]);
        //Compare2=Abs(Without9[Neither]-Lot.Waits[1]);
        if(Compare1>Compare2)
        {
            //means that "neither" is close to waits[1]
            temp1=Lot.CarNo[6];
            Lot.CarNo[6]=Lot.Waits[1];
            Cars[temp2]=temp1;
        }
        else
        {
            //means that "neither" is close to waits[0]
            temp1=Lot.CarNo[6];
            Lot.CarNo[6]=Lot.Waits[0];
            Cars[temp2]=temp1;
        }
    }
    return 0;
}
