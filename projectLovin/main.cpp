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
#include <Windows.h>

#include "Wallet.h"
#include "Gamba.h"

using std::cout;
using std::string;
using std::endl;
using std::thread;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

typedef std::chrono::steady_clock the_clock;

float standardKeyPrice;
int standardKeyPounds;
int standardKeyPence;

int chosenCase = 0;

float blueChance = 79.92;
float purpleChance = 95.90;
float pinkChance = 99.10;
float redChance = 99.74;

std::condition_variable myCV;

bool shouldShowTotal = true;
int showNum = 2;

std::mutex mutex;
std::mutex displayMutex;

Wallet wallet;

Gamba gamba;//CHANGE NAME

//all skins collected
std::vector<Skins> myInv;
std::vector<Skins> myGoods;

//Fuction for the skin roller
int threadFunc(float randRarityNum, int randSkinNum)
{
	//Unique Mutex
	std::unique_lock<std::mutex>lock(mutex);

	//rarity - a random int between 1 and 100 (0 and 99)
	float randomRarity = randRarityNum;

	//skinList is list of the skins that will be filled in a bit
	std::vector<std::vector<Skins>> skinList;

	//random rarities
	if (randomRarity < blueChance)
	{
		skinList = gamba.getVec(BLUE);
	}
	else if (randomRarity < purpleChance)
	{
		skinList = gamba.getVec(PURPLE);
	}
	else if (randomRarity < pinkChance)
	{
		skinList = gamba.getVec(PINK);
	}
	else if (randomRarity < redChance)
	{
		skinList = gamba.getVec(RED);
	}
	else
	{
		skinList = gamba.getVec(YELLOW);
	}

	//randomSkin is a random number
	int randomSkin = randSkinNum % skinList[chosenCase].size();

	//currentSkin is the selected Skin in the whole list from randomSkin
	Skins currentSkin = skinList[chosenCase][randomSkin];

	//Remove standard key price TODO: MAKE NOT MAGIC NUMBER
	wallet.subtract(standardKeyPounds, standardKeyPence);

	//Gain money equal to the skins price and display
	wallet.add(currentSkin.pounds, currentSkin.pence);
	cout << "\n" << currentSkin.name << " - " << currentSkin.pounds << "." << currentSkin.pence;

	if ((currentSkin.pounds >= standardKeyPounds+1) || (currentSkin.pounds >= standardKeyPounds && currentSkin.pence >= standardKeyPence))
	{
		myGoods.push_back(currentSkin);
	}

	return 0;
}

void showTotal()
{
	cout << "\n\nTotal Profit/Loss = " << wallet.getPounds() << "." << wallet.getPence() << "\n\n";
}

//Display every skin collected
int display()
{
	//mutex
	std::unique_lock<std::mutex> displayLock(displayMutex);

	//while there is still profit skins in the vector
	while (myGoods.empty() != true)
	{
		//temporary skin struct for displaying
		Skins displaySkin;

		//set to the back of the vector
		displaySkin = myGoods.back();
		cout << "\n" << displaySkin.name;	//display the temp skin

		//remove the back of the vector which is what displaySkin is
		myGoods.pop_back();
	}

	//if the profit vector is empty
	if (myGoods.empty() == true)
	{
		//set the showTotal bool to true
		shouldShowTotal = true;

		//notify one of the threads
		myCV.notify_one();
	}

	//wait until the 
	myCV.wait(displayLock, [&] {return shouldShowTotal; });

	//knock down the showNum
	showNum -= 1;

	//if the showNum is more than 0 (e.g should only happen once, show the total profit)
	if (showNum > 0)
	{
		showTotal();
	}

	return 0;
}

//openCases gets the random rarity and random skins randomised
void openCases(int caseAmount)
{
	int threadNum = std::thread::hardware_concurrency();
	std::vector<thread> threads;	//a vector of empty threads

	//for every case that the user wants to open...
	for (int i = 0; i < caseAmount; ++i)
	{
		float randRarity = 1 + rand() % 100;	//random number from 1 to 100
		float r = static_cast <float> (rand() / static_cast <float> (RAND_MAX));	//random float for the rarity
		int randSkin = rand();	//complete random number
		threads.push_back(thread(threadFunc, r*100, randSkin));	//pass in the random rarity and random skin to the unbox fucion

		//Clean up after yourself
		threads.back().join();
	}
}

int main()
{
	//----- Gamble -----
	#pragma region ///Gamble
	//get ready to gamble
	//prompt user to input price of a key - this is how much obtaining one skin
	std::cout << "\nPlease enter the price of a key - ";
	std::cin >> standardKeyPrice;
	std::cout << "\n";

	//convert float to 2 ints
	standardKeyPounds = standardKeyPrice;
	standardKeyPence = (standardKeyPrice - standardKeyPounds) * 100;

	//randomize seed
	srand((unsigned)time(NULL));

	//addict is the bool variable which dictates if you want to keep openign cases or not
	bool addict = true;

	//amount of cases to open in one batch
	int caseAmount;

	//while you still want to be opening cases
	while (addict)
	{
		//ask user how many casses to open
		std::cout << "\nOpen some cases? Input number of cases desired or 0 to end - ";
		std::cin >> caseAmount;
		std::cout << "\n";

		//if the user want to open cases
		if (caseAmount > 0)
		{
			//ask player waht case they want to open
			std::cout << "\nWhat type of case would you like to open? 0 = Chroma 2, 1 = Wildfire : ";
			std::cin >> chosenCase;
			std::cout << "\n";

			openCases(caseAmount);
		}
		else {
			//if the user decides to not open any more cases, stop asking them to
			addict = false;
		}
	}
	#pragma endregion ///Gamble

	//----- Display-----
	#pragma region ///Display
	thread knifeThread1(display);
	thread knifeThread2(display);

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	knifeThread1.join();
	knifeThread2.join();
	#pragma endregion ///Display
	return 0;
}