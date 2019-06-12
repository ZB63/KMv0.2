#ifndef EASY_MODE_H
#define EASY_MODE_H

/*
Funkcja easy_mode losuje pojedyncza litere i sprawdza czy zostal wcisniety poprawny klawisz
*/

#include "stdafx.h"
using namespace std;

void delay(int i)
{
	std::clock_t start;
	start = std::clock();

	while ((std::clock() -  start) / (double)1000 < i)
	{ }
	return;
}


void easy_mode(sf::RenderWindow& okno, int x, int y)
{
	okno.clear();
	okno.display();
	Box sound;
	sound.fill_box("letters");
	sf::Event zdarzenie;
	srand(time(NULL));
	int active_key, random;
	char key;
	string key1;

	sf::Font arial;
	if (!arial.loadFromFile("arial.ttf"))
	{
		//std::cout << "Nie udalo sie zaladowac czcionki!\n";
	}; // wczytywanie czcionki

	sf::Text tekst1(key1, arial);
	tekst1.setCharacterSize(300);
	tekst1.setColor(sf::Color::Yellow);
	tekst1.setStyle(sf::Text::Bold);
	tekst1.setPosition(x / 3 + 50, y / 20 * 3 + 20);

	while (okno.isOpen())
	{
		delay(1);//opoznienie
		random = rand() % 25 + 65; // losuje litere :ascii code a=65...z=90
		key1 = string(1, (char)random);//konwersja int na string

		sound.play(key1);
		active_key = random - 65;  //oznacznia event.key.code  A=0,B=1...Z=24


		okno.clear();

		tekst1.setString(key1);

		okno.draw(tekst1);
		okno.display();//wyswietalnie tekstu


		while (1)
		{
			if (okno.pollEvent(zdarzenie))
			{

				if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				{
					return;
				}
				else if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == active_key)
				{
					sound.play("true");
					break;
				}
				else if (zdarzenie.type == sf::Event::KeyPressed)
				{
					sound.play("false");
					while (1)
					{
						okno.pollEvent(zdarzenie);
						if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
						{
							return;
						}
						else if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == active_key)
						{
							sound.play("true");
							break;
						}
						else if (zdarzenie.type == sf::Event::KeyPressed)
						{
							sound.play("false");
						}
					}
					break;
				}
			}
		}
	}

	return;
}

#endif /*EASY_MODE_H*/
