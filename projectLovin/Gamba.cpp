#include "Gamba.h"
Gamba::Gamba()
{
	Skins newSkin;

	newSkin.name = "MP7 | Armor Core";
	newSkin.pounds = 0;
	newSkin.pence = 18;
	newSkin.rarity = BLUE;
	sVec.push_back(newSkin);

	newSkin.name = "Sawed-Off | Origami";
	newSkin.pounds = 0;
	newSkin.pence = 20;
	newSkin.rarity = BLUE;
	sVec.push_back(newSkin);

	newSkin.name = "Negev | Man-o'-war";
	newSkin.pounds = 0;
	newSkin.pence = 14;
	newSkin.rarity = BLUE;
	sVec.push_back(newSkin);

	newSkin.name = "P250 | Valence";
	newSkin.pounds = 0;
	newSkin.pence = 40;
	newSkin.rarity = BLUE;
	sVec.push_back(newSkin);

	newSkin.name = "Desert Eagle | Bronze Deco";
	newSkin.pounds = 1;
	newSkin.pence = 8;
	newSkin.rarity = BLUE;
	sVec.push_back(newSkin);

	newSkin.name = "AK-47 | Elite Build";
	newSkin.pounds = 3;
	newSkin.pence = 45;
	newSkin.rarity = BLUE;
	sVec.push_back(newSkin);

};

Gamba::~Gamba()
{

};

std::vector<Skins> Gamba::getVec()
{
	return sVec;
}