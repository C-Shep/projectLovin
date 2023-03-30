//Callum Shepherd 2101007
//CMP202 Project
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "Wallet.h"
#include "Gamba.h"

using std::cout;
using std::string;
using std::endl;
using std::thread;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

typedef std::chrono::steady_clock the_clock;

int thing = 0;

std::mutex mutex;

Wallet wallet;

Gamba skinList;

int threadFunc()
{
	srand(time(0));
	int randomSkin = (rand()%skinList.getVec().size());

	for (int i = 0; i < 100000; ++i)
	{
		std::unique_lock<std::mutex>lock(mutex);
		wallet.add(5, -2);
	}

	return 0;
}

int main()
{

	//Begin the clock
	the_clock::time_point start = the_clock::now();

	std::vector<thread> threads;

	for (int i = 0; i < 10; ++i)
	{
		threads.push_back(thread(threadFunc));
	}

	for (auto& th : threads)
	{
		th.join();
	}

	cout << wallet.getPounds() << "." << wallet.getPence();

	//End the clock
	the_clock::time_point end = the_clock::now();
	//Calculate the time taken 
	auto time_taken = duration_cast<milliseconds>(end - start).count();
	//Display the overall time taken
	cout << "\nit took " << time_taken << " ms." << endl;

	return 0;
}