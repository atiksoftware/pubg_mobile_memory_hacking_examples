#include "includes.h" 


DWORD controllerOffset = 96;
DWORD posOffset = 336;
DWORD healthOffset = 1912;
DWORD nameOffset = 1512;
DWORD teamIDOffset = 1552;
DWORD statusOffset = 868;
DWORD poseOffset = 288;



Esp* g_pEsp = new Esp();

Esp::Esp(){}


Esp::~Esp(){}

template <class T> T Esp::readFromMemory(PVOID BaseAddress, PSIZE_T NumberOfBytesRead){
	T response = {}; 
	pMM->bypass->RWVM(pMM->bypass->m_hTarget, BaseAddress, &response, sizeof(T), NumberOfBytesRead, true, true);
	return response;
}

template <class T> T Esp::get(DWORD address){
	return readFromMemory<T>((PVOID)address);
}






DWORD Esp::GetViewWorld(){
	BYTE  pattern[] = { 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x01 };
	std::vector<DWORD_PTR> tmpViewWorlds;
	pMM->MemSearch(pattern, sizeof(pattern), 0x26000000, 0x30000000, FALSE, 0, tmpViewWorlds);
	int tmpViewWorldsCount = tmpViewWorlds.size();
	DWORD *viewWorlds = new DWORD[tmpViewWorldsCount];
	for(int i = 0; i < tmpViewWorlds.size(); i++){
		viewWorlds[i] = tmpViewWorlds[i] - 32;
		DWORD cand = (tmpViewWorlds[i] - 32);
		PSIZE_T bytesRead;
		DWORD tmp;
		float t1, t2, t3, t4;
		DWORD rr = get<DWORD>( cand) + 32;
		tmp = get<DWORD>( rr) + 512;
		t1 = get<float>( tmp + 56);
		t2 = get<float>( tmp + 40);
		t3 = get<float>( tmp + 24);
		t4 = get<float>( tmp + 8);
		if(t1 >= 3 && t2 == 0 && t3 == 0 && t4 == 0){
			return cand;
		}
		std::cout << std::endl << termcolor::blue << "Founded View_Worlds : " << termcolor::reset << viewWorlds[i] << std::endl;
	}
	return 0;
}
std::string Esp::getEntityClassName(DWORD gNames, DWORD id){
	gname = get<DWORD>( gNames);
	if(id > 0 && id < 2000000){
		page = id / 16384;
		index = id % 16384;
		secPartAddv = get<DWORD>( gname + page * 4);
		if(secPartAddv > 0){
			nameAddv = get<DWORD>(secPartAddv + index * 4);
			if(nameAddv > 0){
				char * buff = new char[128]; 
				try{
					const size_t namesize = 64;
					char x[namesize]; 
					pMM->bypass->RWVM(pMM->bypass->m_hTarget, (PVOID)(nameAddv + 8), &x, namesize, nullptr, true, true);

					std::wstring tmpname = std::wstring(&x[0], &x[namesize]);
					wchar_t* czech = wcstok(&tmpname[0], L"\0");
					std::wstring ws(czech); 
					std::string str(ws.begin(), ws.end());
					delete[] buff;
					if(czech != nullptr) return str;
				} catch(const std::exception &exc){
					delete[] buff;
				}
				delete[] buff;
				return ""; 
				//pMM->bypass->RWVM(pMM->bypass->m_hTarget, BaseAddress, &response, sizeof(T), NumberOfBytesRead, true, true);
				// return pMM->bypass->getString((nameAddv + 8), 32);  
			}
			return "";
		}
		return "";
	}
	return "";
}
void Esp::getViewMatrix(){ 
	DWORD viewMatrixAddr = get<DWORD>( get<DWORD>( ViewMatrixBase) + 32) + 512 ; 
	viewMatrix = get<D3DMatrix>(viewMatrixAddr);
}

