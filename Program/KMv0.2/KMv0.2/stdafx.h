// stdafx.h: do��cz plik do standardowych systemowych plik�w do��czanych,
// lub specyficzne dla projektu pliki do��czane, kt�re s� cz�sto wykorzystywane, ale
// s� rzadko zmieniane
//

#pragma once

#include "targetver.h"

#ifndef STDAFX
#define STDAFX


/*Bibliotek SFML'a*/
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio.hpp>

/*Odtwarzanie dzwieku*/
#include "sound_file.h"
#include "box.h"

/*Tryby gry*/
//#include "start.h"
//#include "training_mode.h"
//#include "easy_mode.h"
//#include "medium_mode.h"
//#include "hard_mode.h"

/*Standardowe biblioteki*/
#include <iostream>

#include <map>
#include <string>
#include <vector>
#include <cstdlib>

/*Zabic to*/
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#endif STDAFX
// TODO: W tym miejscu odwo�aj si� do dodatkowych nag��wk�w wymaganych przez program
