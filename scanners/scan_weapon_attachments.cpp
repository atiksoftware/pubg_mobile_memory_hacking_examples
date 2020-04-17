// PubgPointerScanner.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include "pch.h"
#include <iostream>
#include "MemoryManager.hpp"
#include "termcolor.hpp"

using namespace std;


MemoryManager* MM;


struct Region{
	PVOID base;
	SIZE_T size;
};
Region regions[10000];
int regionCount = 0;


BYTE* buffer;
void loadBuffer(DWORD address, int size){
	delete[] buffer;
	buffer = new BYTE[size];
	MM->readMemory((PVOID)address, buffer, size); 
}
BYTE* bufferTmp = new BYTE[4];
DWORD _dwb;
DWORD dLook(int i){ 
	bufferTmp[0] = buffer[i];
	bufferTmp[1] = buffer[i + 1];
	bufferTmp[2] = buffer[i + 2];
	bufferTmp[3] = buffer[i + 3];
	memcpy(&_dwb, bufferTmp, 4);
	return _dwb;
}



struct Entity{
	DWORD base;
	int value;
	int offset1 = 0;
	int offset2 = 0;
	int offset3 = 0;
	int offset4 = 0;
};
Entity Foundeds[32000000];
int FoundedsCount = 0;
void addFoundedEntity(DWORD base, int value, int of1 = 0, int of2 = 0, int of3 = 0, int of4 = 0){
	Foundeds[FoundedsCount].base = base;
	Foundeds[FoundedsCount].value = value;
	Foundeds[FoundedsCount].offset1 = of1;
	Foundeds[FoundedsCount].offset2 = of2;
	Foundeds[FoundedsCount].offset3 = of3;
	Foundeds[FoundedsCount].offset4 = of4;
	FoundedsCount++;
}



bool isPointer(DWORD i){
	return i > 0x40f72db0 && i < 0x70f72db0;
}

void filterChanged(){
	cout << termcolor::green << "\n Scanning " << termcolor::yellow << "Changeds" << termcolor::reset << "\n";
	int handledCount = FoundedsCount;
	FoundedsCount = 0;
	DWORD _d;
	for(int i = 0; i < handledCount; i++){
		MM->readMemory((PVOID)Foundeds[i].base, &_d, 4);
		if(_d != Foundeds[i].value && isPointer(_d)){
			addFoundedEntity(Foundeds[i].base, _d, Foundeds[i].offset1, Foundeds[i].offset2, Foundeds[i].offset3, Foundeds[i].offset4);
		}
	}
}
void filterUnChanged(){
	cout << termcolor::green << "\n Scanning " << termcolor::yellow << "Changeds" << termcolor::reset << "\n";
	int handledCount = FoundedsCount;
	FoundedsCount = 0;
	DWORD _d;
	for(int i = 0; i < handledCount; i++){
		MM->readMemory((PVOID)Foundeds[i].base, &_d, 4);
		if(_d == Foundeds[i].value){
			addFoundedEntity(Foundeds[i].base, _d, Foundeds[i].offset1, Foundeds[i].offset2, Foundeds[i].offset3, Foundeds[i].offset4);
		}
	}
}
void filterFulushed(){
	cout << termcolor::green << "\n Scanning " << termcolor::yellow << "Changeds" << termcolor::reset << "\n";
	int handledCount = FoundedsCount;
	FoundedsCount = 0;
	DWORD _d;
	for(int i = 0; i < handledCount; i++){
		MM->readMemory((PVOID)Foundeds[i].base, &_d, 4);
		if(_d == 0){
			addFoundedEntity(Foundeds[i].base, _d);
		}
	}
}
void filterAPointer(){
	cout << termcolor::green << "\n Scanning " << termcolor::yellow << "Changeds" << termcolor::reset << "\n";
	int handledCount = FoundedsCount;
	FoundedsCount = 0;
	DWORD _d;
	for(int i = 0; i < handledCount; i++){
		MM->readMemory((PVOID)Foundeds[i].base, &_d, 4);
		if(isPointer(_d)){
			addFoundedEntity(Foundeds[i].base, _d);
		}
	}
}
void filterExport(){
	cout << termcolor::green << "\n Scanning " << termcolor::yellow << "Changeds" << termcolor::reset << "\n";
	ofstream myfile;
	myfile.open("C:/Users/Amiral/source/repos/PubgPointerScanner/x64/Release/dump.txt");
	myfile << "Dumped list with " << FoundedsCount << " items.\n";
	for(int i = 0; i < FoundedsCount; i++){
		myfile << std::hex << Foundeds[i].base << " : " << Foundeds[i].value;
		myfile << " > " << Foundeds[i].offset1;
		myfile << " > " << Foundeds[i].offset2;
		myfile << " > " << Foundeds[i].offset3;
		myfile << " > " << Foundeds[i].offset4;
		myfile << "\n";
	}
	myfile.close();
	return;
}

