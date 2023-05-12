#include "Farm.h"

void Farm::addTask(Task *task)
{
	q.push(task);
}

void Farm::run()
{
	auto threadFunc = [&]()
	{
		while (q.size() > 0)
		{
			mutex.lock();

			if (q.empty() == false)
			{
				q.front()->run();
				q.pop();
			}

			mutex.unlock();
		}
	};

	static int cpus = std::thread::hardware_concurrency();
	for (int i=0;i<cpus;i++)
	{
		if (q.empty())
		{
			return;
		}
		threads.push_back(std::thread(threadFunc));

		for (auto & th : threads)
		{
			th.join();
		}
	}
}