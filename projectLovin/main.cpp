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

std::condition_variable myCV;

std::mutex mutex;
std::mutex displayMutex;

Wallet wallet;

Gamba gamba;//CHANGE NAME

//all skins collected
std::vector<Skins> myInv;
std::vector<Skins> myGoods;

//Fuction for the skin roller
int threadFunc()
{

	//100 times: MAKE NOT MAGIC NUMBER

		//Unique Mutex
		std::unique_lock<std::mutex>lock(mutex);

		//Time Seed Randomization
		srand((unsigned)time(NULL));
		std::this_thread::sleep_for(std::chrono::seconds(1));

		//Open 10 skins at a time
		for (int j = 0; j < 10; ++j)
		{
			//rarity - a random int between 1 and 100 (0 and 99)
			int randomRarity = (rand() % 100);

			//skinList is list of the skins that will be filled in a bit
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

			if (currentSkin.pounds >= 2)
			{
				myGoods.push_back(currentSkin);
			}
		}
	return 0;
}

//Display every skin collected
void display()
{
	std::unique_lock<std::mutex> displayLock(displayMutex);
	//myCV.wait(displayLock);
	//for (auto& sk : myGoods)
	//{
	//	cout << "\n" << sk.name;
	//	myGoods
	//}
	while (myGoods.empty() != true)
	{
		Skins displaySkin;
		displaySkin = myGoods.back();
		cout << "\n" << displaySkin.name;
		myGoods.pop_back();
	}
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

	thread knifeThread1(display);
	thread knifeThread2(display);
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	myCV.notify_all();
	knifeThread1.join();
	knifeThread2.join();

	//End the clock
	the_clock::time_point end1 = the_clock::now();
	//Calculate the time taken 
	auto time_taken1 = duration_cast<milliseconds>(end1 - start1).count();
	//Display the overall time taken
	cout << "\nit took " << time_taken1 << " ms." << endl;	

	return 0;
}