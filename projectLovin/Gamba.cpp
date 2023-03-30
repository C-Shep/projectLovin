#include "Gamba.h"
Gamba::Gamba()
{
	Skins newSkin;

	//--------- CHROMA 2 ---------

	//BLUES

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

	//PURPLES

	newSkin.name = "UMP-45 | Grand Prix";
	newSkin.pounds = 0;
	newSkin.pence = 29;
	newSkin.rarity = PURPLE;
	sVec.push_back(newSkin);

	newSkin.name = "CZ75-Auto | Pole Position";
	newSkin.pounds = 0;
	newSkin.pence = 97;
	newSkin.rarity = PURPLE;
	sVec.push_back(newSkin);

	newSkin.name = "MAG-7 | Heat";
	newSkin.pounds = 1;
	newSkin.pence = 34;
	newSkin.rarity = PURPLE;
	sVec.push_back(newSkin);

	newSkin.name = "AWP | Worm God";
	newSkin.pounds = 2;
	newSkin.pence = 05;
	newSkin.rarity = PURPLE;
	sVec.push_back(newSkin);

	//PINKS

	newSkin.name = "Five-SeveN | Monkey Business";
	newSkin.pounds = 5;
	newSkin.pence = 74;
	newSkin.rarity = PINK;
	sVec.push_back(newSkin);

	newSkin.name = "FAMAS | Djinn";
	newSkin.pounds = 5;
	newSkin.pence = 37;
	newSkin.rarity = PINK;
	sVec.push_back(newSkin);

	newSkin.name = "Galil AR | Eco";
	newSkin.pounds = 14;
	newSkin.pence = 34;
	newSkin.rarity = PINK;
	sVec.push_back(newSkin);

	//REDS

	newSkin.name = "MAC-10 | Neon Rider";
	newSkin.pounds = 8;
	newSkin.pence = 80;
	newSkin.rarity = RED;
	sVec.push_back(newSkin);

	newSkin.name = "M4A1-S | Hyper Beast";
	newSkin.pounds = 66;
	newSkin.pence = 1;
	newSkin.rarity = RED;
	sVec.push_back(newSkin);

	//YELLOW

	newSkin.name = "Karambit | Doppler";
	newSkin.pounds = 1234;
	newSkin.pence = 82;
	newSkin.rarity = YELLOW;
	sVec.push_back(newSkin);

	//--------- NEXT CASE ---------

};

Gamba::~Gamba()
{

};

std::vector<Skins> Gamba::getVec()
{
	return sVec;
}