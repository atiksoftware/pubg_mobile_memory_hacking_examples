#include "pch.h"

Overlay* g_pOverlay = new Overlay();


Overlay::Overlay(){}


Overlay::~Overlay(){}


void Overlay::createWindow(){


	HWND hwndMain = FindWindowEx(NULL, NULL, L"TXGuiFoundation", L"Gameloop【Turbo AOW Motoru】");
	if(IsWindow(hwndMain)){
		HWND hwndSub = FindWindowEx(hwndMain, NULL, L"AEngineRenderWindowClass", NULL);
		RECT rect;
		GetWindowRect(hwndSub, &rect);
		left = rect.left;
		top = rect.top;
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}
	else{
		left = 1;
		top = 1;
		width = GetSystemMetrics(SM_CXSCREEN) - 2;
		height = GetSystemMetrics(SM_CYSCREEN) - 2;
	}



	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	window.create(
		sf::VideoMode(width, height),
		"Rendom Title here",
		sf::Style::None,
		settings
	);

	HWND hwnd = window.getSystemHandle();

	SetWindowLong(hwnd, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);

	MARGINS margin = { -1 };
	DwmExtendFrameIntoClientArea(hwnd, &margin);

	SetWindowPos(hwnd, HWND_TOPMOST, left, top, width, height, SWP_SHOWWINDOW);
	UpdateWindow(hwnd);



}

void Overlay::init(){

	createWindow();
}
