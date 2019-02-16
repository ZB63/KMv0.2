#ifndef MEDIUM_MODE_H
#define MEDIUM_MODE_H
#include "stdafx.h"
using namespace std;

void delayy()
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
	Box sound;
	sound.fill_box("words");
	sf::Font arial;
	int random;
	char key;
	string key1;
	if (!arial.loadFromFile("arial.ttf"))
	{
		std::cout << "Nie udalo sie zaladowac czcionki!\n";
	};

	random = rand() % 4;
	//printf("%s DLaCZEGO drukuje chinskie znaczki???????????????????????? box.h", (sound.vector_string.begin() + random));


	/*
	while (okno.isOpen())
	{
	delayy();
	random = rand() % 25 ;
	printf("%c", random);
	key = random;
	key1 = string(1, key);
	sound.play(key1);
	random = random - 65;  //oznacznia event.key.code  A=0,B=1...Z=24


	okno.clear();					//wyswietalnie tekstu
	sf::Text tekst1(key1, arial);
	tekst1.setCharacterSize(300);
	tekst1.setColor(sf::Color::Yellow);
	tekst1.setStyle(sf::Text::Bold);
	tekst1.setPosition(x / 3 + 50, y / 20 * 3 + 20);
	okno.draw(tekst1);

	okno.display();
	while (1)
	{
	if (okno.pollEvent(zdarzenie))
	{
	if (zdarzenie.type == sf::Event::KeyPressed)
	{

	if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == random)
	{
	sound.play("true");
	break;
	}
	else if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
	{
	return;
	}
	else if (zdarzenie.type == sf::Event::KeyPressed)
	{
	sound.play("false");
	while (1)
	{
	okno.pollEvent(zdarzenie);
	if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == random)
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



	}


	*/




	return;
}

#endif /*EASY_MODE_H*/

