#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System\String.hpp"
#include "Pions.h"
#include "map.h"
using namespace sf;
using namespace std;
#include <string>
int TabPlateau[8][8];
Pions** lespions = new Pions*[32];
void initpion(Pions** lespions)
{
	//Noir
	//1pt
	lespions[0] = new Pions(0, 0, 1, false);
	lespions[7] = new Pions(0, 7, 1, false);
	lespions[8] = new Pions(1,0, 1, false);
	lespions[15] = new Pions(1, 7, 1, false);
	//2pt
	lespions[1] = new Pions(0, 1, 2, false);
	lespions[6] = new Pions(0, 6, 2, false);
	lespions[9] = new Pions(1, 1, 2, false);
	lespions[14] = new Pions(1, 6, 2, false);
	//3pt
	lespions[2] = new Pions(0, 2, 3, false);
	lespions[5] = new Pions(0, 5, 3, false);
	lespions[10] = new Pions(1, 2, 3, false);
	lespions[13] = new Pions(1, 5, 3, false);
	//4pt
	lespions[11] = new Pions(1, 3, 4, false);
	lespions[12] = new Pions(1, 4, 4, false);
	//5pt
	lespions[3] = new Pions(0, 3, 5, false);
	lespions[4] = new Pions(0, 4, 5, false);


	//Blanc
	//1pt
	lespions[16] = new Pions(6, 0, 1, true);
	lespions[23] = new Pions(6, 7, 1, true);
	lespions[24] = new Pions(7, 0, 1, true);
	lespions[31] = new Pions(7, 7, 1, true);
	//2pt
	lespions[17] = new Pions(6, 1, 2, true);
	lespions[22] = new Pions(6, 6, 2, true);
	lespions[25] = new Pions(7, 1, 2, true);
	lespions[30] = new Pions(7, 6, 2, true);
	//3pt
	lespions[18] = new Pions(6, 2, 3, true);
	lespions[21] = new Pions(6, 5, 3, true);
	lespions[26] = new Pions(7, 2, 3, true);
	lespions[29] = new Pions(7, 5, 3, true);
	//4pt
	lespions[19] = new Pions(6, 3, 4, true);
	lespions[20] = new Pions(6, 4, 4, true);
	//5pt
	lespions[27] = new Pions(7, 3, 5, true);
	lespions[28] = new Pions(7, 4, 5, true);
	
}
bool checkposition (int x, int y,int selected)
{
	bool continu = true;
	int i = 1;
	int px = lespions[selected]->posx;
	px = px / 64;
	int py = lespions[selected]->posy;
	py = py / 64;

	//Noir
	//Diago bas droite
	if (lespions[selected]->equipe == false)
	{
		while (continu)
		{
			if (px + i < 8 && py + i > -1)
			{
				if (TabPlateau[py + i][px + i] == 0)
				{
					i++;
				}
				else if (px + i - 1 == x && py + i - 1 == y)
					return true;
				else
				{
					continu = false;
				}
			}
			else
				continu = false;
		}
		//Bas 
		continu = true; i = 1;
		while (continu)
		{
			if (px < 8 && py + i > -1)
			{
				if (TabPlateau[py + i][px] == 0)
				{
					i++;
				}
				else if (px == x && py + i - 1 == y)
					return true;
				else
				{
					continu = false;
				}
			}
			else
				continu = false;
		}
		//Diago haut gauche
		continu = true; i = 1;
		while (continu)
		{
			if (px - i > -1 && py + i > -1)
			{
				if (TabPlateau[py + i][px - i] == 0)
				{
					i++;
				}
				else if (px == x + i - 1 && py + i - 1 == y)
				{
					return true;
				}
				else
				{
					continu = false;
				}
			}
			else
				continu = false;
		}
	}


	if (lespions[selected]->equipe == true)
	{
		while (continu)
		{
			if (px + i < 8 && py - i < 8)
			{
				if (TabPlateau[py - i][px + i] == 0)
				{
					i++;
				}
				else if (px + i - 1 == x && py - i + 1 == y)
					return true;
				else
				{
					continu = false;
				}
			}
			else
				continu = false;
		}
		//Haut 
		continu = true; i = 1;
		while (continu)
		{
			if (px < 8 && py - i < 8)
			{
				if (TabPlateau[py - i][px] == 0)
				{
					i++;
				}
				else if (px == x && py - i + 1 == y)
					return true;
				else
				{
					continu = false;
				}
			}
			else
				continu = false;
		}
		//Diago haut gauche
		continu = true; i = 1;
		while (continu)
		{
			if (px - i > -1 && py - i < 8)
			{
				if (TabPlateau[py - i][px - i] == 0)
				{
					i++;
				}
				else if (px == x + i - 1 && py - i + 1 == y)
					return true;
				else
				{
					continu = false;
				}
			}
			else
				continu = false;
		}
	}
	return false;
}
void main()
{

	initpion(lespions);

	int numpion = 0;

	//Creation de la map
	Map map;
	int tabmap[64]
	{
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0,
		0,1,0,1,0,1,0,1,
		1,0,1,0,1,0,1,0
	};
	map.load("tileset.png", sf::Vector2u(64, 64), tabmap, 8, 8);
	//Tableau des cases
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i < 2 || i>5)
			{
				TabPlateau[i][j] = numpion;
				numpion++;
			}
			else
				TabPlateau[i][j] = 0;
		}
		

	}
	string nom = "Souitch";
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "My window");

	
	Sprite SPlateau;
	Texture TPlateau;
	Image image;
	TPlateau.loadFromFile("plateau.jpg");



	SPlateau.setTexture(TPlateau);
	Mouse souris;
	int selectedpion;
	bool selected = false;
//Boucle d'event
	while (window.isOpen())
	{

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					
				
					int select;
					int x = event.mouseButton.x / 64;
					int y = event.mouseButton.y / 64;
					select = TabPlateau[y][x];
					if (select != 0 || selected )
					{
						
						if (!selected || select != 0)
						{
							selectedpion = select;
							selected = true;
						}
						else
						{
							if (checkposition(x, y, selectedpion))
							{
								lespions[selectedpion]->SPions.setPosition(Vector2f(x * 64, y * 64));
								TabPlateau[y][x] = selectedpion;
								TabPlateau[lespions[selectedpion]->posy / 64][lespions[selectedpion]->posx / 64] = 0;
								lespions[selectedpion]->posx = x * 64;
								lespions[selectedpion]->posy = y * 64;
								lespions[selectedpion]->SPions.setPosition(Vector2f(lespions[selectedpion]->posx, lespions[selectedpion]->posy));
								selected = false;
							}
						}
					}


				}
			}
			window.clear();
			window.draw(map);
			for (int i = 0; i < 32; i++)
			{
				window.draw(lespions[i]->getSPions());
			}
			window.display();
			
		}
	}
}