std::string  Esp::getPlayerName(DWORD entityAddv){
	BYTE playerNameBuffer[34];
	SIZE_T dwNumberOfBytesRead = 0;
	pMM->bypass->RWVM(pMM->bypass->m_hTarget, (PVOID)get<DWORD>(entityAddv + nameOffset), &playerNameBuffer, 32, nullptr, true, true);
	bool ended = false;
	int count = 0;
	for(int y = 0; y < 32; y++){
		if(y > 0){
			if(y % 2 == 1){
				if(playerNameBuffer[y + 1] == 0x00){
					break;
				}
			}
		}
		count++; 
	}
	BYTE* stringerChars = new BYTE[count];
	 
	int l = 0;
	for(int i = 0; i < count; i++){
		int x = static_cast<unsigned int>(playerNameBuffer[i]);
		if(x >= 33 && x <= 126){
			stringerChars[l] = playerNameBuffer[i];
			l++;
		}
	}
	count = l;
	 
	std::string s2;
	try{
		s2.append(reinterpret_cast<const char *>(stringerChars), count);
	} catch(const std::exception&){ }

	delete[] stringerChars; 
	return s2; 
}
 

void Esp::scanEntityList(){
	uWorlds = get<DWORD>( uWorld);
	uLevel = get<DWORD>(uWorlds + 32);
	gameInstance = get<DWORD>(uWorlds + 36);
	playerController = get<DWORD>(gameInstance + controllerOffset);
	playerCarry = get<DWORD>(playerController + 32);
	uMyObject = get<DWORD>(playerCarry + 788);
	ViewMatrixBase = viewWorld;
	entityEntry = get<DWORD>(uLevel + 112);
	entityCount = get<DWORD>(uLevel + 116);
	if(entityCount < 0){
		entityCount = 0;
	}
	if(entityCount > 1024){
		entityCount = 1024;
	}
	enemyCount = 0;
	for(int i = 0; i < entityCount; i++){
 
		entityAddv = get<DWORD>(entityEntry + i * 4);
		entityStruct = get<DWORD>(entityAddv + 16);

 
		if(Entities[i].entityAddv != entityAddv){
			std::string entityClassName = getEntityClassName(gNames, entityStruct);
			Entities[i].setClassName(entityClassName); 
 
			Entities[i].itemId = get<int>(get<DWORD>(get<DWORD>(entityAddv + 0xC) + 0xA8) + 0x2F4);
			
			if(Entities[i].itemType == 0){ 
				std::cout << termcolor::green << entityClassName << " " << termcolor::red << entityAddv << " " << termcolor::yellow << Entities[i].itemId << termcolor::reset << "\n";
			}
	 

			//std::string entityClassName = GetEntityClassName(gNames, entityStruct);
		}
	 
		// VEHICLE
		if(Entities[i].isVehicle){
			 
		 
		}
		 
		// BOX
		if(Entities[i].isBox ){
			Entities[i].isBox = true;
			int boxItemCount;
			boxItemCount = get<int>(entityAddv + 1088);
	 
			if(boxItemCount < 60){
				DWORD itemEntry = get<DWORD>( entityAddv + 1084);
				//std::cout << std::hex << itemEntry << "\n";
				if(itemEntry > 50000){
					long itemAddv, itemID, itemCount;
					Entities[i].BoxItemLength = 0;
					for(int h = 0; h < boxItemCount; h++){
						itemAddv = itemEntry + h * 48;
						itemID = get<int>( itemAddv + 52);
						itemID = get<int>( itemAddv + 0x4);
						if(itemID > 0){
							itemCount = get<int>(itemAddv + 72);
							itemCount = get<int>(itemAddv + 0x18); 
							if(itemCount > 0){ 
								Entities[i].addBoxItem(itemID, itemCount);   
							} 
						}
					}
				}
			}
		}
		 
		// PLAYER
		if(Entities[i].isPlayer){
			if(Entities[i].entityAddv != entityAddv){
				Entities[i].playerWorld = get<DWORD>(entityAddv + 312); 
				// Entities[i].setPlayerName(Entities[i].isRobot ? "_bot_" : pname); 
			}

			DWORD ws = get<DWORD>(entityAddv + 300);
			DWORD ws_1 = get<DWORD>(ws);
			DWORD ws_2 = get<DWORD>(ws + 4);
			int ws_1_id = get<int>(ws_1 + 728);
			int ws_2_id = get<int>(ws_2 + 728);
			int w1_ammo_cur = get<int>(get<DWORD>(ws_1 + 0x54) + 0x7D0);
			int w1_ammo_max = get<int>(get<DWORD>(ws_1 + 0x54) + 0x7D4);
			 
			 




			if(Entities[i].entityAddv != entityAddv){
				std::string playerName = getPlayerName(entityAddv);
				Entities[i].setMainString(playerName);
			}
			Entities[i].playerStatus = get<int>( Entities[i].playerWorld + statusOffset);
			if(Entities[i].playerStatus != 6){ 
				// PlayerTeam
				Entities[i].setPlayerTeamId(get<int>( entityAddv + teamIDOffset));
				if(entityAddv == uMyObject){
					myTeamID = Entities[i].playerTeamId;
				}
				if(myTeamID != Entities[i].playerTeamId){
					enemyCount++;
				}
				// Is a Bot
				Entities[i].isRobot = get<int>( entityAddv + 692) == 0 ? true : false;
				Entities[i].playerPose = get<int>( Entities[i].playerWorld + poseOffset); 
				// Player Bone
				DWORD tmpAddv = get<DWORD>( entityAddv + 776);
				Entities[i].bodyAddv = tmpAddv + 320;
				Entities[i].boneAddv = get<DWORD>( tmpAddv + 1408) + 48;
				// Weapons
				DWORD weaponsPtr = get<DWORD>(entityAddv + 300);
				DWORD wptr_1 = get<DWORD>(weaponsPtr);
				DWORD wptr_2 = get<DWORD>(weaponsPtr + 4);
				int wid_1 = get<int>(wptr_1 + 728);
				int wid_2 = get<int>(wptr_2 + 728);
				int w1_ammo_cur = get<int>(get<DWORD>(wptr_1 + 0x54) + 0x7D0);
				int w1_ammo_max = get<int>(get<DWORD>(wptr_1 + 0x54) + 0x7D4);
				int w2_ammo_cur = get<int>(get<DWORD>(wptr_2 + 0x54) + 0x7D0);
				int w2_ammo_max = get<int>(get<DWORD>(wptr_2 + 0x54) + 0x7D4);
				Entities[i].setPlayerWeapon(0, wid_1, w1_ammo_cur, w1_ammo_max);
				Entities[i].setPlayerWeapon(1, wid_2, w2_ammo_cur, w2_ammo_max);
			} 
		}
	

		Entities[i].entityAddv = entityAddv;
	}

	std::string textEnemyCountString = "Enemy: ";
	textEnemyCountString += std::to_string(enemyCount);
	textEnemyCount.setString(textEnemyCountString);
	 
}


