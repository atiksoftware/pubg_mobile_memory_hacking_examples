#include <Windows.h>
#include <string>
#include <iostream>
#include <winternl.h>
#include <ntstatus.h>

#include "NativeCore.hpp"

#include <iostream>
#include <iomanip>


#pragma comment (lib, "ntdll.lib")

#include <Windows.h>
#include <TlHelp32.h>  
#include <tchar.h>

#define KPH_DEVICE_TYPE 0x9999
#define KPH_CTL_CODE(x) CTL_CODE(KPH_DEVICE_TYPE, 0x800 + x, METHOD_NEITHER, FILE_ANY_ACCESS)
#define KPH_READVIRTUALMEMORYUNSAFE KPH_CTL_CODE(58)
#define KPH_READVIRTUALMEMORY KPH_CTL_CODE(56)
#define KPH_WRITEVIRTUALMEMORY KPH_CTL_CODE(57) 

 


class MemoryManager{
public:
 
	HANDLE m_hDriver = nullptr;
	HANDLE processHandle;
	int processId = 0;
	bool allIsWell = false;
	PSIZE_T NumberOfBytes = nullptr;

	std::wstring str2wstr(std::string  in){
		std::wstring out; out.assign(in.begin(), in.end()); return out;
	}
	MemoryManager(){ 
		// if not connected driver : Connect to Amiral Router Driver (undetected)
		if(!m_hDriver){
			connectToDriver("\\Device\\AmiralRouterDrv");
		}
		// if not connected driver : Connect to ProcessHacker's driver - kprocesshacker.sys
		if(!m_hDriver){
			connectToDriver("\\Device\\KProcessHacker2");
		}
		// if not connected yet: exit. 
		if(!m_hDriver){
			return;
		}

 
		// Find AOW Process Id
		int pid = 0;
		int threadCount = 0;
		HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		PROCESSENTRY32 pe;
		pe.dwSize = sizeof(PROCESSENTRY32);
		Process32First(hSnap, &pe);
		while(Process32Next(hSnap, &pe)){
			if(_tcsicmp(pe.szExeFile, _T("aow_exe.exe")) == 0){
				if(pe.cntThreads > threadCount){ threadCount = pe.cntThreads; pid = pe.th32ProcessID; }
			}
		} 
	 
		processId = pid;
		if(processId){
			// Get process handle
			processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
			if(processHandle){ allIsWell = true; }
		}  
	}

	bool connectToDriver(std::string m_strDeviceName){ 
		const auto strObjectName = str2wstr(m_strDeviceName);
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


	void readMemory(PVOID BaseAddress, PVOID Buffer, SIZE_T BufferSize){
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

		NtDeviceIoControlFile(m_hDriver, nullptr, nullptr, nullptr, &ioStatusBlock, KPH_READVIRTUALMEMORY, &input, sizeof(input), nullptr, 0);

	}
 
};

auto MM = new MemoryManager();

bool RC_CallConv ReadRemoteMemory(RC_Pointer handle, RC_Pointer address, RC_Pointer buffer, int offset, int size)
{
	buffer = reinterpret_cast<RC_Pointer>(reinterpret_cast<uintptr_t>(buffer) + offset);

	MM->readMemory(address, buffer, size);

	return true;
}