void searchForPointers(){
	int playerBase;
	cout << termcolor::blue << termcolor::magenta << " What you want ? " << termcolor::reset;
	cin >> playerBase;
	DWORD _q,_w,_e;
	for(int q = 4; q < 0x400; q += 4){
		MM->readMemory((PVOID)(playerBase + q), &_q, 4);
		if(isPointer(_q)){
			for(int w = 4; w < 0x400; w += 4){
				MM->readMemory((PVOID)(q + w), &_w, 4);
				for(int i = 0; i < FoundedsCount; i++){
					if(q + w == Foundeds[i].base || Foundeds[i].value == _w || Foundeds[i].base == _w || Foundeds[i].value == q + w){
						std::cout << "FOUND !";
					}
				}
				if(isPointer(_w)){
					for(int e = 4; e < 0x400; e += 4){
						MM->readMemory((PVOID)(w + e), &_e, 4);
						for(int i = 0; i < FoundedsCount; i++){
							if(w + e == Foundeds[i].base || Foundeds[i].value == _e || Foundeds[i].base == _e || Foundeds[i].value == w + e){
								std::cout << "FOUND !";
							}
						}
					}
				}


			}
		}
	}
}







int main()
{
 
	MM = new MemoryManager();

	 

	SYSTEM_INFO si;
	GetSystemInfo(&si); 
	MEMORY_BASIC_INFORMATION info;
	vector<char> chunk;
	char* p = 0; bool cont = true;
	while(cont && p < si.lpMaximumApplicationAddress){
		 
		if(VirtualQueryEx(MM->processHandle, p, &info, sizeof(info)) == sizeof(info)){
			p = (char*)info.BaseAddress;
			chunk.resize(info.RegionSize);
			p += info.RegionSize;
			regions[regionCount].base = info.BaseAddress; regions[regionCount].size = info.RegionSize; regionCount++;
			if(info.BaseAddress >= (PVOID)0x70000000){ cont = false; } 
		} 
	}
 
	cout << "Founded " << regionCount << " regions\n";
	cout << "Scanning pointers\n";
	 

	DWORD _d;
	for(int i = 0; i < regionCount - regionCount; i++){
		if((DWORD)regions[i].base < 0x40F72E40){
			continue;
		}
		cout << "Scanning region " << i << "/" << regionCount << " -> ";
		cout << " BASE : " << hex  << (DWORD)regions[i].base << dec;
		cout << " SIZE : " << (int)regions[i].size;
		cout << "\n";
		//cout << "Scanning region " << i << "/" << regionCount << " -> Size : " << (trunc((int)regions[i].size / 1000 / 1000 * 10) / 10) << "\n";
		loadBuffer((DWORD)regions[i].base, (int)regions[i].size);
		for(int b = 0; b < (int)regions[i].size - 4; b += 4){
			_d = dLook(b);
			if(isPointer(_d)){
				addFoundedEntity((DWORD)regions[i].base + b, _d); 
			}
		}
	}




	int AttBase = 0;
	cout << " AttBase: ";
	cin >> AttBase;
	DWORD _q, _w, _e, _r;

	for(int q = 0; q < 0x500; q += 4){
		//std::cout << q << "\n";
		MM->readMemory((PVOID)(AttBase + q), &_q, 4);
		if(_q == 203005){ 
			std::cout << termcolor::yellow;
			cout << std::hex;
			cout << q << " " << std::dec << termcolor::reset << "\n";
		}
		if(isPointer(_q)){
			for(int w = 0; w < 0x500; w += 4){
				MM->readMemory((PVOID)(_q + w), &_w, 4);
				if(_w == 203005){
					std::cout << "YESS 2 \n";
				}
				if(isPointer(_w)){
					for(int e = 0; e < 0x500; e += 4){
						MM->readMemory((PVOID)(_w + e), &_e, 4);
						if(_e == 203005){
							std::cout << termcolor::red;
							cout << std::hex;
							cout << q << " " << w << " " << e << " " << std::dec << termcolor::reset << "\n";
						}
						if(isPointer(_e)){
							for(int r = 0; r < 0x500; r += 4){
								MM->readMemory((PVOID)(_e + r), &_r, 4);
								if(_r == 203005){
									std::cout << termcolor::green;
									cout << std::hex;
									cout << q << " " << w << " " << e << " " << r << " " << std::dec << termcolor::reset << "\n";
								}
							}
						}
					}
				}
			}
		}
		
	}

	cout << " NOOO !!!"; 
	cin >> AttBase;
	Sleep(10000);





	/**********************************/
	int weaponBase = 0;
	cout << " weaponbase: " ;
	cin >> weaponBase;
	 
	for(int q = 0; q < 0x500; q += 4){ 
		std::cout << q << "\n";
		MM->readMemory((PVOID)(weaponBase + q), &_q, 4);
		if(!isPointer(_q)){ continue; }
		addFoundedEntity(weaponBase + q, _q,q);
		for(int w = 0; w < 0x500; w += 4){
			MM->readMemory((PVOID)(_q + w), &_w, 4);
			if(!isPointer(_w)){ continue; }
			addFoundedEntity(_q + w, _w, q, w);
			for(int e = 0; e < 0x500; e += 4){
				MM->readMemory((PVOID)(_w + e), &_e, 4);
				if(!isPointer(_e)){ continue; }
				addFoundedEntity(_w + e, _e, q, w,e);
				 
			}
		}
	}




	int consoleInput = 0;
	while(true){
		cout << termcolor::blue << "\n\n =======================================\n" << termcolor::green << " Handled " << termcolor::red << FoundedsCount << termcolor::green << " items" << termcolor::reset << "\n";
		cout << termcolor::blue << " 1" << termcolor::reset << " : Changed \n";
		cout << termcolor::blue << " 2" << termcolor::reset << " : UnChanged \n";
		cout << termcolor::blue << " 3" << termcolor::reset << " : Flushed \n";
		cout << termcolor::blue << " 4" << termcolor::reset << " : A Pointer \n";
		cout << termcolor::blue << " 5" << termcolor::reset << " : Dump to file \n";
		cout << termcolor::blue << " 6" << termcolor::reset << " : Search for playerEntity \n";
		cout << termcolor::blue << termcolor::magenta << " What you want ? " << termcolor::reset;
		cin >> consoleInput;
		if(consoleInput == 1){
			filterChanged();
		}if(consoleInput == 2){
			filterUnChanged();
		}if(consoleInput == 3){
			filterFulushed();
		}if(consoleInput == 4){
			filterAPointer();
		}if(consoleInput == 5){
			filterExport();
		}if(consoleInput == 6){
			searchForPointers();
		}
	}


    cout << FoundedsCount << "\n";
    cout << "Hello World!\n"; 
}
 