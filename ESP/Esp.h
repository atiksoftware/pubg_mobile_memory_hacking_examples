#pragma once
#include "pch.h"

class Esp{
public:
	Esp();
	~Esp();

	DWORD viewWordBase;
	DWORD uWorld;
	DWORD gNames;
	DWORD uWorlds;
	DWORD uLevel;
	DWORD gameInstance;
	DWORD playerController;
	DWORD playerCarry;
	DWORD uMyObject;


	int iGet(DWORD base);
	float fGet(DWORD base);
	DWORD dGet(DWORD base);




	void init();

	DWORD getViewWorld();

};


extern Esp* g_pEsp;