//#define debug

using System;
using System.Collections.Generic;

namespace ParkingLot
{
	class Program
	{
		static void Main(string[] args)
		{
			// Some arrays and collections used in this demo app might not be fully encapsulated. 
			// This is justifiable since this app is used for demonstration only. 
			//
			// Some commented code is written for code extensibility, for which implementation is not requested. 

			ParkingLot lot = new ParkingLot();
			bool formatFlag = false;
			int selection = 0;
			PrintState(lot);
			do
			{
				try
				{
					Console.Write("Enter a car number: ");
					selection = Int32.Parse(Console.ReadLine());
					Console.WriteLine();
					formatFlag = true;
					if(lot.Queue(selection) == false)
					{
						Console.WriteLine("Invalid Input - Car Already Pending or Parked. ");
						formatFlag = false;
					}
				}
				catch (FormatException)
				{
					Console.WriteLine("Invalid Input - Format Error. ");
					formatFlag = false;
				}
				catch (ArgumentException)
				{
					Console.WriteLine("Invalid Input - Car Not Found. ");
					formatFlag = false;
				}
			}
			while (formatFlag == false);
			for (int i = 0; i < 2; i++)
			{
				Console.Clear();
				PrintState(lot);
				lot.Queue();
				Console.WriteLine("Press any key to continue... ");
				Console.ReadKey();
			}
			Console.Clear();
			PrintState(lot);
		}

		static void PrintState(ParkingLot lot)
		{
			Console.WriteLine("Freed Cars: ");
			foreach (Car car in lot.GetFreeCars())
			{
				Console.Write($"{car} ");
			}
			Console.WriteLine();
			Console.WriteLine();
			Console.WriteLine("Pending Cars: ");
			foreach (Car car in lot.GetWaitlist())
			{
				Console.Write($"{car} ");
			}
			Console.WriteLine();
			Console.WriteLine();
			Console.WriteLine("Spaces: ");
			Car[] spaces = lot.GetParkingSpace();
			for (int i = 0; i < 7; i++)
			{
				Console.Write($"{lot.spaceMap[i]} \t");
			}
			Console.WriteLine();
			for (int i = 0; i < 7; i++)
			{
				Console.Write(spaces[i] == null ? "Empty \t" : spaces[i] + " \t");
			}
			Console.WriteLine();
			Console.WriteLine();
		}
	}

	public class ParkingLot
	{
		Random rand = new Random(DateTime.Now.Millisecond);
		Car[] spaces = new Car[7];
		public string[] spaceMap = new string[7] { "A", "B", "C", "D", "E", "F", "G" };
		List<Car> waitlist = new List<Car>(2);
		List<Car> cars = new List<Car>(20);

		bool Queue(Car car)
		{
			if(cars.Remove(car) == false)
			{
				return false;
			}
			Park(FindCandidate(car, waitlist));
			waitlist.Add(car);
#if debug
			Console.WriteLine($"> Queue {car}");
#endif
			return true;
		}
		public bool Queue(int selection)
		{
			return Queue(CarRemap(selection));
		}
		public bool Queue()
		{
			if (cars.Count == 0) { return false; }
			Queue(cars[rand.Next(0, cars.Count)]);
			return true;
		}
		void Park(Car car)
		{
			spaces[Unpark()] = car;
			waitlist.Remove(car);
#if debug
			Console.WriteLine($"> Park {car}");
#endif
		}

//		void Park(Car car, int index)
//		{
//			Unpark(index);
//			spaces[index] = car;
//			waitlist.Remove(car);
//#if debug
//			Console.WriteLine($"Park {car}");
//#endif
//		}

		int Unpark()
		{
			for (int i = 0; i < 7; i++)
			{
				if (spaces[i] == null) { return i; }
			}
			int index = rand.Next(0, 7);
			Unpark(index);
			return index;
		}
		void Unpark(int index)
		{
			if (spaces[index] == null) { }
			else
			{
#if debug
				Console.WriteLine($"> Remove {spaces[index]}");
#endif

				cars.Add(spaces[index]);
				spaces[index] = null;
			}
		}

		Car FindCandidate(Car target, List<Car> candidates)
		{
			int index = 0;
			int min = Int32.MaxValue;
			for (int i = 0; i < candidates.Count; i++)
			{
				if(Math.Abs(target - candidates[i]) < min)
				{
					index = i;
				}
			}
			return candidates[index];
		}
		Car CarRemap(int number)
		{
			foreach (Car car in cars)
			{
				if(car.Number == number) { return car; }
			}
			foreach (Car car in spaces)
			{
				if (car.Number == number) { return car; }
			}
			foreach (Car car in waitlist)
			{
				if (car.Number == number) { return car; }
			}
			throw new ArgumentException("Car not found. ");
		}
		public List<Car> GetFreeCars()
		{
			List<Car> res = new List<Car>(cars.Count);
			foreach (Car car in cars)
			{
				res.Add(car);
			}
			return res;
		}
		public Car[] GetParkingSpace()
		{
			Car[] res = new Car[7];
			for (int i = 0; i < 7; i++)
			{
				res[i] = spaces[i];
			}
			return res;
		}
		public List<Car> GetWaitlist()
		{
			List<Car> res = new List<Car>(cars.Count);
			foreach (Car car in waitlist)
			{
				res.Add(car);
			}
			return res;
		}

		public ParkingLot()
		{
			for(int i = 0; i < 20; i++)
			{
				cars.Add(new Car(i + 1));
			}
			for(int i = 0; i < 7; i++)
			{
				Car tempCar = cars[rand.Next(0, cars.Count)];
				spaces[i] = tempCar;
				cars.Remove(tempCar);
			}
			for(int i = 0; i < 2; i++)
			{
				Car tempCar = cars[rand.Next(0, cars.Count)];
				waitlist.Add(tempCar);
				cars.Remove(tempCar);
			}
		}
		
	}
	public class Car
	{
		public int Number { get; private set; }
		
		public static int operator -(Car lhs, Car rhs)
		{
			return lhs.Number - rhs.Number;
		}
		public override string ToString()
		{
			return Number.ToString();
		}

		public Car(int number) => Number = number;
	}
}
