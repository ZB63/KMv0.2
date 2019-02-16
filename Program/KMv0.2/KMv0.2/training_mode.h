#pragma once
#ifndef TRAINING_MODE_H
#define TRAINING_MODE_H
/*
Funkcja easy_mode losuje pojedyncza litere i sprawdza czy zostal wcisniety poprawny klawisz
*/

#include "stdafx.h"

using namespace std;



void training_mode(sf::RenderWindow& okno, int x, int y)
{

	// play("wstep_tryb_nauki") Aby anulowac glos wprowadzajacy w tryb nauki nacisnij enter


	sf::Event zdarzenie;

	Box sound;
	sound.fill_box("letters");
	int random;
	char key = 0;
	string key1;
	sf::Font arial;
	if (!arial.loadFromFile("arial.ttf"))
	{
		std::cout << "Nie udalo sie zaladowac czcionki!\n";
	};



	while (okno.isOpen())
	{

		while (1)
		{
			if (okno.pollEvent(zdarzenie))
			{
				if (zdarzenie.type == sf::Event::KeyPressed)
				{
					key = zdarzenie.key.code;
					key = key + 65;//konwersja do kodu ascii przy warunkach poczatkowych A=0

					if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
					{
						return;
					}
					if (key < 96 && key>64)
					{
						sound.play(string(1, key)); //konwersja char do string string(1, key)

						okno.clear();//
						sf::Text tekst1(string(1, key), arial);
						tekst1.setCharacterSize(300);
						tekst1.setColor(sf::Color::Yellow);
						tekst1.setStyle(sf::Text::Bold);
						tekst1.setPosition(x / 3 + 50, y / 20 * 3 + 20);
						okno.draw(tekst1);
						okno.display();//wyswietalnie tekstu

					}


				}
				if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				{
					return;
				}


			}


		}
	}

	return;
}

#endif /*EASY_MODE_H*/
