#include<iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;
typedef unsigned long long int u;
u EvenSum = 0;
u OddSum = 0;
void findOdd()
{
	for(int i = 0; i<1900000000; i++)
	{
		if(i%2 == 1)
		{
			OddSum = OddSum + i;
		}
	}
}


void findEven()
{
	for(int i = 0 ; i<1900000000 ; i++)
	{
		if(i%2 == 0)
		{
			EvenSum = EvenSum + i;
		}
	}
}

int main()
{
	int oddsum = 0, evensum = 0;
	auto start = high_resolution_clock::now();

	findOdd();
	findEven();
	cout<<"Sum of odd number "<<OddSum<<endl;;
	cout<<"Sum of even numbers "<<EvenSum<<endl;
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout<<"Sec = "<<duration.count()/1000000<<endl;
}

