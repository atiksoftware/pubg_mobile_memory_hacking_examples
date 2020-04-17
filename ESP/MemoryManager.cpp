#include "pch.h"


MemoryManager* g_pMemoryManager = new MemoryManager();


MemoryManager::MemoryManager(){}


MemoryManager::~MemoryManager(){}


void MemoryManager::init(int pid, bool debug){
	// if not connected driver : Connect to Amiral Router's Driver (undetected)
	if(!m_hDriver){
		if(debug){
			std::cout << termcolor::blue << "Try connect to \\Device\\AmiralRouterDrv \n" << termcolor::reset;
		}
		connectToDriver("\\Device\\AmiralRouterDrv");
	}
	// if not connected driver : Connect to ProcessHacker's driver - kprocesshacker.sys
	if(!m_hDriver){
		if(debug){
			std::cout << termcolor::blue << "Try connect to \\Device\\KProcessHacker2 \n" << termcolor::reset;
		}
		connectToDriver("\\Device\\KProcessHacker2");
	}
	// if not connected yet: exit. 
	if(!m_hDriver){
		if(debug){
			std::cout << termcolor::red << "Can not connect to any driver. Please be sure to driver is loaded. \n";
		}
		return;
	}
	if(debug){
		std::cout << termcolor::yellow << "Connecting to driver: " << termcolor::green << "SUCCESS. \n" << termcolor::reset;
	}

	// Find AOW Process Id
	int threadCount = 0;
	processId = pid;
	if(!processId){
		if(debug){
			std::cout << termcolor::red << "\nNot set Process Id. It will search for aow_exe.exe \n" << termcolor::reset;
		}
		HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		PROCESSENTRY32 pe;
		pe.dwSize = sizeof(PROCESSENTRY32);
		Process32First(hSnap, &pe);
		while(Process32Next(hSnap, &pe)){
			if(_tcsicmp(pe.szExeFile, _T("aow_exe.exe")) == 0){
				if(pe.cntThreads > threadCount){
					threadCount = pe.cntThreads; pid = pe.th32ProcessID;
				}
			}
		}
		processId = pid;
	}
	if(debug){
		std::cout << termcolor::blue << "PID : " << termcolor::green << pid << " \n" << termcolor::reset;
	}


	if(processId){
		// Get process handle
		processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
		if(debug){
			std::cout << termcolor::blue << "HWND : " << termcolor::green << std::hex << (int)processHandle << std::dec << " \n" << termcolor::reset;
		}
		if(processHandle){
			allIsWell = true;
		}
	} else{
		if(debug){
			std::cout << termcolor::red << "\nCant connected to process. Process not running or your app not admin mode ! \n" << termcolor::reset;
		}
	}

}


bool  MemoryManager::connectToDriver(std::string m_strDeviceName){
	std::wstring strObjectName;
	strObjectName.assign(m_strDeviceName.begin(), m_strDeviceName.end());
	UNICODE_STRING objectName;
	HANDLE hNtDriver;
	OBJECT_ATTRIBUTES objectAttributes;
	IO_STATUS_BLOCK isb;
	RtlInitUnicodeString(&objectName, strObjectName.c_str());
	InitializeObjectAttributes(&objectAttributes, &objectName, FILE_NON_DIRECTORY_FILE, NULL, NULL);
	NTSTATUS status = NtOpenFile(&hNtDriver, FILE_GENERIC_READ, &objectAttributes, &isb, FILE_SHARE_READ, FILE_NON_DIRECTORY_FILE);
	if(status == STATUS_SUCCESS){
		m_hDriver = hNtDriver;
		return true;
	}
	return false;
}


void MemoryManager::readMemory(PVOID BaseAddress, PVOID Buffer, SIZE_T BufferSize){
	if(!allIsWell)
		return;

	struct{
		HANDLE ProcessHandle;
		PVOID BaseAddress;
		PVOID Buffer;
		SIZE_T BufferSize;
		PSIZE_T NumberOfBytesRead;
	} input = { processHandle, BaseAddress, Buffer, BufferSize, NumberOfBytes };

	IO_STATUS_BLOCK ioStatusBlock;

	NtDeviceIoControlFile(m_hDriver, nullptr, nullptr, nullptr, &ioStatusBlock, MM_READVIRTUALMEMORY, &input, sizeof(input), nullptr, 0);

}




