#include "Wallet.h"

Wallet::Wallet()
{

}

Wallet::~Wallet()
{

}

void Wallet::add(int pounds, int pence)
{
	pounds_ += pounds;
	pence_ += pence;

	if (pence_ >= 100) {
		pounds_++;
		pence_ -= 100;
	}

	if (pence_ < 0) {
		pounds_--;
		pence_ += 99;
	}
}

void Wallet::subtract(int pounds, int pence)
{
	pounds_ -= pounds;
	pence_ -= pence;

	//if (pence_ <0) {
	//	pounds_--;
	//	pence_ += 99;
	//}
}

int Wallet::getPounds()
{
	return pounds_;
}

int Wallet::getPence()
{
	return pence_;
}