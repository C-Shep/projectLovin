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
	int myCase;
	int rarity;
};

class Gamba
{
public:
	Gamba();
	~Gamba();
	std::vector<std::vector<Skins>> getVec(int rare);

private:
	int vecSize = 2;

	std::vector<std::vector<Skins>> blueVec;
	std::vector<std::vector<Skins>> purpleVec;
	std::vector<std::vector<Skins>> pinkVec;
	std::vector<std::vector<Skins>> redVec;
	std::vector<std::vector<Skins>> yellowVec;
};

#endif
