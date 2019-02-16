#ifndef BOX
#define BOX

#include "stdafx.h"
#include <fstream>

class Box
{
private:
	std::map<std::string, Sound_file> tab;

public:

	int fill_box(std::string location)//location to nazwa pliku z ktorego bierzemy nazwy dzwiekow
	{
		std::fstream plik;
		std::string bufor;
		Sound_file *wsk;
		
		plik.open("sounds/" + location + ".txt", std::ios::in);

		if (!plik.good()) return 1; // nie udalo sie otworzyc pliku index

		while (!plik.eof())
		{
			getline(plik, bufor);
			if (bufor.length() == 0) break;
			
			try
			{
				wsk = new Sound_file();

				tab.insert({bufor, *wsk});
				tab.find(bufor)->second.load(bufor);
				delete wsk;
			}
			catch (...)
			{
				tab.clear();
				plik.close();
				return 2;
			}
		}

		plik.close();
		return 0;
	}

	bool play(std::string n) // zwraca true kiedy udalo sie odtworzyc dzwiek
	{
		std::map<std::string, Sound_file>::iterator it;
		it = tab.find(n);

		if (it == tab.end() || tab.empty()) 
		{
			//std::cout << n << " sound file not found!";// robocza obsluga bledu, do zmiany
			return false;
		}
		else
		{
			it->second.play();
		}
		return true;
	}

};

#endif /*BOX*/
