# Pubg Mobile Gameloop ESP Source
[![GitHub](https://img.shields.io/badge/Author-Amiral%20Router-blue)]()
[![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fatiksoftware%2Fpubg_mobile_memory_hacking_examples)]()
[![GitHub stars](https://img.shields.io/github/stars/atiksoftware/pubg_mobile_memory_hacking_examples?color=brightgreen)]()
[![GitHub contributors](https://img.shields.io/github/contributors/atiksoftware/pubg_mobile_memory_hacking_examples?color=brightgreen)]()
[![GitHub issues](https://img.shields.io/github/issues/atiksoftware/pubg_mobile_memory_hacking_examples?color=blue)]()


[https://discord.gg/r29z6XW](https://discord.gg/r29z6XW)

Pubg Mobile Emulator Gameloop Memory Hacking C++ code examples. Ex: Name, Coord, Bones, Weapons, Items, Box, Drop etc.  

**[Youtube Video](https://www.youtube.com/watch?v=4KoCf4DoBKQ)**
[![PUBG ESP EXAMPLE SCREENSHOT](https://raw.githubusercontent.com/atiksoftware/pubg_mobile_memory_hacking_examples/master/screens/example_screen.jpg)](https://www.youtube.com/watch?v=4KoCf4DoBKQ)

I just created this quickly. Then text not pretty good.  

`I not share project. because i cant share bypass methos. I just share how can you find detas in memory`

## Tutorial
[![#1 - How Can I Find Pubg Mobile View Matrix Pattern](https://i3.ytimg.com/vi/ya0rbAwFKdY/default.jpg)](https://www.youtube.com/watch?v=ya0rbAwFKdY)
[![#2 - Create a New C++ Console Application | Pubg Mobile Hacking Tutorial](https://i3.ytimg.com/vi/8DxZExFLges/default.jpg)](https://www.youtube.com/watch?v=8DxZExFLges)
[![#3 - Create a Overlay Window - Import SFML Library | Pubg Mobile Hacking Tutorial](https://i3.ytimg.com/vi/mukNNm5MxJE/default.jpg)](https://www.youtube.com/watch?v=mukNNm5MxJE)
[![#4 - Process Manager - Find Aow Process ID | Pubg Mobile Hacking Tutorial](https://i3.ytimg.com/vi/nVuDz1hbYEs/default.jpg)](https://www.youtube.com/watch?v=nVuDz1hbYEs)
[![#5 - How Can I Change Driver Name - kprocesshacker.sys | Pubg Mobile Hacking Tutorial](https://i3.ytimg.com/vi/uJiurAlhsWw/default.jpg)](https://www.youtube.com/watch?v=uJiurAlhsWw)
[![#6 - Colorful Terminal Output | Pubg Mobile Hacking Tutorial](https://i3.ytimg.com/vi/UI6xyrmGtQ4/default.jpg)](https://www.youtube.com/watch?v=UI6xyrmGtQ4)
[![#7 - Memory Manager - Connect to Driver | Pubg Mobile Hacking Tutorial](https://i3.ytimg.com/vi/V3bd7XEfW68/default.jpg)](https://www.youtube.com/watch?v=V3bd7XEfW68)
[![#8 - ESP - Find Base Points | Pubg Mobile Hacking Tutorial](https://i3.ytimg.com/vi/TpCXqkRH08A/default.jpg)](https://www.youtube.com/watch?v=TpCXqkRH08A)
[![#9 - Switch to Smartgaga | Pubg Mobile Hacking Tutorial](https://i3.ytimg.com/vi/RYxih0Phqgg/default.jpg)](https://www.youtube.com/watch?v=RYxih0Phqgg)
[![#10 - Scan Entity List And Draw | Pubg Mobile Hacking Tutorial](https://i3.ytimg.com/vi/RXzzC8rI6H4/default.jpg)](https://www.youtube.com/watch?v=RXzzC8rI6H4)

## Just Examples
Hi dear visitor. Its not hacking app or shared app. It just example codes pool. I will push here simples code about what i know and what i experied on pubg memory hacking. My purpose is find again if i forget or if some one need it, he can find it.


## What I do
I used C++, and used SFML library  
I have find patterns and ofsets about pubg gameloop

## Referances
+ ESP source for PUBGM v0.17.0 on Gameloop  
Author : xiderowg  
Link : [https://www.unknowncheats.me/forum/pubg-mobile/379241-esp-source-pubgm-v0-17-0-gameloop.html](https://www.unknowncheats.me/forum/pubg-mobile/379241-esp-source-pubgm-v0-17-0-gameloop.html)  
i start with xiderowg's source  
it was C#.   
i created c++ project and used his pattern and offsets  
+ BypaPH - Process Hacker's bypass (read/write any process virtual memory & kernel mem)  
Author : harakirinox  
Link : [https://www.unknowncheats.me/forum/anti-cheat-bypass/312791-bypaph-process-hackers-bypass-read-write-process-virtual-memory-kernel-mem.html](https://www.unknowncheats.me/forum/anti-cheat-bypass/312791-bypaph-process-hackers-bypass-read-write-process-virtual-memory-kernel-mem.html)

## Whats my news
+ Vehicle HP
+ Vehicle Fuel
+ PlayerDeadInventoryBox
+ PlayerDeadInventoryBox Items
+ Airdrop Items

You can see my codes and offsets
[ESP Source File ](https://github.com/atiksoftware/pubg_mobile_memory_hacking_examples/blob/master/Esp.cpp)
  
---  
## Whats defferent between Gameloop/Smartgaga and LDPlayer/Memu
As **xiderowg**'s says on https://www.unknowncheats.me/forum/pubg-mobile/379241-esp-source-pubgm-v0-17-0-gameloop.html

`Gameloop is based on AOW/QEMU Engine, while LDPlayer is using VirtualBox, these offsets and pattern may not be applicable to LDPlayer.`
  
---  
## Pubg Mobile Entity Offsets

[![Pubg Mobile Player Entity Offsets](https://raw.githubusercontent.com/atiksoftware/pubg_mobile_memory_hacking_examples/master/Offsets/images/ReClassThumbnailPlayer.png)](Offsets/Player.md)
[![Pubg Mobile Vehicle Entity Offsets](https://raw.githubusercontent.com/atiksoftware/pubg_mobile_memory_hacking_examples/master/Offsets/images/ReClassThumbnailVehicle.png)](Offsets/Vehicle.md)
[![Pubg Mobile Invetory Entity Offsets](https://raw.githubusercontent.com/atiksoftware/pubg_mobile_memory_hacking_examples/master/Offsets/images/ReClassThumbnailInventory.png)](Offsets/Inventory.md)
---  
## Player Details
![](https://raw.githubusercontent.com/atiksoftware/pubg_mobile_memory_hacking_examples/master/screens/example_player_reclass.jpg)
---  
## Player Details
 ```c++
DWORD NavMesh = dGet(Entities[i]->entityAddv + 312);
Entities[i]->position = v3fGet(NavMesh + 0x150);
Entities[i]->onEntiyPositionChanged();
Entities[i]->velocity = v3fGet(NavMesh + 0x1A0);
Entities[i]->onEntiyVelocityChanged();

Entities[i]->playerWorld = dGet(entityAddv + 0x138);

// Thats UFT16 wchar
strcpy(Entities[i]->playerName, strGet(dGet(entityAddv + 0x5E8), iGet(entityAddv + 0x5EC) * 2));
strcpy(Entities[i]->playerFlag, strGet(dGet(entityAddv + 0x5F4), 4));
strcpy(Entities[i]->playerID, strGet(dGet(entityAddv + 0x604), 22));

Entities[i]->playerStatus = iGet(Entities[i]->playerWorld + 0x364);
Entities[i]->playerTeamId = iGet(entityAddv + 0x610);
Entities[i]->itsMe = 0;
if(entityAddv == uMyObject){
	myTeamID = Entities[i]->playerTeamId;
	MeEntity = Entities[i];
	Entities[i]->itsMe = 1;
}
Entities[i]->itsFriend = 0;
if(myTeamID == Entities[i]->playerTeamId){
	Entities[i]->itsFriend = 1;
}
Entities[i]->playerIsBot = iGet(entityAddv + 0x2B4) == 0 ? true : false;
DWORD tmpAddv = dGet(entityAddv + 0x308);
Entities[i]->bodyAddv = tmpAddv + 0x140;
Entities[i]->boneAddv = dGet(tmpAddv + 0x580) + 0x30;


Entities[i]->rotation = fGet(Entities[i]->playerWorld + 0x128); // ROTATE

/* PSOE Ites not ineger, bytes, but we will read as integer.
1144306736 standing 
1143847984 crouched  
1143684144 creep */
Entities[i]->playerPose = iGet(Entities[i]->playerWorld + 0x130); 

Entities[i]->playerHealth.max = fGet(Entities[i]->entityAddv + 0x77C);
Entities[i]->playerHealth.cur = fGet(Entities[i]->entityAddv + 0x778);
Entities[i]->playerEnergy.max = fGet(Entities[i]->entityAddv + 0x1408);
Entities[i]->playerEnergy.cur = fGet(Entities[i]->entityAddv + 0x140C);

DWORD weaponsCapsule = dGet(Entities[i]->entityAddv + 0x12C);
Entities[i]->playerIsAttacking = false;
for(int w = 0; w < 4; w++){
	DWORD weaponBase = dGet(weaponsCapsule + w * 4);
	DWORD weaponAmmoBase = dGet(weaponBase + 0x54);
	Entities[i]->playerWeapons[w].activity = iGet(weaponBase + 0xDC);
	Entities[i]->playerWeapons[w].state = iGet(weaponBase + 0x4C0);
	Entities[i]->playerWeapons[w].entityId = iGet(dGet(weaponBase + 0x4BC) + 0xC0);
	Entities[i]->playerWeapons[w].maxAmmo = iGet(weaponAmmoBase + 0x7D4);
	Entities[i]->playerWeapons[w].curAmmo = iGet(weaponAmmoBase + 0x7D0);
}
// Bones
Entities[i]->boneActor = vectorBoneRead(Entities[i]->bodyAddv);
for(int b = 0; b < 15; b++){
	Entities[i]->playerBones[b] = getPlayerBone(Entities[i]->boneAddv, Entities[i]->boneActor, i, b);
}
 ```
 ---  
## Vehicle Details
 ```c++
DWORD NavMesh = dGet(Entities[i]->entityAddv + 312);
Entities[i]->position = v3fGet(NavMesh + 0x150);
Entities[i]->onEntiyPositionChanged(); 

Entities[i]->velocity = v3fGet(dGet(Entities[i]->entityAddv + 0x54) + 0x78);
Entities[i]->onEntiyVelocityChanged();
DWORD vehicleCommon = dGet(dGet(Entities[i]->entityAddv + 0x54) + 0x4D8);
Entities[i]->vehicleHealth.max = fGet(vehicleCommon + 0x108);
Entities[i]->vehicleHealth.cur = fGet(vehicleCommon + 0x10C);
Entities[i]->vehicleFuel.max = fGet(vehicleCommon + 0x120);
Entities[i]->vehicleFuel.cur = fGet(vehicleCommon + 0x124);
```
 ---  
## Inventory Details
 ```c++
int boxItemCount = iGet(entityAddv + 0x440);
Entities[i]->inventoryItemCount = 0;
if(boxItemCount < 60){
	DWORD itemEntry = iGet(entityAddv + 0x43C);
	if(itemEntry > 50000){
		for(int h = 0; h < boxItemCount; h++){
			DWORD itemAddv = itemEntry + h * 48;
			Entities[i]->inventoryItems[Entities[i]->inventoryItemCount].entityId = iGet(itemAddv + 0x4);
			if(Entities[i]->inventoryItems[Entities[i]->inventoryItemCount].entityId > 0){
				Entities[i]->inventoryItems[Entities[i]->inventoryItemCount].count = iGet(itemAddv + 0x18);
				Entities[i]->inventoryItemCount++;
			}
		}
	}
} 
```
---  

## Item Details

Item Types  
1 : Loot - Item  
2 : InventoryBox or AirDrop  
5 : Vehicle  
8 : Player 

| entityId | itemType | className                                | displayName                       |
|----------|----------|------------------------------------------|-----------------------------------|
| 103003   | 1        | BP\_Sniper\_AWM\_Wrapper\_C              | AWM                               |
| 103010   | 1        | BP\_Sniper\_QBU\_Wrapper\_C              | QBU                               |
| 103009   | 1        | BP\_Sniper\_SLR\_Wrapper\_C              | SLR                               |
| 103004   | 1        | BP\_Sniper\_SKS\_Wrapper\_C              | SKS                               |
| 103006   | 1        | BP\_Sniper\_Mini14\_Wrapper\_C           | Mini14                            |
| 103002   | 1        | BP\_Sniper\_M24\_Wrapper\_C              | M24                               |
| 103001   | 1        | BP\_Sniper\_Kar98k\_Wrapper\_C           | Kar98k                            |
| 103005   | 1        | BP\_Sniper\_VSS\_Wrapper\_C              | VSS                               |
| 103008   | 1        | BP\_Sniper\_Win94\_Wrapper\_C            | Win94                             |
| 103003   | 7        | BP\_Sniper\_AWM\_C                       | AWM\_C                            |
| 101006   | 7        | BP\_Rifle\_AUG\_C                        | AUG                               |
| 101008   | 1        | BP\_Rifle\_M762\_Wrapper\_C              | M762                              |
| 101003   | 1        | BP\_Rifle\_SCAR\_Wrapper\_C              | SCAR\-L                           |
| 101004   | 1        | BP\_Rifle\_M416\_Wrapper\_C              | M416                              |
| 101002   | 1        | BP\_Rifle\_M16A4\_Wrapper\_C             | M16A\-4                           |
| 101009   | 1        | BP\_Rifle\_Mk47\_Wrapper\_C              | Mk47 Mutant                       |
| 101010   | 1        | BP\_Rifle\_G36\_Wrapper\_C               | G36C                              |
| 101007   | 1        | BP\_Rifle\_QBZ\_Wrapper\_C               | QBZ                               |
| 101001   | 1        | BP\_Rifle\_AKM\_Wrapper\_C               | AKM                               |
| 101005   | 1        | BP\_Rifle\_Groza\_Wrapper\_C             | Groza                             |
| 101006   | 1        | BP\_Rifle\_AUG\_Wrapper\_C               | AUG\_A3                           |
| 104003   | 1        | BP\_ShotGun\_S12K\_Wrapper\_C            | S12K                              |
| 104004   | 1        | BP\_ShotGun\_DP12\_Wrapper\_C            | DBS                               |
| 104001   | 1        | BP\_ShotGun\_S686\_Wrapper\_C            | S686                              |
| 104002   | 1        | BP\_ShotGun\_S1897\_Wrapper\_C           | S1897                             |
| 106006   | 1        | BP\_ShotGun\_SawedOff\_Wrapper\_C        | SawedOff                          |
| 102005   | 1        | BP\_MachineGun\_PP19\_Wrapper\_C         | PP19Bizon                         |
| 102004   | 1        | BP\_MachineGun\_TommyGun\_Wrapper\_C     | TommyGun                          |
| 102007   | 1        | BP\_MachineGun\_MP5K\_Wrapper\_C         | MP5K                              |
| 102002   | 1        | BP\_MachineGun\_UMP9\_Wrapper\_C         | UMP9                              |
| 102003   | 1        | BP\_MachineGun\_Vector\_Wrapper\_C       | Vector                            |
| 102001   | 1        | BP\_MachineGun\_Uzi\_Wrapper\_C          | Uzi                               |
| 106003   | 1        | BP\_Pistol\_R1895\_Wrapper\_C            | R1895                             |
| 106008   | 1        | BP\_Pistol\_Vz61\_Wrapper\_C             | Vz61                              |
| 106001   | 1        | BP\_Pistol\_P92\_Wrapper\_C              | P92                               |
| 106004   | 1        | BP\_Pistol\_P18C\_Wrapper\_C             | P18C                              |
| 106005   | 1        | BP\_Pistol\_R45\_Wrapper\_C              | R45                               |
| 106002   | 1        | BP\_Pistol\_P1911\_Wrapper\_C            | P1911                             |
| 106010   | 1        | BP\_Pistol\_DesertEagle\_Wrapper\_C      | DesertEagle                       |
| 108003   | 1        | BP\_WEP\_Sickle\_Pickup\_C               | Sickle                            |
| 108001   | 1        | BP\_WEP\_Machete\_Pickup\_C              | Machete                           |
| 107001   | 1        | BP\_WEP\_Cowbar\_Pickup\_C               | Levye                             |
| 108004   | 1        | BP\_WEP\_Pan\_Pickup\_C                  | Pan                               |
| 103007   | 1        | BP\_WEP\_Mk14\_Pickup\_C                 | Mk14                              |
| 108004   | 7        | BP\_WEP\_Pan\_C                          | Pan\_C                            |
| 302001   | 1        | BP\_Ammo\_762mm\_Pickup\_C               | 7\.62                             |
| 305001   | 1        | BP\_Ammo\_45ACP\_Pickup\_C               | 45ACP                             |
| 303001   | 1        | BP\_Ammo\_556mm\_Pickup\_C               | 5\.56                             |
| 301001   | 1        | BP\_Ammo\_9mm\_Pickup\_C                 | 9mm                               |
| 306001   | 1        | BP\_Ammo\_300Magnum\_Pickup\_C           | 300Magnum                         |
| 304001   | 1        | BP\_Ammo\_12Guage\_Pickup\_C             | 12Guage                           |
| 307001   | 1        | BP\_Ammo\_Bolt\_Pickup\_C                | Arbalet Oku                       |
| 201004   | 1        | BP\_QK\_Mid\_FlashHider\_Pickup\_C       | Alev Gizl \(Haf\. Mak\.\.\)       |
| 201010   | 1        | BP\_QK\_Large\_FlashHider\_Pickup\_C     | Alev Gizl \(Oto\.\)               |
| 201009   | 1        | BP\_QK\_Large\_Compensator\_Pickup\_C    | Otomatik Kompensator              |
| 201004   | 1        | BP\_QK\_Mid\_Compensator\_Pickup\_C      | Kompensator \(Haf\.Mak\.\)        |
| 205002   | 1        | BP\_QT\_A\_Pickup\_C                     | Taktik Dipcik                     |
| 201012   | 1        | BP\_QK\_DuckBill\_Pickup\_C              | Duckbill \(Pompalı\)              |
| 201005   | 1        | BP\_QK\_Sniper\_FlashHider\_Pickup\_C    | Alev Gizl\. Sniper                |
| 201006   | 1        | BP\_QK\_Mid\_Suppressor\_Pickup\_C       | Susturucu \(Haf\. Mak\. Tabanca\) |
| 205003   | 1        | BP\_QT\_Sniper\_Pickup\_C                | Chekpad Sniper                    |
| 201001   | 1        | BP\_QK\_Choke\_Pickup\_C                 | Choke                             |
| 205001   | 1        | BP\_QT\_UZI\_Pickup\_C                   | Dipcik \(Micro UZI\)              |
| 201003   | 1        | BP\_QK\_Sniper\_Compensator\_Pickup\_C   | Sniper Kompensator                |
| 201007   | 1        | BP\_QK\_Sniper\_Suppressor\_Pickup\_C    | Susuturucu Sniper                 |
| 201011   | 1        | BP\_QK\_Large\_Suppressor\_Pickup\_C     | Susuturucu Oto\.                  |
| 204009   | 1        | BP\_DJ\_Sniper\_EQ\_Pickup\_C            | Hc\.Uz\.Snip\.Sarjor              |
| 204004   | 1        | BP\_DJ\_Mid\_E\_Pickup\_C                | Uz\.Haf\.Sarjor                   |
| 204005   | 1        | BP\_DJ\_Mid\_Q\_Pickup\_C                | Hc\.Haf\.Sarjor                   |
| 204007   | 1        | BP\_DJ\_Sniper\_E\_Pickup\_C             | Uz\.Snip\.Sarjor                  |
| 204008   | 1        | BP\_DJ\_Sniper\_Q\_Pickup\_C             | Hc\.Snip\.Sarjor                  |
| 204012   | 1        | BP\_DJ\_Large\_Q\_Pickup\_C              | Hc\.Oto\.Sarjor                   |
| 204013   | 1        | BP\_DJ\_Large\_EQ\_Pickup\_C             | Hc\.Uz\.Oto\.Sarjor               |
| 204011   | 1        | BP\_DJ\_Large\_E\_Pickup\_C              | Uz\.Oto\.Sarjor                   |
| 204006   | 1        | BP\_DJ\_Mid\_EQ\_Pickup\_C               | Hc\.Uz\.Haf\.Sarjor               |
| 205004   | 1        | BP\_ZDD\_Crossbow\_Q\_Pickup\_C          | Sadak \(Arbalet\)                 |
| 204014   | 1        | BP\_ZDD\_Sniper\_Pickup\_C               | Mermilik                          |
| 203005   | 1        | BP\_MZJ\_8X\_Pickup\_C                   | 8x                                |
| 203003   | 1        | BP\_MZJ\_2X\_Pickup\_C                   | 2x                                |
| 203001   | 1        | BP\_MZJ\_HD\_Pickup\_C                   | Lazer                             |
| 203014   | 1        | BP\_MZJ\_3X\_Pickup\_C                   | 3X                                |
| 203002   | 1        | BP\_MZJ\_QX\_Pickup\_C                   | Holo                              |
| 203015   | 1        | BP\_MZJ\_6X\_Pickup\_C                   | 6x                                |
| 203004   | 1        | BP\_MZJ\_4X\_Pickup\_C                   | 4x                                |
| 105002   | 1        | BP\_Other\_DP28\_Wrapper\_C              | DP28                              |
| 107001   | 1        | BP\_Other\_CrossBow\_Wrapper\_C          | Arbalet                           |
| 105001   | 1        | BP\_Other\_M249\_Wrapper\_C              | M249                              |
| 501006   | 1        | PickUp\_BP\_Bag\_Lv3\_C                  | Canta 3                           |
| 501006   | 1        | PickUp\_BP\_Bag\_Lv3\_B\_C               | Canta 3                           |
| 501004   | 1        | PickUp\_BP\_Bag\_Lv1\_C                  | Canta 1                           |
| 501004   | 1        | PickUp\_BP\_Bag\_Lv1\_B\_C               | Canta 1                           |
| 501005   | 1        | PickUp\_BP\_Bag\_Lv2\_C                  | Canta 2                           |
| 501005   | 1        | PickUp\_BP\_Bag\_Lv2\_B\_C               | Canta 2                           |
| 503002   | 1        | PickUp\_BP\_Armor\_Lv2\_C                | Yelek 2                           |
| 503002   | 1        | PickUp\_BP\_Armor\_Lv2\_B\_C             | Yelek 2                           |
| 503001   | 1        | PickUp\_BP\_Armor\_Lv1\_C                | Yelek 1                           |
| 503001   | 1        | PickUp\_BP\_Armor\_Lv1\_B\_C             | Yelek 1                           |
| 503003   | 1        | PickUp\_BP\_Armor\_Lv3\_C                | Yelek 3                           |
| 503003   | 1        | PickUp\_BP\_Armor\_Lv3\_B\_C             | Yelek 3                           |
| 502002   | 1        | PickUp\_BP\_Helmet\_Lv2\_C               | Kask 2                            |
| 502002   | 1        | PickUp\_BP\_Helmet\_Lv2\_B\_C            | Kask 2                            |
| 502001   | 1        | PickUp\_BP\_Helmet\_Lv1\_C               | Kask 1                            |
| 502001   | 1        | PickUp\_BP\_Helmet\_Lv1\_B\_C            | Kask 1                            |
| 502003   | 1        | PickUp\_BP\_Helmet\_Lv3\_C               | Kask 3                            |
| 502003   | 1        | PickUp\_BP\_Helmet\_Lv3\_B\_C            | Kask 3                            |
| 0        | 5        | BP\_VH\_Buggy\_2\_C                      | Buggy                             |
| 0        | 5        | BP\_VH\_Buggy\_3\_C                      | Buggy                             |
| 0        | 5        | BP\_VH\_Tuk\_1\_C                        | Tuk                               |
| 602004   | 1        | BP\_Grenade\_Shoulei\_Weapon\_Wrapper\_C | Grenade                           |
| 0        | 1        | BP\_Grenade\_Shoulei\_C                  | Bomb\!                            |
| 602002   | 1        | BP\_Grenade\_Smoke\_Weapon\_Wrapper\_C   | Smoke                             |
| 602003   | 1        | BP\_Grenade\_Burn\_Weapon\_Wrapper\_C    | Molotof                           |
| 0        | 1        | BP\_Grenade\_Burn\_C                     | Burn\!                            |
| 602002   | 0        | BP\_Grenade\_Smoke\_C                    | Smoke\!                           |
| 602005   | 1        | BP\_Grenade\_Apple\_Weapon\_Wrapper\_C   | Apple                             |
| 601003   | 1        | Pills\_Pickup\_C                         | Painkiller                        |
| 601002   | 1        | Injection\_Pickup\_C                     | Adrenaline Syringe                |
| 601001   | 1        | Drink\_Pickup\_C                         | Energy Drink                      |
| 601005   | 1        | Firstaid\_Pickup\_C                      | FirstaidKit                       |
| 601004   | 1        | Bandage\_Pickup\_C                       | Bandage                           |
| 0        | 8        | BP\_PlayerPawn\_C                        | BP\_PlayerPawn\_C                 |
| 0        | 8        | BP\_PlayerPawn\_ZNQ\_C                   | BP\_PlayerPawn\_ZNQ\_C            |
| 202006   | 1        | BP\_WB\_ThumbGrip\_Pickup\_C             | Basparmaklik                      |
| 202007   | 1        | BP\_WB\_Lasersight\_Pickup\_C            | Silah Lazeri                      |
| 202001   | 1        | BP\_WB\_Angled\_Pickup\_C                | Acili El Tutamagi                 |
| 202004   | 1        | BP\_WB\_LightGrip\_Pickup\_C             | Hafif Tutamak                     |
| 0        | 1        | BP\_WB\_HalfGrip\_Pickup\_C              | Yarım Tutamak                     |
| 202002   | 1        | BP\_WB\_Vertical\_Pickup\_C              | DikeyTutamac                      |
| 0        | 5        | VH\_Motorcycle\_C                        | Motor                             |
| 0        | 5        | VH\_Motorcycle\_1\_C                     | Motor                             |
| 0        | 5        | Mirado\_open\_4\_C                       | Mirado Open                       |
| 0        | 5        | VH\_Dacia\_C                             | Toros                             |
| 0        | 5        | VH\_Dacia\_1\_C                          | Toros                             |
| 0        | 5        | VH\_Dacia\_4\_C                          | Toros                             |
| 0        | 5        | Rony\_01\_C                              | Rony                              |
| 0        | 5        | VH\_Snowmobile\_C                        | Snowmobile                        |
| 0        | 5        | Mirado\_close\_3\_C                      | Mirado Blue                       |
| 0        | 5        | LadaNiva\_01\_C                          | Lada Niva                         |
| 0        | 5        | VH\_Scooter\_C                           | Scooter                           |
| 0        | 5        | VH\_BRDM\_C                              | Tank                              |
| 0        | 5        | PickUp\_02\_C                            | PickUp                            |
| 0        | 5        | VH\_MiniBus\_01\_C                       | MiniBus                           |
| 0        | 5        | VH\_MotorcycleCart\_C                    | Motor 3Teker                      |
| 0        | 5        | VH\_MotorcycleCart\_1\_C                 | Motor 3Teker                      |
| 0        | 5        | VH\_Snowbike\_C                          | Snowbike                          |
| 0        | 5        | VH\_PG117\_C                             | Boat                              |
| 0        | 5        | VH\_UAZ01\_C                             | UAZ1                              |
| 0        | 5        | VH\_UAZ02\_C                             | UAZ2                              |
| 0        | 5        | VH\_UAZ03\_C                             | UAZ2                              |
| 0        | 5        | VH\_UAZ04\_C                             | UAZ2                              |
| 0        | 2        | AquaRail\_1\_C                           | JetSki                            |
| 106007   | 1        | BP\_Pistol\_Flaregun\_Wrapper\_C         | Flaregun                          |
| 0        | 1        | BP\_AirDropBox\_C                        | AirDrop                           |
| 0        | 1        | BP\_AirDropPlane\_C                      | Plane                             |
| 0        | 1        | PlayerDeadInventoryBox\_C                | Player Box                        |
| 603001   | 1        | GasCan\_Destructible\_Pickup\_C          | Benzin                            |
| 0        | 2        | PickUpListWrapperActor                   | Create Box                        |
| 0        | 5        | VH\_Dacia\_2\_C                          | Toros                             |
| 0        | 5        | VH\_Dacia\_3\_C                          | Toros                             |
| 3000312  | 1        | BP\_GameCoin\_Pickup\_C                  | GameCoin                          |
| 0        | 1        | BP\_BlindBoxMachine\_C                   | BlindBoxMachine                   |
| 0        | 1        | BP\_MiniGameMachine\_C                   | MiniGameMachine                   |
| 0        | 1        | BP\_Grenade\_ColorBall\_C                | ColorBall                         |
| 0        | 2        | AirDropListWrapperActor                  | AirDrop                           |
| 601006   | 1        | FirstAidbox\_Pickup\_C                   | Medkit                            |
| 308001   | 1        | BP\_Ammo\_Flare\_Pickup\_C               | Flaregun                          |
| 501003   | 1        | PickUp\_BP\_Bag\_Lv3\_Inbox\_C           | Canta 3                           |
| 501002   | 1        | PickUp\_BP\_Bag\_Lv2\_Inbox\_C           | Canta 2                           |
| 501001   | 1        | PickUp\_BP\_Bag\_Lv1\_Inbox\_C           | Canta 1                           |
| 201002   | 1        | BP\_QK\_Mid\_Compensator\_Inbox\_C       | Kompensator \(Haf\.Mak\.\)        |
| 502005   | 1        | PickUp\_BP\_Helmet\_Lv2\_Inbox\_C        | Kask 2                            |
| 403989   | 1        | PickUp\_BP\_Ghillie\_4\_C                | Suit \- Arctic                    |
| 403045   | 1        | PickUp\_BP\_Ghillie\_1\_C                | Suit \- Woodland                  |
| 403187   | 1        | PickUp\_BP\_Ghillie\_2\_C                | Suit \- Desert                    |
| 403188   | 1        | PickUp\_BP\_Ghillie\_3\_C                | Suit \- Desert                    |
---

#### If you like this document, you can give a star. Thank you
**Amiral Router!**
