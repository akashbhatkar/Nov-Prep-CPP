
// TOPIC: std::mutex::try_lock() On Mutex In C++11 Threading
// // 0. try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false. // 1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
// // 2. If try lock is called again by the same thread which owns the mutex, the behavior is undefined.
// //
// It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int Counter = 0;
mutex m;

void IncrementCounter(int d)
{
	if(m.try_lock())
	{
		for(int i = 0 ; i<d; i++)
		{
			//	if(m.try_lock())
			//	{
			++Counter;
			m.unlock();
			//	}
		}
	}
}

int main()
{
	thread t1(IncrementCounter , 10000000);
	thread t2(IncrementCounter, 10000000);
	cout<<"Counter = "<<Counter<<endl;

	t1.join();
	t2.join();
	return 0;
}