void Esp::scanEntityPositions(){
	bestCloseEnemyDistance = 500;
	for(int i = 0; i < entityCount; i++){ 
		DWORD azxs = get<DWORD>(Entities[i].entityAddv + 312);
		Entities[i].position = get<Vector3>( azxs + posOffset); 
		if(Entities[i].isVehicle){
			DWORD vehicleDynamics = get<DWORD>(get<DWORD>(Entities[i].entityAddv + 0x54) + 0x4D8);
			Entities[i].setMaxHealth(get<float>(vehicleDynamics + 0x108));
			Entities[i].setCurHealth(get<float>(vehicleDynamics + 0x10C));
			Entities[i].setMaxGallon(get<float>(vehicleDynamics + 0x108 + 0x18));
			Entities[i].setCurGallon(get<float>(vehicleDynamics + 0x10C + 0x18));
		}
		if(Entities[i].isPlayer){ 
			float playerHp = get<int>(entityAddv + healthOffset);
			float playerHp2 = get<int>(entityAddv + healthOffset + 4);
			Entities[i].setMaxHealth(playerHp);
			Entities[i].setCurHealth(playerHp2);
		}
	}
}










void Esp::drawEntityList(){
	getViewMatrix();
 
	for(int i = 0; i < entityCount; i++){
		if(Entities[i].isObj && debugMod){
			Entities[i].drawObj();
		}
		if(Entities[i].isLoot){
			Entities[i].drawLoot();
		}
		if(Entities[i].isBox){
			Entities[i].drawBox();
		}
		if(Entities[i].isVehicle){
			Entities[i].drawVehicle();
		}
		if(Entities[i].isPlayer){
			if(myTeamID != Entities[i].playerTeamId){
				Entities[i].drawPlayer();
			}
		}
	}

	g_pOverlay->window.draw(textEnemyCount);


}





