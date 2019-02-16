#include "stdafx.h"

#ifndef START_H
#define START_H
/*
Funkcja menu_start zwraca liczbe odpowiadajaca trybowi jaki ma zostac
aktywowany w glownej petli.
Legenda:
0 - zamykamy program
1 - learning(), tryb uczenia
2 - easy_mode(), litery
3 - medium_mode(), slowa
4 - hard_mode(), zdania
*/

int menu_start(sf::RenderWindow& okno, int x, int y)
{
	sf::Event zdarzenie;
	sf::Font arial;
	const int font_size = 50;

	/*
	Pozycje napisow:
	{wspolrzedna x, wspolrzedna y}
	*/

	const int positions[6][2] = { { x / 3, y / 20 * 3 },
	{ x / 3, y / 20 * 6 },
	{ x / 3, y / 20 * 9 },
	{ x / 3, y / 20 * 12 },
	{ x / 3, y / 20 * 15 },
	{ x / 5, y / 20 * 3 } };

	//int pointer_position_min = positions[0][1]; // skrajna pozycja na gorze
	//int pointer_position_max = positions[5][1]; // skrajna pozycja na dole

	//int pointer_position = positions[0][1]; // aktualna pozycja

	/*
	i to zmienna ktora posluzy do przesuwania znacznika po poszczegolnych
	opcjach w menu
	*/

	int i = 0;


	if (!arial.loadFromFile("arial.ttf"))
	{
		
	};

	/*
	Po kolei definiujemy jak beda wygladac poszczegolne obiekty sf::Text.
	Roznia sie od siebie tylko "tekstem" jaki bada przechowywac i pozycja.
	Poza tym wszystkie sa takie same :)
	*/

	sf::Text tekst1("Tryb uczenia", arial);
	tekst1.setCharacterSize(font_size);
	tekst1.setColor(sf::Color::Yellow);
	tekst1.setStyle(sf::Text::Bold);
	tekst1.setPosition(positions[0][0], positions[0][1]);  // < -- do zmiany

	sf::Text tekst2("Litery", arial);
	tekst2.setCharacterSize(font_size);
	tekst2.setColor(sf::Color::Yellow);
	tekst2.setStyle(sf::Text::Bold);
	tekst2.setPosition(positions[1][0], positions[1][1]);// < -- do zmiany

	sf::Text tekst3("Slowa", arial);
	tekst3.setCharacterSize(font_size);
	tekst3.setColor(sf::Color::Yellow);
	tekst3.setStyle(sf::Text::Bold);
	tekst3.setPosition(positions[2][0], positions[2][1]);// < -- do zmiany

	sf::Text tekst4("Zdania", arial);
	tekst4.setCharacterSize(font_size);
	tekst4.setColor(sf::Color::Yellow);
	tekst4.setStyle(sf::Text::Bold);
	tekst4.setPosition(positions[3][0], positions[3][1]);// < -- do zmiany

	sf::Text tekst5("Wyjscie", arial);
	tekst5.setCharacterSize(font_size);
	tekst5.setColor(sf::Color::Yellow);
	tekst5.setStyle(sf::Text::Bold);
	tekst5.setPosition(positions[4][0], positions[4][1]);// < -- do zmiany

	/*
	Specjalny tekst stosowany do wskazywania opcji w menu.
	*/

	sf::Text wskaznik(">", arial);
	wskaznik.setCharacterSize(font_size);
	wskaznik.setColor(sf::Color::Yellow);
	wskaznik.setStyle(sf::Text::Bold);
	wskaznik.setPosition(positions[5][0], positions[i][1]);// < -- do zmiany

	/*
	Lokalna petla odpowiedzialna za wyswietlanie poczatkowego menu.
	*/

	while (okno.isOpen()) {

		if (okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				okno.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				okno.close(); //wyjscie z programu

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Enter)
			{
				if (i == 0)// tryb uczenia
				{
					okno.clear();
					okno.display();
					return 1;
				}
				else if (i == 1) return 2; // litery
				else if (i == 2) return 3; // slowa
				else if (i == 3) return 4; // zdania
				else if (i == 4) return 0; // wyjscie z programu
			}

			//Obsluga przesuwania znacznika w gore i w dol
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up)
			{
				if (i > 0) i--;
			}

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down)
			{
				if (i < 4) i++;
			}

		}

		okno.clear();

		okno.draw(tekst1);
		okno.draw(tekst2);
		okno.draw(tekst3);
		okno.draw(tekst4);
		okno.draw(tekst5);

		wskaznik.setPosition(positions[5][0], positions[i][1]);
		okno.draw(wskaznik);

		okno.display();

	}//koniec while

	return 0;
}//koniec funkcji menu_start, wracamy do glownej petli

#endif /*START_H*/
