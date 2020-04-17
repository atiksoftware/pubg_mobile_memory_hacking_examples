 
#ifndef PCH_H
#define PCH_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#pragma comment(lib,"Dwmapi.lib")

#include <Windows.h>
#include <dwmapi.h>

#include <TlHelp32.h>
#include <tchar.h>
 
#include <string>
#include <iostream>
#include <winternl.h>
#include <ntstatus.h>
#include <iomanip> 
#pragma comment (lib, "ntdll.lib")



#include "termcolor.h" 

#include "ProcManager.h" 
#include "MemoryManager.h"

#include "Overlay.h"

#include "Esp.h"



#endif //PCH_H
