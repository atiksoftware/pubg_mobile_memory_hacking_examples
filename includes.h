#pragma once

#pragma warning( disable : 4244 )
#pragma warning( disable : 4309 )
#pragma warning( disable : 4838 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4334 )
#pragma warning( disable : 4305 )
#pragma warning( disable : 4805 )
#pragma warning( disable : 4018 )
#pragma warning( disable : 4172 )
#pragma warning( disable : 4042 )
#pragma warning( disable : 4996 )

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#pragma comment(lib,"wininet.lib")
#pragma comment(lib, "Dwmapi.lib")

#include <windows.h>
#include <windowsx.h> 
#include <stdio.h>
#include <psapi.h>
#include <time.h>
#include <math.h>
#include <string>
#include <iostream>
#include <Dwmapi.h> 


#include <TlHelp32.h>  
#include <stack>
#include <vector> 
#include <future> 
#include <wchar.h>
#include <sstream> 
#include <thread>
#include <chrono>  
 
#include <list> 
#include <tchar.h>
 
#include <locale> 
#include <codecvt> 

#define MAX_ENTITY 1024

// Entitiy type struct
extern struct ItemAsset_t{
	int entityId;
	std::string className;
	std::string displayName;

	int fontType = 1;
	int fontSize = 12;
	sf::Color textColor;
	sf::Color bgColor;
	sf::Color textOutlineColor;
	int textOutlineSize;

	int inboxFontType = 1;
	int inboxFontSize = 12;
	sf::Color inboxTextColor;

	int subtextFontType = 1;
	int subtextFontSize = 9;
	sf::Color subtextColor;
	sf::Color subtextOutlineColor;
	int subtextOutlineSize = 0;

	int itemType = 0;

	sf::Sprite icon;
	bool hasIcon;
};

// Vectors
extern struct Vector2{
	float x = 0;
	float y = 0;
};
extern struct Vector3{
	float x = 0;
	float y = 0;
	float z = 0;
};
extern struct Vector4{
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;
};
extern struct VectorRect{
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
};

// its for Player Inventory Box Item
extern struct BoxItem_t{
	int itemId = 0;
	int count = 0;
	std::string className = "";
	std::string displayName = "";
	ItemAsset_t itemConfig;
	sf::Sprite icon;
	bool hasIcon;
};
// its for entity player weapon details
extern struct playerWeapon{
	int itemId = 0;
	int ammoCur = 0;
	int ammoMax = 0;
	std::string displayName = "";
	sf::Text textWeaponName;
	sf::Text textWeaponAmmo;
};

// its for world to screen
// i found this from ESP source for PUBGM v0.17.0 on Gameloop
extern struct D3DMatrix{
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;
};

// its for player bound calculate
// i found this from ESP source for PUBGM v0.17.0 on Gameloop
extern struct FTTransform2_t{
	Vector4 Rotation;
	Vector3 Translation;
	float ddd;
	Vector3 Scale3D;
};


// Colorful terminal write lines
#include "termcolor.hpp"
// Converting types. Ex: str to float..
#include "Convert.h"
// Ini fine reader
#include "INIReader.h"

/*
	Soryy for this
	but i removed some headers from this about bypass gameloop detection
	i can't share the my special method
*/

// these same like BypaPH - Process Hacker's bypass (read/write any process virtual memory & kernel mem)
#include "Driver.hpp"
#include "BypaPH.hpp"

// these about find process id and scanning memory
// same like https://github.com/fly8888/pubg-mobile-esp
#include "ProcManager.h" 
#include "MemoryManager.h" 

// SFML library
#include "Overlay.h"
// Icons,fonts and audio 
#include "AssetManager.h"
// Entity class and other details
#include "EntityClasses.h"
// An Entity object
#include "Entity.h"
// ESP scanner
#include "Esp.h"