#ifndef MEDIUM_MODE_H
#define MEDIUM_MODE_H
#include "stdafx.h"
using namespace std;

void delayy()//nie korzystam z tego
{

	for (int i = 0; i < 5000000; i++)
	{
		for (int i = 0; i < 80; i++)
		{

		}
	}
}


void medium_mode(sf::RenderWindow& okno, int x, int y)
{

	sf::Event zdarzenie;
	srand(time(NULL));

	Box words;
	words.fill_box("words");
	Box letters;
	letters.fill_box("letters");

	sf::Font arial;
	if (!arial.loadFromFile("arial.ttf"))
	{
		std::cout << "Nie udalo sie zaladowac czcionki!\n";
	};

	string random = "";
	string typed = "";
	char key = 0;

	sf::Text tekst_random(random, arial);
	tekst_random.setCharacterSize(50);
	tekst_random.setColor(sf::Color::Yellow);
	tekst_random.setStyle(sf::Text::Bold);
	tekst_random.setPosition(x / 3, y / 20 * 3);

	sf::Text tekst_typed(typed, arial);
	tekst_typed.setCharacterSize(50);
	tekst_typed.setColor(sf::Color::Yellow);
	tekst_typed.setStyle(sf::Text::Bold);
	tekst_typed.setPosition(x / 3, y / 20 * 5);

	while (okno.isOpen())//petla glowna
	{
		random = words.random();
		words.play(random);
		tekst_random.setString(random);
		typed = "";
		tekst_typed.setString(typed);

		for (int i = 0; i < random.length(); i++)//iteracja na kazda litere
		{
			while (okno.isOpen())//czeka na wpisanie pojedynczej litery
			{
				if (okno.pollEvent(zdarzenie))
				{
					if (zdarzenie.type == sf::Event::Closed)
						okno.close();

					if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
						okno.close(); //wyjscie z programu

					if (zdarzenie.type == sf::Event::KeyPressed)
					{
						key = zdarzenie.key.code;
						key = key + 97;//konwersja do kodu ascii

						if (key == random[i])
						{
							letters.play("true");
							typed += key;
							break;
						}
						else {
							letters.play("false");
						}
					}

				}

				tekst_typed.setString(typed);

				okno.clear();
				okno.draw(tekst_random);
				okno.draw(tekst_typed);
				okno.display();//wyswietalnie tekstu
			}
		}
	}

	return;
}

#endif /*EASY_MODE_H*/

