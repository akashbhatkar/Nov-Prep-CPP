#include<iostream>
#include <thread>
#include<chrono>

using namespace std::chrono;
using namespace std;

void PrintName(int times)
{
	while(times)
	{
		cout<<"Akash"<<endl;
		times--;
	}
	this_thread::sleep_for(seconds(5));
}

int main()
{
	thread t1(PrintName, 10);
	cout<<"Before Join"<<endl;
	(t1.joinable()) ? cout<<"Joinable"<<endl : cout<<"Not joinable"<<endl;

	t1.join();
	cout<<"After join"<<endl;
	(t1.joinable()) ? cout<<"Joinable"<<endl : cout<<"Not joinable"<<endl;
}
