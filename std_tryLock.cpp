/*std::try_lock (note: not mutex.try_lock()) is a helper function in C++ used when you want to lock multiple mutexes at once without deadlocks.

This is different from mutex.try_lock(), so let’s understand clearly.

✅ What is std::try_lock?

std::try_lock tries to lock multiple mutexes one by one using try_lock() on each, but:

If it succeeds in locking all → returns -1

If it fails at some mutex:

Unlocks all previously locked mutexes

Returns the index of the mutex where it failed

It never blocks waiting for a mutex → it only tries.*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m1,m2,m3;

void CheckMutex(int a)
{
    int isLocked = std::try_lock(m1,m2,m3);
	if(isLocked == -1)
	{
		cout<<"Mutex lock successfull for the thread "<<a<<endl;
		m1.unlock();
		m2.unlock();
		m3.unlock();
	}
	else
	{
		cout<<"thread "<<a<<" Does not lock"<<endl;

	}
}

int main()
{
	thread t1(CheckMutex, 1);
	thread t2(CheckMutex, 2);
    t1.join();
    t2.join();
}
	
