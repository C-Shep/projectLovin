#ifndef WALLET_H
#define WALLET_H
class Wallet
{
public:
	Wallet();
	~Wallet();
	void add(int pounds, int pence);
	void subtract(int pounds, int pence);
	int getPounds();
	int getPence();

private:
	int pounds_ = 0;
	int pence_ = 0;
};

#endif