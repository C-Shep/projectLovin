#pragma once
#include <queue>
#include "task.h"
#include <mutex>
#include<iostream>
#include<thread>
#include<vector>

class Farm
{
	public:
		void addTask(Task *task);
		void run();
	private:
		std::queue<Task*> q;
		std::vector<std::thread> threads;
		std::mutex mutex;
};