bool Esp::WorldToScreen(  Vector3 pos, Vector3 &screen, int* distance ){
	float screenW = (viewMatrix._14 * pos.x) + (viewMatrix._24 * pos.y) + (viewMatrix._34 * pos.z + viewMatrix._44);
	screen.z = screenW;
	*distance = (screenW / 100);
	if(screenW < 0.0001f) return false;
	screenW = 1 / screenW;
	float sightX = (g_pOverlay->screen_width / 2);
	float sightY = (g_pOverlay->screen_height / 2);
	screen.x = sightX + (viewMatrix._11 * pos.x + viewMatrix._21 * pos.y + viewMatrix._31 * pos.z + viewMatrix._41) * screenW * sightX;
	screen.y = sightY - (viewMatrix._12 * pos.x + viewMatrix._22 * pos.y + viewMatrix._32 * pos.z + viewMatrix._42) * screenW * sightY;
	return true;
}
bool Esp::WorldToScreen(Vector3 pos, Vector2 &screen, int* distance){
	float screenW = (viewMatrix._14 * pos.x) + (viewMatrix._24 * pos.y) + (viewMatrix._34 * pos.z + viewMatrix._44);
	*distance = (screenW / 100);
	if(screenW < 0.0001f) return false;
	screenW = 1 / screenW;
	float sightX = (g_pOverlay->screen_width / 2);
	float sightY = (g_pOverlay->screen_height / 2);
	screen.x = sightX + (viewMatrix._11 * pos.x + viewMatrix._21 * pos.y + viewMatrix._31 * pos.z + viewMatrix._41) * screenW * sightX;
	screen.y = sightY - (viewMatrix._12 * pos.x + viewMatrix._22 * pos.y + viewMatrix._32 * pos.z + viewMatrix._42) * screenW * sightY;
	return true;
}

