#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
class Pions
{
private:
	Texture TPions;
	int posxdepart;
	int posydepart;
public:
	bool equipe;
	int posx;
	int posy;
	int valeur;
	Sprite SPions;
	Sprite getSPions();
	Pions();
	Pions(int x, int y, int val, bool camp);
	~Pions();
};

