#include "Pions.h"



Pions::Pions()
{

}
int midhypothenuse()
{
	float hypo = 64 * 64;
	hypo = hypo * 2;
	hypo = sqrtf(hypo);
	hypo = hypo / 2;
	return hypo;
}
Pions::Pions(int y, int x, int val, bool camp)
{

	posxdepart = posx = 64 * x;
	posydepart = posy = 64*y;
	valeur = val;
	equipe = camp;
	switch (equipe)
	{
	//Noir
	case 0:
		if (valeur == 1)
			TPions.loadFromFile("n1.png");
		else if (valeur == 2)
			TPions.loadFromFile("n2.png");
		else if (valeur == 3)
			TPions.loadFromFile("n3.png");
		else if (valeur == 4)
			TPions.loadFromFile("n4.png");
		else if (valeur == 5)
			TPions.loadFromFile("n5.png");
		break;
	//Blanc
	case 1:
		if (valeur == 1)
			TPions.loadFromFile("b1.png");
		else if (valeur == 2)
			TPions.loadFromFile("b2.png");
		else if (valeur == 3)
			TPions.loadFromFile("b3.png");
		else if (valeur == 4)
			TPions.loadFromFile("b4.png");
		else if (valeur == 5)
			TPions.loadFromFile("b5.png");
		break;
	}
	SPions.setTexture(TPions);
	SPions.setPosition(Vector2f(posx, posy));
}
Sprite Pions::getSPions()
{
	return SPions;
}
Pions::~Pions()
{
}
