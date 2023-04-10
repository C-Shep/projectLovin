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
std::mutex mutex1;

Wallet wallet;

Gamba gamba;//CHANGE NAME

//all skins collected
std::vector<Skins> myInv;

//Fuction for the skin roller
int threadFunc()
{
	srand(time(0));

	//100 times: MAKE NOT MAGIC NUMBER
	for (int i = 0; i < 100; ++i)
	{
		//Unique Mutex
		std::unique_lock<std::mutex>lock(mutex);

		//rarity - a random int between 1 and 100 (0 and 99)
		int randomRarity = (rand() % 100);

		//skinList is all of the skins
		std::vector<Skins> skinList;

		//TODO MAKE THESE NOT MAGIC NUMBERS
		if (randomRarity < 79)
		{
			skinList = gamba.getVec(BLUE);
		}
		else if (randomRarity < 90)
		{
			skinList = gamba.getVec(PURPLE);
		}
		else if (randomRarity < 97)
		{
			skinList = gamba.getVec(PINK);
		}
		else if (randomRarity < 99)
		{
			skinList = gamba.getVec(RED);
		}
		else
		{
		skinList = gamba.getVec(YELLOW);
		}
		
		//randomSkin is a random number
		int randomSkin = (rand() % skinList.size());


		//currentSkin is the selected Skin in the whole list from randomSkin
		Skins currentSkin = skinList[randomSkin];

		//Remove standard key price TODO: MAKE NOT MAGIC NUMBER
		wallet.subtract(2, 15);

		//Gain money equal to the skins price and display
		wallet.add(currentSkin.pounds, currentSkin.pence);
		cout << "\n" << currentSkin.name << " - " << currentSkin.pounds << "." << currentSkin.pence << "    " << randomRarity;

		myInv.push_back(currentSkin);
	}

	return 0;
}

//Display every skin collected
int display()
{
	std::unique_lock<std::mutex>lock(mutex1);
	for (auto& sk : myInv)
	{
		cout << "\n" << sk.name;
	}

	return 0;
}

int main()
{
	//GAMBLE CODE
	// 
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

	cout << "\nTotal Profit/Loss = " << wallet.getPounds() << "." << wallet.getPence();

	//End the clock
	the_clock::time_point end = the_clock::now();
	//Calculate the time taken 
	auto time_taken = duration_cast<milliseconds>(end - start).count();
	//Display the overall time taken
	cout << "\nit took " << time_taken << " ms." << endl;

	//DISPLAY CODE

	the_clock::time_point start1 = the_clock::now();

	std::vector<thread> threads1;
	display();
	for (int i = 0; i < 10; ++i)
	{
		threads1.push_back(thread(display));
	}

	for (auto& th1 : threads1)
	{
		th1.join();
	}

	//End the clock
	the_clock::time_point end1 = the_clock::now();
	//Calculate the time taken 
	auto time_taken1 = duration_cast<milliseconds>(end1 - start1).count();
	//Display the overall time taken
	cout << "\nit took " << time_taken1 << " ms." << endl;
	return 0;
}