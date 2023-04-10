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
	std::vector<Skins> getVec(int rare);

private:
	std::vector<Skins> blueVec;
	std::vector<Skins> purpleVec;
	std::vector<Skins> pinkVec;
	std::vector<Skins> redVec;
	std::vector<Skins> yellowVec;
};

#endif
