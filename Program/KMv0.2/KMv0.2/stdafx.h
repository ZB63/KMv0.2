// stdafx.h: do³¹cz plik do standardowych systemowych plików do³¹czanych,
// lub specyficzne dla projektu pliki do³¹czane, które s¹ czêsto wykorzystywane, ale
// s¹ rzadko zmieniane
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
// TODO: W tym miejscu odwo³aj siê do dodatkowych nag³ówków wymaganych przez program
