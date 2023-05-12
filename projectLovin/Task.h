#pragma once
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

class Task
{
public:

	float randRarityNum_;
	int randSkinNum_;

	Task(float randRarityNum, int randSkinNum)
	{
		randRarityNum_ = randRarityNum;
		randSkinNum_ = randSkinNum;
	}

	~Task()
	{

	}

	void run()
	{

	}
};

