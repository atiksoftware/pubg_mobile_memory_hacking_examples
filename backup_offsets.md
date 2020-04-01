```C#
internal const int PlayerState = 0x420;
internal const int KillsNum = 0x860;
```

---  

```C++
uint32_t ChunkSize = 0x4108;
uint32_t UWorldOffset = 0x7847818;
uint32_t GNamesOffset = 0x76c6608; 
uint32_t ActorsArrayOffset = 0x1D8;
uint32_t LocalsArrayOffset = 0x48;
uint32_t ULevelOffset = 0x230;
uint32_t GameInstanceOffset = 0x290; 
uint32_t RootComponentOffset = 0x1C8;
uint32_t PlayerControllerOffset = 0x30;
uint32_t DroppedItem_Item = 0x3F0;
uint32_t DroppedItemGroupArrayOffset = 0x230;
uint32_t ComponentToWorldOffset = 0x300;
uint32_t AbsoluteLocationOffset = 0x310;
uint32_t PlayerController_PlayerCameraManager = 0x498;
uint32_t PlayerCameraManager_CameraCache_POV = ( 0x470 + 0x10 );
uint32_t CameraLocationOffset = ( PlayerCameraManager_CameraCache_POV + 0x5b0 );
uint32_t CameraFovOffset = ( PlayerCameraManager_CameraCache_POV + 0xc );
uint32_t CameraRotationOffset = ( PlayerCameraManager_CameraCache_POV + 0x5a0 );
```

--- 

```C++
#define OFFSET_DECRYPT_TABLE 0x5724228
 
#define OFFSET_UWORLD 0x7847818
 
#define OFFSET_GNAMES 0x76C6628 - 0x20
#define OFFSET_CHUNKSIZE 0x4108
 
#define OFFSET_CACHED_LOCALPLAYER 0x7827410 
 
#define OFFSET_PERSISTENT_LEVEL 0x230
#define OFFSET_ACTORS_ARRAY 0x1D8
 
#define OFFSET_LOCALPLAYER_CONTROLER 0x30
#define OFFSET_CONTROLER_ROTATION 0x410
#define OFFSET_CONTROLER_ACKPAWN 0x400
 
#define OFFSET_LOCALPLAYER_CAMERA 0x498 
#define OFFSET_CAMERA_FOV 0x48C
#define OFFSET_CAMERA_LOCATION 0xA30
#define OFFSET_CAMERA_ROTATION 0xA20
 
#define OFFSET_ACTOR_ID 0x1C 
#define OFFSET_PLAYER_HEALTH 0x1678 
#define OFFSET_PLAYER_GROGGYHEALTH 0x15A8
#define OFFSET_ACTOR_ROOTCOMPONENT 0x1C8
#define OFFSET_ROOTCOMPONENT_LOCATION 0x310 
#define OFFSET_ACTOR_MESHCOMPONENT 0x518
#define OFFSET_MESHCOMPONENT_STATICMESH 0xAC0
#define OFFSET_MESHCOMPONENT_COMPONENT2WORLD 0x300
 
#define OFFSET_MESHCOMPONENT_LASTSUBMITTIME 0x760
#define OFFSET_MESHCOMPONENT_LASTRENDERTIMEONSCREEN 0x768
 
#define OFFSET_MESHCOMPONENT_UANIMINSTANCE 0xC68
#define OFFSET_UANIMINSTANCE_CONTROL_ROTATION_CP 0x6A0
#define OFFSET_UANIMINSTANCE_RECOILADS_ROTATION 0xB48
 
#define OFFSET_LOCALPLAYER_WEAPONPROCESSOR 0x1598
#define OFFSET_WEAPONPROCESSER_EQUIPPEDWEAPONS 0x2A8
#define OFFSET_WEAPONPROCESSER_WEAPONINDEX (OFFSET_WEAPONPROCESSER_EQUIPPEDWEAPONS + 0x21)
#define OFFSET_WEAPON_TRAJECTORYDATA 0xEC0
#define OFFSET_TRAJECTORYDATA_CONFIG 0xB0 
 
#define OFFSET_TRAJECTORYCONFIG_VELOCITY (OFFSET_TRAJECTORYDATA_CONFIG + 0x0)
#define OFFSET_TRAJECTORYCONFIG_VDRAG_COEFICIENT (OFFSET_TRAJECTORYDATA_CONFIG + 0x2C)
```

