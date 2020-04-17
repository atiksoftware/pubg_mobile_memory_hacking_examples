#pragma once
#include "pch.h"


#define MM_DEVICE_TYPE 0x9999
#define MM_CTL_CODE(x) CTL_CODE(MM_DEVICE_TYPE, 0x800 + x, METHOD_NEITHER, FILE_ANY_ACCESS)
#define MM_READVIRTUALMEMORY MM_CTL_CODE(56)

typedef struct _MEMORY_REGION{
	DWORD_PTR dwBaseAddr;
	DWORD_PTR dwMemorySize;
}MEMORY_REGION;

class MemoryManager{
public:
	MemoryManager();
	~MemoryManager();


	HANDLE m_hDriver = nullptr;
	HANDLE processHandle;
	int processId = 0;
	bool allIsWell = false;
	PSIZE_T NumberOfBytes = nullptr;

	DWORD _d;
	float _f;
	int _i;


	void init(int pid, bool debug);

	bool connectToDriver(std::string m_strDeviceName);

	void readMemory(PVOID BaseAddress, PVOID Buffer, SIZE_T BufferSize);

	bool search(BYTE * bSearchData, int nSearchSize, DWORD_PTR dwStartAddr, DWORD_PTR dwEndAddr, BOOL bIsCurrProcess, int iSearchMode, std::vector<DWORD_PTR>& vRet);

	int find(BYTE * buffer, int dwBufferSize, BYTE * bstr, DWORD dwStrLen);

	DWORD dRead(DWORD base);
	float fRead(DWORD base);
	int iRead(DWORD base);

};


extern MemoryManager* g_pMemoryManager;