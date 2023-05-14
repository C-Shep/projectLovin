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
#include <queue>

#include "Wallet.h"
#include "Gamba.h"

using std::cout;
using std::string;
using std::endl;
using std::thread;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

typedef std::chrono::steady_clock the_clock;

float standardKeyPrice = -1;
int standardKeyPounds;
int standardKeyPence;

float totalMoney;

int wantedThreadAmount = 0;

int chosenCase = -1;

float blueChance = 79.92;
float purpleChance = 95.90;
float pinkChance = 99.10;
float redChance = 99.74;

std::condition_variable myCV;

bool shouldShowTotal = true;
int showNum = 2;

//std::queue 

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
	//Unique Mutex
	//std::unique_lock<std::mutex>lock(mutex);


	int randSkin = rand();	//complete random number

	//rarity - a random int between 1 and 100 (0 and 99)
	float randomRarity = (static_cast <float> (rand() / static_cast <float> (RAND_MAX))*100.0f);	//random float for the rarity

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
	int randomSkin = randSkin % skinList[chosenCase].size();

	//currentSkin is the selected Skin in the whole list from randomSkin
	Skins currentSkin = skinList[chosenCase][randomSkin];

	//Remove standard key price
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
	//Get final money amount from 
	float pound = wallet.getPounds();
	float pence = wallet.getPence();
	pence = pence / 100;

	totalMoney = pound + pence;

	cout << "\n\nTotal Profit/Loss = " << totalMoney << "\n\n";
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
	myCV.wait(displayLock, [&] {return shouldShowTotal;});

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
	static int threadNum = std::thread::hardware_concurrency();
	std::vector<thread> threads;	//a vector of empty threads
	int caseCounter = caseAmount;

	for (int i = 0; i < threadNum; i++)
	{
		threads.push_back(std::thread([&](){
			srand(time(NULL)+i);
			while (true)
			{
				std::unique_lock<std::mutex>lock(mutex);
				if (caseCounter <= 0)
				{
					return;
				}
				threadFunc();
				caseCounter--;
			}
		}));
	}

	for (auto&th:threads)
	{
		th.join();
	}

	return;

}

int main()
{
	//----- Gamble -----
	#pragma region ///Gamble

	//Ask how many threads you want to use
	while (wantedThreadAmount <= 0 || wantedThreadAmount > std::thread::hardware_concurrency())
	{
		std::cout << "\nHow many threads would you like to use? : ";
		std::cin >> wantedThreadAmount;
		std::cout << "\n";
		if (wantedThreadAmount <= 0 || wantedThreadAmount > std::thread::hardware_concurrency())
		{
			std::cout << "ERROR! Please enter a valid number!";
		}
	}


	//get ready to gamble
	//prompt user to input price of a key - this is how much obtaining one skin

	while (standardKeyPrice < 0)
	{
		std::cout << "\nPlease enter the price of a key - ";
		std::cin >> standardKeyPrice;
		std::cout << "\n";

	}

	//convert float to 2 ints
	standardKeyPounds = standardKeyPrice;
	standardKeyPence = (standardKeyPrice - standardKeyPounds) * 100;

	//randomize seed
	srand((unsigned)time(NULL));

	//addict is the bool variable which dictates if you want to keep openign cases or not
	bool addict = true;

	//while you still want to be opening cases
	while (addict)
	{
		//Reset case type
		chosenCase = -1;

		//amount of cases to open in one batch
		int caseAmount = -1;

		//ask user how many casses to open
		while (caseAmount < 0)
		{
			std::cout << "\nOpen some cases? Input number of cases desired or 0 to end - ";
			std::cin >> caseAmount;
			std::cout << "\n";
		}

		//if the user want to open cases
		if (caseAmount > 0)
		{
			//ask player waht case they want to open
			while (chosenCase < 0 || chosenCase > 1)
			{
				std::cout << "\nWhat type of case would you like to open? 0 = Chroma 2, 1 = Wildfire : ";
				std::cin >> chosenCase;
				std::cout << "\n";
			}

			//Begin Timer
			the_clock::time_point start = the_clock::now();

			//Open Case Function
			openCases(caseAmount);

			//End the clock
			the_clock::time_point end = the_clock::now();
			//Calculate the time taken 
			auto time_taken = duration_cast<milliseconds>(end - start).count();
			//Display the overall time taken
			cout << "\nit took " << time_taken << " ms." << "\n\n";
		}
		else {
			//if the user decides to not open any more cases, stop asking them to
			addict = false;
		}
	}
	#pragma endregion ///Gamble

	//----- Display-----
	#pragma region ///Display

	//Choose amount of threads
	the_clock::time_point displayStart = the_clock::now();

	thread goodThread1(display);
	thread goodThread2(display);

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	goodThread1.join();
	goodThread2.join();

	//End the clock
	the_clock::time_point displayEnd = the_clock::now();
	//Calculate the time taken 
	auto displayTimeTaken = duration_cast<milliseconds>(displayEnd - displayStart).count();
	//Display the overall time taken
	cout << "\nit took " << displayTimeTaken << " ms." << "\n\n";
	#pragma endregion ///Display

	return 0;
}