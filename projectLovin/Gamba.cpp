#include "Gamba.h"
Gamba::Gamba()
{
	Skins newSkin;

	blueVec.resize(vecSize);
	pinkVec.resize(vecSize);
	purpleVec.resize(vecSize);
	redVec.resize(vecSize);
	yellowVec.resize(vecSize);

	//--------- CHROMA 2 ---------

	//BLUE

	newSkin.name = "MP7 | Armor Core";
	newSkin.pounds = 0;
	newSkin.pence = 18;
	newSkin.myCase = 0;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Sawed-Off | Origami";
	newSkin.pounds = 0;
	newSkin.pence = 20;
	newSkin.myCase = 0;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Negev | Man-o'-war";
	newSkin.pounds = 0;
	newSkin.pence = 14;
	newSkin.myCase = 0;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "P250 | Valence";
	newSkin.pounds = 0;
	newSkin.pence = 40;
	newSkin.myCase = 0;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Desert Eagle | Bronze Deco";
	newSkin.pounds = 1;
	newSkin.pence = 8;
	newSkin.myCase = 0;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "AK-47 | Elite Build";
	newSkin.pounds = 3;
	newSkin.pence = 45;
	newSkin.myCase = 0;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	//PURPLES

	newSkin.name = "UMP-45 | Grand Prix";
	newSkin.pounds = 0;
	newSkin.pence = 29;
	newSkin.myCase = 0;
	newSkin.rarity = PURPLE;
	purpleVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "CZ75-Auto | Pole Position";
	newSkin.pounds = 0;
	newSkin.pence = 97;
	newSkin.rarity = PURPLE;
	purpleVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "MAG-7 | Heat";
	newSkin.pounds = 1;
	newSkin.pence = 34;
	newSkin.myCase = 0;
	newSkin.rarity = PURPLE;
	purpleVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "AWP | Worm God";
	newSkin.pounds = 2;
	newSkin.pence = 05;
	newSkin.myCase = 0;
	newSkin.rarity = PURPLE;
	purpleVec[newSkin.myCase].push_back(newSkin);

	//PINKS

	newSkin.name = "Five-SeveN | Monkey Business";
	newSkin.pounds = 5;
	newSkin.pence = 74;
	newSkin.myCase = 0;
	newSkin.rarity = PINK;
	pinkVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "FAMAS | Djinn";
	newSkin.pounds = 5;
	newSkin.pence = 37;
	newSkin.myCase = 0;
	newSkin.rarity = PINK;
	pinkVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Galil AR | Eco";
	newSkin.pounds = 14;
	newSkin.pence = 34;
	newSkin.myCase = 0;
	newSkin.rarity = PINK;
	pinkVec[newSkin.myCase].push_back(newSkin);

	//REDS

	newSkin.name = "MAC-10 | Neon Rider";
	newSkin.pounds = 8;
	newSkin.pence = 80;
	newSkin.myCase = 0;
	newSkin.rarity = RED;
	redVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "M4A1-S | Hyper Beast";
	newSkin.pounds = 66;
	newSkin.pence = 1;
	newSkin.myCase = 0;
	newSkin.rarity = RED;
	redVec[newSkin.myCase].push_back(newSkin);

	//YELLOW

	newSkin.name = "Karambit | Doppler";
	newSkin.pounds = 1234;
	newSkin.pence = 82;
	newSkin.myCase = 0;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bayonet | Damascus Steel";
	newSkin.pounds = 390;
	newSkin.pence = 25;
	newSkin.myCase = 0;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Flip Knife | Tiger Tooth";
	newSkin.pounds = 553;
	newSkin.pence = 01;
	newSkin.myCase = 0;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Gut Knife | Rust Coat";
	newSkin.pounds = 113;
	newSkin.pence = 24;
	newSkin.myCase = 0;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "M9 Bayonet | Ultraviolet";
	newSkin.pounds = 654;
	newSkin.pence = 03;
	newSkin.myCase = 0;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	//--------- WILDFIRE ---------

	//BLUE

	newSkin.name = "Tec-9 | Jambiya";
	newSkin.pounds = 0;
	newSkin.pence = 18;
	newSkin.myCase = 1;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "MAC-10 | Lapis Gator";
	newSkin.pounds = 0;
	newSkin.pence = 27;
	newSkin.myCase = 1;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Dual Berettas | Cartel";
	newSkin.pounds = 0;
	newSkin.pence = 19;
	newSkin.myCase = 1;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "PP-Bizon | Photic Zone";
	newSkin.pounds = 0;
	newSkin.pence = 19;
	newSkin.myCase = 1;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "SSG 08 | Necropos";
	newSkin.pounds = 0;
	newSkin.pence = 19;
	newSkin.myCase = 1;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "USP-S | Lead Conduit";
	newSkin.pounds = 0;
	newSkin.pence = 41;
	newSkin.myCase = 1;
	newSkin.rarity = BLUE;
	blueVec[newSkin.myCase].push_back(newSkin);

	//PURPLE

	newSkin.name = "Five-SeveN | Triumvirate";
	newSkin.pounds = 1;
	newSkin.pence = 46;
	newSkin.myCase = 1;
	newSkin.rarity = PURPLE;
	purpleVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "MAG-7 | Praetorian";
	newSkin.pounds = 1;
	newSkin.pence = 66;
	newSkin.myCase = 1;
	newSkin.rarity = PURPLE;
	purpleVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "MP7 | Impire";
	newSkin.pounds = 1;
	newSkin.pence = 62;
	newSkin.myCase = 1;
	newSkin.rarity = PURPLE;
	purpleVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "FAMAS | Valence";
	newSkin.pounds = 1;
	newSkin.pence = 31;
	newSkin.myCase = 1;
	newSkin.rarity = PURPLE;
	purpleVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Glock-18 | Royal Legion";
	newSkin.pounds = 1;
	newSkin.pence = 27;
	newSkin.myCase = 1;
	newSkin.rarity = PURPLE;
	purpleVec[newSkin.myCase].push_back(newSkin);

	//PINK

	newSkin.name = "Nova | Hyper Beast";
	newSkin.pounds = 11;
	newSkin.pence = 35;
	newSkin.myCase = 1;
	newSkin.rarity = PINK;
	pinkVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "AWP | Elite Build";
	newSkin.pounds = 9;
	newSkin.pence = 90;
	newSkin.myCase = 1;
	newSkin.rarity = PINK;
	pinkVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Desert Eagle | Kumicho Dragon";
	newSkin.pounds = 12;
	newSkin.pence = 9;
	newSkin.myCase = 1;
	newSkin.rarity = PINK;
	pinkVec[newSkin.myCase].push_back(newSkin);

	//RED

	newSkin.name = "M4A4 | The Battlestar";
	newSkin.pounds = 4;
	newSkin.pence = 51;
	newSkin.myCase = 1;
	newSkin.rarity = RED;
	redVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "AK-47 | Fuel Injector";
	newSkin.pounds = 184;
	newSkin.pence = 6;
	newSkin.myCase = 1;
	newSkin.rarity = RED;
	redVec[newSkin.myCase].push_back(newSkin);

	//YELLOW

	newSkin.name = "Bowie Knife | Slaughter";
	newSkin.pounds = 353;
	newSkin.pence = 51;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Fade";
	newSkin.pounds = 1028;
	newSkin.pence = 93;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Scorched";
	newSkin.pounds = 833;
	newSkin.pence = 94;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Crimson Web";
	newSkin.pounds = 322;
	newSkin.pence = 53;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Blue Steel";
	newSkin.pounds = 237;
	newSkin.pence = 96;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Case Hardened";
	newSkin.pounds = 305;
	newSkin.pence = 55;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Vanilla";
	newSkin.pounds = 249;
	newSkin.pence = 81;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Night";
	newSkin.pounds = 393;
	newSkin.pence = 96;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Safari Mesh";
	newSkin.pounds = 367;
	newSkin.pence = 71;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Boreal Forest";
	newSkin.pounds = 255;
	newSkin.pence = 72;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Stained";
	newSkin.pounds = 204;
	newSkin.pence = 57;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Urban Masked";
	newSkin.pounds = 140;
	newSkin.pence = 34;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

	newSkin.name = "Bowie Knife | Forest DDPAT";
	newSkin.pounds = 131;
	newSkin.pence = 10;
	newSkin.myCase = 1;
	newSkin.rarity = YELLOW;
	yellowVec[newSkin.myCase].push_back(newSkin);

};

Gamba::~Gamba()
{

};

std::vector<std::vector<Skins>> Gamba::getVec(int rare)
{
	switch (rare)
	{
		case BLUE:
			return blueVec;
			break;
		case PURPLE:
			return purpleVec;
			break;
		case PINK:
			return pinkVec;
			break;
		case RED:
			return redVec;
			break;
		case YELLOW:
			return yellowVec;
			break;
		default:
			return blueVec;//just in case :)
			break;
	}
	
}