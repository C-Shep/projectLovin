#ifndef GAMBA_H
#define GAMBA_H

#include <string>
#include <vector>

enum skinRarity {BLUE, PURPLE, PINK, RED, YELLOW};

struct Skins
{
	std::string name;
	int pounds;
	int pence;
	int rarity;
};

class Gamba
{
public:
	Gamba();
	~Gamba();
	std::vector<Skins> getVec();

private:


	Skins skinArray[3];
	std::vector<Skins> sVec;
};

#endif
