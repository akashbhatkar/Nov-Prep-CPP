#include <iostream>
#include <thread>
using namespace std;
using namespace std::chrono;

int MyBalance = 0;

void IncrementBalance()
{
	++MyBalance;
}
int main()
{
	std::thread t1(IncrementBalance);
	std::thread t2(IncrementBalance);
	t1.join();
	t2.join();
	cout<<"MyBalance = "<<MyBalance<<endl;
}