--- 

```C++
struct FRepMovement                                ReplicatedMovement;                                       // 0x0078(0x0034) (Edit, Net, DisableEditOnInstance, RepNotify, NoDestructor, AdvancedDisplay, NativeAccessSpecifierPublic) 	
 
//ScriptStruct Engine.RepMovement
//0x0034 
struct FRepMovement 
{
	struct FVector                                     LinearVelocity;                                           // 0x0000(0x000C) (Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	struct FVector                                     AngularVelocity;                                          // 0x000C(0x000C) (Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	struct FVector                                     Location;                                                 // 0x0018(0x000C) (Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	struct FRotator                                    Rotation;                                                 // 0x0024(0x000C) (Transient, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic) 	
	unsigned char                                      bSimulatedPhysicSleep : 1;                                // 0x0030(0x0001) (Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bRepPhysics : 1;                                          // 0x0030(0x0001) (Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	FEVectorQuantization                               LocationQuantizationLevel;                                // 0x0031(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	FEVectorQuantization                               VelocityQuantizationLevel;                                // 0x0032(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	FERotatorQuantization                              RotationQuantizationLevel;                                // 0x0033(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
};
 
//Class Engine.Actor
//0x03C8 (0x03F8 - 0x0030)
class AActor : public UObject
{
	struct FScriptMulticastDelegate                    OnActorHit;                                               // 0x0030(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData00[0x10];                                      // 0x0040(0x0010)	
	class UInputComponent*                             InputComponent;                                           // 0x0050(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bActorEnableCollision : 1;                                // 0x0058(0x0001) (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate) 	
	unsigned char                                      bReplayRewindable : 1;                                    // 0x0059(0x0001) (NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected) 	
	unsigned char                                      bReplicates : 1;                                          // 0x0059(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected) 	
	unsigned char                                      UnknownData01[0x6];                                       // 0x005A(0x0006)	
	struct FName                                       NetDriverName;                                            // 0x0060(0x0008) (ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected) 	
	TEnumAsByte<FENetRole>                             RemoteRole;                                               // 0x0068(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate) 	
	unsigned char                                      UnknownData02[0x7];                                       // 0x0069(0x0007)	
	class AActor*                                      Owner;                                                    // 0x0070(0x0008)	 (EncryptedObjectProperty) (Net, RepNotify, NoDestructor, UObjectWrapper, NativeAccessSpecifierPrivate) 
	struct FRepMovement                                ReplicatedMovement;                                       // 0x0078(0x0034) (Edit, Net, DisableEditOnInstance, RepNotify, NoDestructor, AdvancedDisplay, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData03[0x4];                                       // 0x00AC(0x0004)	
	struct FRepAttachment                              AttachmentReplication;                                    // 0x00B0(0x0040) (Net, Transient, RepNotify, NoDestructor, ContainsInstancedReference, NativeAccessSpecifierPrivate) 	
	struct FScriptMulticastDelegate                    OnInputTouchBegin;                                        // 0x00F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData04[0x50];                                      // 0x0100(0x0050)	
	float                                              ForceReplicateInterleavingFreq;                           // 0x0150(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData05[0x64];                                      // 0x0154(0x0064)	
	unsigned char                                      bAutoDestroyWhenFinished : 1;                             // 0x01B8(0x0001) (BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bCanBeDamaged : 1;                                        // 0x01B8(0x0001) (Edit, BlueprintVisible, Net, SaveGame, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bActorIsBeingDestroyed : 1;                               // 0x01B8(0x0001) (Transient, DuplicateTransient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate) 	
	unsigned char                                      bCollideWhenPlacing : 1;                                  // 0x01B8(0x0001) (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bFindCameraComponentWhenViewTarget : 1;                   // 0x01B8(0x0001) (Edit, BlueprintVisible, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bRelevantForNetworkReplays : 1;                           // 0x01B8(0x0001) (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bGenerateOverlapEventsDuringLevelStreaming : 1;           // 0x01B8(0x0001) (Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bIgnoreDestroyActorFromBlueprint : 1;                     // 0x01B8(0x0001) (Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bCanBeInCluster : 1;                                      // 0x01B9(0x0001) (Edit, NoDestructor, AdvancedDisplay, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected) 	
	FESpawnActorCollisionHandlingMethod                SpawnCollisionHandlingMethod;                             // 0x01BA(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bHidden : 1;                                              // 0x01BB(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, Net, Interp, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bNetTemporary : 1;                                        // 0x01BB(0x0001) (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bNetStartup : 1;                                          // 0x01BB(0x0001) (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bOnlyRelevantToOwner : 1;                                 // 0x01BB(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bAlwaysRelevant : 1;                                      // 0x01BB(0x0001) (Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bReplicateMovement : 1;                                   // 0x01BB(0x0001) (Edit, Net, DisableEditOnInstance, RepNotify, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bIsSetSpectatedDelay : 1;                                 // 0x01BB(0x0001) (Net, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bTearOff : 1;                                             // 0x01BB(0x0001) (Net, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bExchangedRoles : 1;                                      // 0x01BC(0x0001) (Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bNetLoadOnClient : 1;                                     // 0x01BC(0x0001) (Edit, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bNetUseOwnerRelevancy : 1;                                // 0x01BC(0x0001) (Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bBlockInput : 1;                                          // 0x01BC(0x0001) (Edit, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bAllowTickBeforeBeginPlay : 1;                            // 0x01BC(0x0001) (Edit, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData06[0x3];                                       // 0x01BD(0x0003)	
	struct FScriptMulticastDelegate                    OnInputTouchLeave;                                        // 0x01C0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	struct FScriptMulticastDelegate                    OnEndCursorOver;                                          // 0x01D0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	struct FScriptMulticastDelegate                    OnActorBeginOverlap;                                      // 0x01E0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	unsigned char                                      bAllowReceiveTickEventOnDedicatedServer : 1;              // 0x01F0(0x0001) (NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected) 	
	unsigned char                                      bActorSeamlessTraveled : 1;                               // 0x01F0(0x0001) (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bIgnoresOriginShifting : 1;                               // 0x01F0(0x0001) (Edit, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bEnableAutoLODGeneration : 1;                             // 0x01F0(0x0001) (Edit, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData07[0x7];                                       // 0x01F1(0x0007)	
	TArray<class AActor*>                              Children;                                                 // 0x01F8(0x0010) (ZeroConstructor, Transient, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData08[0x8];                                       // 0x0208(0x0008)	
	float                                              CustomTimeDilation;                                       // 0x0210(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData09[0xC];                                       // 0x0214(0x000C)	
	float                                              InitialLifeSpan;                                          // 0x0220(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected) 	
	unsigned char                                      UnknownData0A[0x4];                                       // 0x0224(0x0004)	
	struct FScriptMulticastDelegate                    OnActorEndOverlap;                                        // 0x0228(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	uint64_t                                           HiddenEditorViews;                                        // 0x0238(0x0008) (ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	class USceneComponent*                             RootComponent;                                            // 0x0240(0x0008)	 (EncryptedObjectProperty) (ExportObject, InstancedReference, NoDestructor, Protected, UObjectWrapper, NativeAccessSpecifierProtected) 
	struct FScriptMulticastDelegate                    OnInputTouchEnd;                                          // 0x0248(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	float                                              NetPriority;                                              // 0x0258(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	int                                                InputPriority;                                            // 0x025C(0x0004) (Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	struct FGuid                                       DestructibleId;                                           // 0x0260(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      bIsDestroyedVersion : 1;                                  // 0x0270(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      RemoveFromLevelLOD : 1;                                   // 0x0271(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData0B[0x6];                                       // 0x0272(0x0006)	
	struct FActorTickFunction                          PrimaryActorTick;                                         // 0x0278(0x0058) (Edit, DisableEditOnInstance, NativeAccessSpecifierPublic) 	
	struct FScriptMulticastDelegate                    OnReleased;                                               // 0x02D0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	float                                              NetCullDistanceSquared;                                   // 0x02E0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData0C[0x4];                                       // 0x02E4(0x0004)	
	struct FScriptMulticastDelegate                    OnTakeAnyDamage;                                          // 0x02E8(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData0D[0x4];                                       // 0x02F8(0x0004)	
	TEnumAsByte<FENetRole>                             Role;                                                     // 0x02FC(0x0001) (Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData0E[0x3];                                       // 0x02FD(0x0003)	
	struct FScriptMulticastDelegate                    OnClicked;                                                // 0x0300(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	TArray<struct FName>                               Layers;                                                   // 0x0310(0x0010) (ZeroConstructor, NativeAccessSpecifierPublic) 	
	float                                              NetUpdateFrequency;                                       // 0x0320(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData0F[0x4];                                       // 0x0324(0x0004)	
	TArray<struct FName>                               Tags;                                                     // 0x0328(0x0010) (Edit, BlueprintVisible, ZeroConstructor, AdvancedDisplay, NativeAccessSpecifierPublic) 	
	TArray<class UActorComponent*>                     InstanceComponents;                                       // 0x0338(0x0010) (ExportObject, ZeroConstructor, ContainsInstancedReference, NativeAccessSpecifierPrivate) 	
	struct FScriptMulticastDelegate                    OnInputTouchEnter;                                        // 0x0348(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	TArray<class AMatineeActor*>                       ControllingMatineeActors;                                 // 0x0358(0x0010) (ZeroConstructor, Transient, Protected, NativeAccessSpecifierProtected) 	
	class APawn*                                       Instigator;                                               // 0x0368(0x0008) (BlueprintVisible, Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData10[0x8];                                       // 0x0370(0x0008)	
	TArray<class UActorComponent*>                     BlueprintCreatedComponents;                               // 0x0378(0x0010) (ExportObject, ZeroConstructor, NonTransactional, ContainsInstancedReference, TextExportTransient, NativeAccessSpecifierPublic) 	
	struct FScriptMulticastDelegate                    OnBeginCursorOver;                                        // 0x0388(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	int                                                NetTag;                                                   // 0x0398(0x0004) (ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData11[0x4];                                       // 0x039C(0x0004)	
	struct FScriptMulticastDelegate                    OnTakePointDamage;                                        // 0x03A0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	TWeakObjectPtr<class AActor>                       ParentComponentActor;                                     // 0x03B0(0x0008) (ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate) 	
	TEnumAsByte<FEAutoReceiveInput>                    AutoReceiveInput;                                         // 0x03B8(0x0001) (Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData12[0x7];                                       // 0x03B9(0x0007)	
	struct FScriptMulticastDelegate                    OnDestroyed;                                              // 0x03C0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	struct FScriptMulticastDelegate                    OnEndPlay;                                                // 0x03D0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData13[0x2];                                       // 0x03E0(0x0002)	
	TEnumAsByte<FEInputConsumeOptions>                 InputConsumeOption;                                       // 0x03E2(0x0001) (ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData14[0x1];                                       // 0x03E3(0x0001)	
	TWeakObjectPtr<class UChildActorComponent>         ParentComponent;                                          // 0x03E4(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate) 	
	float                                              MinNetUpdateFrequency;                                    // 0x03EC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic) 	
	unsigned char                                      UnknownData15[0x8];                                       // 0x03F0(0x0008)	
}
```