bool MemoryManager::search(BYTE * bSearchData, int nSearchSize, DWORD_PTR dwStartAddr, DWORD_PTR dwEndAddr, BOOL bIsCurrProcess, int iSearchMode, std::vector<DWORD_PTR> &vRet){

	MEMORY_BASIC_INFORMATION	mbi;
	std::vector<MEMORY_REGION> m_vMemoryRegion;
	mbi.RegionSize = 0x400;
	DWORD dwAddress = dwStartAddr;

	MEMORY_REGION memSectorList[1000];

	int memSectorIndex = 0;
	while(VirtualQueryEx(processHandle, (LPCVOID)dwAddress, &mbi, sizeof(mbi)) && (dwAddress < dwEndAddr) && ((dwAddress + mbi.RegionSize) > dwAddress)){
		if(
			(mbi.State == MEM_COMMIT) &&
			((mbi.Protect & PAGE_GUARD) == 0) &&
			(mbi.Protect != PAGE_NOACCESS) &&
			((mbi.AllocationProtect & PAGE_NOCACHE) != PAGE_NOCACHE)
			){
			MEMORY_REGION mData = { 0 };
			mData.dwBaseAddr = (DWORD_PTR)mbi.BaseAddress;
			mData.dwMemorySize = mbi.RegionSize;
			m_vMemoryRegion.push_back(mData);
			memSectorList[memSectorIndex] = mData;
			memSectorIndex++;
		}
		dwAddress = (DWORD)mbi.BaseAddress + mbi.RegionSize;
	}

	std::vector<MEMORY_REGION>::iterator it;
	//for(it = m_vMemoryRegion.begin(); it != m_vMemoryRegion.end(); it++){
	int memSectorCount = memSectorIndex;
	memSectorIndex = 0;
	DWORD_PTR curAddr = dwStartAddr;
	while(curAddr < dwEndAddr){
		VirtualQueryEx(processHandle, (LPCVOID)curAddr, &mbi, sizeof(mbi));
		long regionSizeOrg = mbi.RegionSize;
		long regionSize = mbi.RegionSize;
		if(regionSize > 10){
			BYTE* pCurrMemoryData = new BYTE[regionSize];
			ZeroMemory(pCurrMemoryData, regionSize);
			readMemory((PVOID)curAddr, (PVOID*)pCurrMemoryData, regionSize);
			DWORD_PTR dwOffset = 0;
			int iOffset = find(pCurrMemoryData, regionSize, bSearchData, nSearchSize);
			while(iOffset != -1){
				dwOffset += iOffset;
				vRet.push_back(dwOffset + curAddr);
				dwOffset += nSearchSize;
				iOffset = find(pCurrMemoryData + dwOffset, regionSize - dwOffset - nSearchSize, bSearchData, nSearchSize);
			}
			delete[] pCurrMemoryData;
		}
		memSectorIndex++;
		curAddr = curAddr + (DWORD_PTR)regionSizeOrg;
		continue;
	}
	return TRUE;
}


int MemoryManager::find(BYTE *buffer, int dwBufferSize, BYTE *bstr, DWORD dwStrLen){
	if(dwBufferSize < 0){
		return -1;
	}
	DWORD  i, j;
	for(i = 0; i < dwBufferSize; i++){
		for(j = 0; j < dwStrLen; j++){
			if(buffer[i + j] != bstr[j] && bstr[j] != '?')
				break;
		}
		if(j == dwStrLen)
			return i;
	}
	return -1;
}



DWORD MemoryManager::dRead(DWORD base){
	readMemory((PVOID)base, &_d, 4);
	return _d;
}

float MemoryManager::fRead(DWORD base){
	readMemory((PVOID)base, &_f, 4);
	return _f;
}
int MemoryManager::iRead(DWORD base){
	readMemory((PVOID)base, &_i, 4);
	return _i;
}