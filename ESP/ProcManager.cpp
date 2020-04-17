#include "pch.h"


ProcManager::ProcManager(){}


ProcManager::~ProcManager(){}


int ProcManager::getAowProcID(){
	int pid = 0;
	int threadCount = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnap, &pe);
	while(Process32Next(hSnap, &pe)){
		if(_tcsicmp(pe.szExeFile, _T("aow_exe.exe")) == 0){
			if((int)pe.cntThreads > threadCount){
				threadCount = pe.cntThreads;
				pid = pe.th32ProcessID;
			}
		}
	}

	return pid;
}