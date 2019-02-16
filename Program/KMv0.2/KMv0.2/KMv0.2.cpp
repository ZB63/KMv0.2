// KMv0.2.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "start.h"
#include "easy_mode.h"
#include "training_mode.h"
#include "medium_mode.h"

using namespace std;

const int winWidth = 800;
const int winHeight = 600;
int choose_function;
int main()
{

	sf::RenderWindow oknoAplikacji(sf::VideoMode(winWidth, winHeight, 32), "KMv0.2");

	sf::Texture obraz1;
	obraz1.loadFromFile("images\\brukiew.png");

	sf::Sprite sprite1;
	sprite1.setTexture(obraz1);

	while (1)
	{
		choose_function = menu_start(oknoAplikacji, winWidth, winHeight); // odpalamy menu
		if (choose_function == 1)
		{
			training_mode(oknoAplikacji, winWidth, winHeight);
		}
		else if (choose_function == 2)
		{
			easy_mode(oknoAplikacji, winWidth, winHeight);
		}
		else if (choose_function == 3)
		{
			medium_mode(oknoAplikacji, winWidth, winHeight);
		}
		else if (choose_function == 0)
		{
			oknoAplikacji.close();
		}
	}

	return 0;
}