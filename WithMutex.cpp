// TOPIC: Mutex In C++ Threading | Why Use Mutex What Is Race Condition And How To Solve It? What Is Critical Section // Mutex: Mutual Exclusion
// // RACE CONDITION:
// // 0. Race condition is a situation where two or more threads/process happend to change a common data at the same time. // 1. If there is a race condition then we have to protect it and the protected setion is
// // MUTEX:
// //0. Mutex is used to avoid race condition.
// // 1. We use lock(), unlock() on mutex to avoid race condition.
// called critical section/region.
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
using namespace std::chrono;
mutex m;
int MyBalance = 0;

void IncrementBalance()
{
	m.lock();
	++MyBalance;
	m.unlock();
}
int main()
{
	std::thread t1(IncrementBalance);
	std::thread t2(IncrementBalance);
	t1.join();
	t2.join();
	cout<<"MyBalance = "<<MyBalance<<endl;
}
