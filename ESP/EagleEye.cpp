 

#include "pch.h"
#include <iostream>

int main()
{



	int gamePid = ProcManager::getAowProcID();
	 

	g_pMemoryManager->init(gamePid, true);


	g_pEsp->init();



	g_pOverlay->init();




	sf::Vertex line[2];
	line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Green;
	line[0].position = sf::Vector2f(0,0);
	line[1].position = sf::Vector2f(500,500);



	while(g_pOverlay->window.isOpen()){

		
		g_pOverlay->window.clear(sf::Color::Transparent);


		/* DRAW */

		g_pOverlay->window.draw(line, 2, sf::Lines);


		g_pOverlay->window.display();


	}






    std::cout << "Hello World!\n"; 
}
 