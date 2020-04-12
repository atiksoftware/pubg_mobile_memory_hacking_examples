# ReClass Modified

I have modified reclass for pubg mobile  
i have change ReadRemoteMemory.cpp for read memory  
i changed ReClassNet 8 byte to 4 bytes for 64 bit version. because i used 64 bit driver. and i run x64.  
`But pubg is x86 (32 bit). i was need show data as 32 bit. ` then i changed view functions to 4 byte.

`this program auto connect to aow_exe after you choose any process for attach`
# How it working
i load driver manual.  
my driver `\Device\AmiralRouterDrv`  

but you can run with `ProcessHacker's driver - kprocesshacker.sys`.  
its `Device\KProcessHacker2`  

Open ReClass, attach to any process, it already connect to aow_exe.  
and use