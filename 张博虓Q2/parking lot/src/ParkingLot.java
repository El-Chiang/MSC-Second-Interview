import java.util.Scanner;

public class ParkingLot {
    public static void main(String[] args) {
    	int lot[]=new int[10];//this array records the car numbers in the lot(step 1)
    	char cars[]=new char[30];//this array records the state of cars(step 2)
    	int m,a,b,temp,inp,randomly;
    	for (int i=0;i<20;i++) {
    		cars[i]='0';//initialize the array
    	}
    	System.out.println("the cars that are initially in the parking lot");
    	for(int i=0;i<7;i++) {
    		//this part(line 13 to 23) is to realize the step 3
    		m=ParkingLot.NewCar(cars);
    		lot[i]=m;
    		cars[m]=(char)(i+17);//'0' to '6' convert into 'A' to 'G'
    		System.out.print(lot[i]+1);
    		System.out.print("  ");
    	}
    	a=ParkingLot.NewCar(cars);
    	cars[a]='w';//'w' means waiting
    	b=ParkingLot.NewCar(cars);
    	cars[b]='w';
    	System.out.println();
    	System.out.println("the cars that are waiting");
    	//every number in this program needs to subtract 1 because the array is from 0
    	System.out.print(a+1);
    	System.out.print("  ");
    	System.out.println(b+1);
    	//the initialization finished here
    	//step 4 begins
    	System.out.println("please input a legal number");
    	//input through the keyboard(step 4(1))
    	inp=ParkingLot.Scanning();
        inp-=1;
    	temp=ParkingLot.Judge(a, b, inp);
    	//replace the old number with the newly created number
    	if (temp==a) {
    		a=inp;
    	}
    	else {
    		b=inp;
    	}
    	ParkingLot.Change(cars,lot,temp);
    	ParkingLot.OnScreen(lot,a,b);
    	randomly=ParkingLot.NewCar(cars);
    	//this time is a random number(step 5, the second arrangement)
    	System.out.print("the random number in the second arrangement is ");
    	System.out.println(randomly+1);
    	temp=ParkingLot.Judge(a, b, randomly);
    	if (temp==a) {
    		a=randomly;
    	}
    	else {
    		b=randomly;
    	}
    	ParkingLot.Change(cars,lot,temp);
    	ParkingLot.OnScreen(lot,a,b);
    	randomly=ParkingLot.NewCar(cars);
    	//repeat once(the third arrangement)
    	System.out.print("the random number in the third arrangement is ");
    	System.out.println(randomly+1);
    	temp=ParkingLot.Judge(a, b, randomly);
    	if (temp==a) {
    		a=randomly;
    	}
    	else {
    		b=randomly;
    	}
    	ParkingLot.Change(cars,lot,temp);
    	ParkingLot.OnScreen(lot,a,b);
    }
    public static int NewCar(char[] x) {
    	//this method is to randomly create a legal car number
    	int temp;
    	do{
    	    temp=(int)(Math.random()*20);
    	}while(x[temp]!='0');//if the value is the initial value,it's a legal car number
    	return temp;
    }
    public static int Judge(int a,int b,int c){
    	//this method is to realize the step 4(2)
    	int temp;
    	if (Math.abs(a-c)>Math.abs(b-c)){
    		temp=b;
    	}
    	else {
    		temp=a;
    	}
    	return temp;
    }
    public static void Change(char[] x,int[] y,int a) {
    	//this method is to realize the step 4(3)
    	int temp;
    	temp=(int)(Math.random()*7);
    	y[temp]=a;
		x[a]=(char)(temp+65);
    }
    public static void OnScreen(int[] y,int a,int b) {
    	//put the result on the screen
    	System.out.println("the cars in the parking lot after the arrangement");
    	for(int i=0;i<7;i++) {
    		System.out.print(y[i]+1);
    		System.out.print("  ");
    	}
    	System.out.println();
    	System.out.println("the cars that are waiting");
    	System.out.print(a+1);
    	System.out.print("  ");
    	System.out.println(b+1);
    }
    public static int Scanning() {
    	//this method is to get the input message
    	Scanner s=new Scanner(System.in);
    	int temp=s.nextInt();
    	return temp;
    }
}