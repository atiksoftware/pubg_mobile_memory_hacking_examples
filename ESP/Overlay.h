#pragma once
#include "pch.h"


class Overlay{
public:
	Overlay();
	~Overlay();

	int left;
	int top;
	int width;
	int height;



	sf::RenderWindow window;



	void createWindow();
	void init();
};

extern Overlay* g_pOverlay;