bool Esp::WorldToScreenPlayer(Vector3 pos, Vector3 &screen, int* distance){
	float screenW = (viewMatrix._14 * pos.x) + (viewMatrix._24 * pos.y) + (viewMatrix._34 * pos.z + viewMatrix._44);
	*distance = (screenW / 100);
	if(screenW < 0.0001f) return false;
	float screenY = (viewMatrix._12 * pos.x) + (viewMatrix._22 * pos.y) + (viewMatrix._32 * (pos.z + 85) + viewMatrix._42);
	float screenX = (viewMatrix._11 * pos.x) + (viewMatrix._21 * pos.y) + (viewMatrix._31 * pos.z + viewMatrix._41);
	screen.y = (g_pOverlay->screen_height / 2) - (g_pOverlay->screen_height / 2) * screenY / screenW;
	screen.x = (g_pOverlay->screen_width / 2) + (g_pOverlay->screen_width / 2) * screenX / screenW;
	float y1 = (g_pOverlay->screen_height / 2) - (viewMatrix._12 * pos.x + viewMatrix._22 * pos.y + viewMatrix._32 * (pos.z - 95) + viewMatrix._42) * (g_pOverlay->screen_height / 2) / screenW;
	screen.z = y1 - screen.y;
	return true;
}
FTTransform2_t Esp::ReadFTransform2(DWORD vAddv){
	return pMM->bypass->qRVM<FTTransform2_t>((PVOID)(vAddv));
}
Vector3 Esp::GetBoneWorldPosition(DWORD actorAddv, DWORD boneAddv){
	FTTransform2_t bone = ReadFTransform2(boneAddv);
	FTTransform2_t actor = ReadFTransform2(actorAddv);
	D3DMatrix boneMatrix = ToMatrixWithScale(bone.Translation, bone.Scale3D, bone.Rotation);
	D3DMatrix componentToWorldMatrix = ToMatrixWithScale(actor.Translation, actor.Scale3D, actor.Rotation);
	D3DMatrix newMatrix = MatrixMultiplication(boneMatrix, componentToWorldMatrix);
	Vector3 bonePos;
	bonePos.x = newMatrix._41;
	bonePos.y = newMatrix._42;
	bonePos.z = newMatrix._43;
	return bonePos;
}
D3DMatrix Esp::ToMatrixWithScale(Vector3 translation, Vector3 scale, Vector4 rot){
	D3DMatrix m;
	m._41 = translation.x;
	m._42 = translation.y;
	m._43 = translation.z;

	float x2 = rot.x + rot.x;
	float y2 = rot.y + rot.y;
	float z2 = rot.z + rot.z;

	float xx2 = rot.x * x2;
	float yy2 = rot.y * y2;
	float zz2 = rot.z * z2;
	m._11 = (1.0f - (yy2 + zz2)) * scale.x;
	m._22 = (1.0f - (xx2 + zz2)) * scale.y;
	m._33 = (1.0f - (xx2 + yy2)) * scale.z;

	float yz2 = rot.y * z2;
	float wx2 = rot.w * x2;
	m._32 = (yz2 - wx2) * scale.z;
	m._23 = (yz2 + wx2) * scale.y;

	float xy2 = rot.x * y2;
	float wz2 = rot.w * z2;
	m._21 = (xy2 - wz2) * scale.y;
	m._12 = (xy2 + wz2) * scale.x;

	float xz2 = rot.x * z2;
	float wy2 = rot.w * y2;
	m._31 = (xz2 + wy2) * scale.z;
	m._13 = (xz2 - wy2) * scale.x;

	m._14 = 0.0f;
	m._24 = 0.0f;
	m._34 = 0.0f;
	m._44 = 1.0f;

	return m;
}
D3DMatrix Esp::MatrixMultiplication(D3DMatrix pM1, D3DMatrix pM2){
	D3DMatrix pOut = {
		pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41,
		pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42,
		pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43,
		pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44,
		pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41,
		pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42,
		pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43,
		pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44,
		pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41,
		pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42,
		pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43,
		pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44,
		pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41,
		pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42,
		pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43,
		pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44
	};

	return pOut;
}


















void Esp::Init(){
	dwGamePid = ProcManager::GetAowProcId();

	//bypass = new BypaPH(dwGamePid);
	pMM->setGamePid(dwGamePid);



	viewWorld = GetViewWorld();
	uWorld = viewWorld - 4217216;
	gNames = viewWorld - 1638204;

	for(int i = 0; i < MAX_ENTITY; i++){
		Entities[i] = Entity();
		Entities[i].index = i;
	}

	textEnemyCount.setCharacterSize(24);
	textEnemyCount.setColor(sf::Color::Color(242, 0, 46, 255)); 
	textEnemyCount.setFont(g_pEntityClasses->Fonts[2]);
	textEnemyCount.setPosition(320, 150);
	textEnemyCount.setOutlineColor(sf::Color::Color(0, 0, 0, 150));
	textEnemyCount.setOutlineThickness(2);

	sf::SoundBuffer bufferEnemyCount; 
	soundEnemyCount.openFromFile(g_pEntityClasses->filePath("/assets/audio/enemycount.wav"));
	soundEnemyCount.setVolume(40);  
	soundEnemyCount.play();  
	 
 
 
}