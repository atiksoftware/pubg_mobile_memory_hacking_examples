#include "pch.h"

Esp* g_pEsp = new Esp();

Esp::Esp(){}


Esp::~Esp(){}


int Esp::iGet(DWORD base){
	return g_pMemoryManager->iRead(base);
}
float Esp::fGet(DWORD base){
	return g_pMemoryManager->fRead(base);
}
DWORD Esp::dGet(DWORD base){
	return g_pMemoryManager->dRead(base);
}




void Esp::init(){
	viewWordBase = getViewWorld();

	if(viewWordBase){
		std::cout << "VWBASE : " << termcolor::green << std::hex << viewWordBase << std::dec << termcolor::reset << "\n";
	} else{
		std::cout << termcolor::red << "View World Not Found ! \n" << termcolor::reset;
		return;
	}
	uWorld = viewWordBase - 4217216;
	gNames = viewWordBase - 1638204;
	std::cout << "uWorld : " << termcolor::green << std::hex << uWorld << std::dec << termcolor::reset << "\n";
	std::cout << "gNames : " << termcolor::green << std::hex << gNames << std::dec << termcolor::reset << "\n";
}

DWORD Esp::getViewWorld(){

	BYTE pattern[] = { 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x01 };
	
	std::vector<DWORD_PTR> foundedBases;

	g_pMemoryManager->search(pattern, sizeof(pattern), 0x26000000, 0x30000000, false, 0, foundedBases);

	for(int i = 0; i < foundedBases.size(); i++){
		DWORD cand = foundedBases[i] - 0x20;
		DWORD eng = dGet(cand) + 0x20;
		DWORD tmp = dGet(eng) + 0x200;
		float v1, v2, v3, v4;
		v1 = fGet(tmp + 0x8);
		v2 = fGet(tmp + 0x18);
		v3 = fGet(tmp + 0x28);
		v4 = fGet(tmp + 0x38);
		if(v1 == 0 && v2 == 0 && v3 == 0 && v4 >= 3){
			return cand;
		}
	}
	return 0;

}