```C#
internal const int UWorld = 0x7593728;
internal const int GNames = 0x7815CC8;

internal const int ObjectId = 0x8;

internal const int ChunkSize = 0x3F58;

internal const int ULevel = 0x160;

internal const int ActorsArray = 0x1E8;

internal const int PlayerController = 0x30;

internal const int RootComponent = 0x108;

/* PlayerController */
internal const int AcknowledgedPawn = 0x490;
internal const int PlayerCameraManager = 0x4B0;
internal const int SpectatorsCount = 0xCC4;

/* PrimitiveComponent */
internal const int LastSubmitTime = 0x760;
internal const int LastRenderTime = LastSubmitTime + 8;

/* SceneComponent */
internal const int ComponentToWorld = 0x250;
internal const int CharacterVelocity = 0x200;
internal const int RelativeLocation = 0x2D0;
internal const int AbsoluteLocation = 0x260;

/* SkeletalMeshComponent */
internal const int AnimScriptInstance = 0xC68;

/* SkinnedMeshComponent */
internal const int CachedBoneSpaceTransforms = 0xAC0;

/* Pawn */
internal const int PlayerState = 0x438;

/* PlayerState */
internal const int PlayerName = 0x468;
internal const int KillsNum = 0x4A0;

/* Character */
internal const int SkinnedMeshComponent = 0x4C0;

/* TslCharacter */
internal const int Health = 0xC58;
internal const int GroggyHealth = 0xBAC;
internal const int Team = 0x1680;
internal const int WeaponProcessor = 0xFC8;

/* TslAnimInstance */
internal const int AnimScriptControlRotation = 0x6A0;

/* WeaponProcessorComponent */
internal const int EquippedWeapons = 0x2A8;
internal const int CurrentWeaponIndex = EquippedWeapons + 0x20;

/* TslWeapon_Trajectory */
internal const int WeaponTrajectoryData = 0xF40;

/* WeaponTrajectoryData */
internal const int TrajectoryConfig = 0xB0;
internal const int VDragCoefficient = TrajectoryConfig + 0x2C;

/* CameraCache */
internal const int CameraCacheLocation = 0x1024;
internal const int CameraCacheRotation = 0x15B0;
internal const int CameraCacheFov = 0x15C4;

/* Items */
internal const int ItemPackageArray = 0x530;
internal const int ItemGroupArray = 0x288;
internal const int UItem = 0x650;
internal const int ItemId = 0x268;

```


https://www.unknowncheats.me/forum/pubg-mobile/269708-pubg-mobile-reversal-structs-offsets-7.html
```c#
FTransform ReadFTransform(int ptr)
{
 
	float quatX = ReadFloat(ptr + 0x14);
	float quatY = ReadFloat(ptr + 0x18);
	float quatZ = ReadFloat(ptr + 0x1c);
	float quatW = ReadFloat(ptr + 0x20);
 
	float transX = ReadFloat(ptr + 0x0024);
	float transY = ReadFloat(ptr + 0x0028);
	float transZ = ReadFloat(ptr + 0x002c);
 
	float scaleX = ReadFloat(ptr + 0x0);
	float scaleY = ReadFloat(ptr + 0x4);
	float scaleZ = ReadFloat(ptr + 0x8);
 
	Vector4 fQuat = { quatW, quatX, quatY, quatZ };
	Vector3 trans = { transX, transY, transZ };
	Vector3 scale = { scaleX, scaleY, scaleZ };
	FTransform fTransform (fQuat, trans, scale);
	return fTransform;
}
```


```
```


```
```


```
```


```
```


```
```