
its a backup for if i will need and i cant find again

link: https://www.unknowncheats.me/forum/playerunknown-s-battlegrounds/214976-pubg-reversal-structs-offsets-594.html  
by: baba08000
```C#
/* PUBG 7.2.6.4 */
/* Dumped by baba08000 using SharpOBForcer */
public class SDK
    {
        public const ulong OFFSET_UWorld                    = 0x747B768;
        public const ulong OFFSET_GNAMES                    = 0x736A248;
        public const ulong OFFSET_Decrypt                   = 0x503D028;
 
        public const ulong OFFSET_PersistentLevel           = 0x0228;
        public const ulong OFFSET_GameInstance              = 0x0128;
        public const ulong OFFSET_LevelBuildDataId          = 0x0050;
        public const ulong OFFSET_WorldLocation             = 0x07FC; //OR 5D0
 
        public const ulong OFFSET_ActorsArray               = 0x0180;
        public const ulong OFFSET_ULocalPlayer              = 0x0058;
        
        public const ulong OFFSET_PlayerController          = 0x0038;
        public const ulong OFFSET_ChunkSize                 = 0x4174; 
 
        //ROL4(input ^ a, 14) ^ (ROL4(input ^ a, b) << c) ^ d;
        public const ulong OFFSET_OBJECT_ID = 0x000C;
 
        public const ulong OFFSET_UITEM = 0x0660;
        public const ulong OFFSET_UITEM_ID = 0x0270;
        public const ulong OFFSET_DROPPED_ITEM_GROUP = 0x0158;
        public const ulong OFFSET_ITEM_PACKAGE = 0x0530;
 
        public const ulong OFFSET_LODDistanceScaleGrass = 0x7240488;
        public const ulong OFFSET_GrassRenderDistance = 0x000006C;
        public const ulong OFFSET_UnknownInstantADS = 0x00009F8;
        public static ulong[] OFFSET_WEAPON_RECOIL = new ulong[] { 0x918 /*, 0x9AE*/ };
 
 
 
        /* class APlayerController : public AController */
 
        public const ulong OFFSET_AcknowledgedPawn = 0x0488; //488
 
        /* */
 
        /* class APlayerCameraManager : public AActor */
 
        //struct FCameraCacheEntry CameraCache;
        public const ulong OFFSET_CameraCache = 0x04A8;
 
        //struct FMinimalViewInfo
        public const ulong OFFSET_FOV = 0x1714;
        public const ulong OFFSET_Location = 0x1704;
        public const ulong OFFSET_Rotation = 0x1720;
 
        //├── CameraFOV 0x484 (103f)
        //├── CameraFOV 0xA74 (103f)
        //├── CameraFOV 0xAA4 (103f)
        //├── CameraFOV 0x1714 (103f)
 
        //├── CameraLocation 0x474 (<-13129,17  -3274,822  1891,955>)
        //├── CameraLocation 0xA94 (<-13129,18  -3274,824  1891,948>)
        //├── CameraLocation 0x1704 (<-13129,18  -3274,83  1891,936>)
 
        //├── CameraRotation 0x490 (<1,857736  -177,8135  1,353075E-05>)
        //├── CameraRotation 0xAB0 (<1,857757  -177,8135  -6,456722E-06>)
        //├── CameraRotation 0x1720 (<1,857777  -177,8135  -4,83837E-07>)
 
        /* */
 
        /* class ACharacter : public APawn */
 
        //class UCharacterMovementComponent : public UPawnMovementComponent
        public const ulong OFFSET_CharacterMovement = 0x0490; //4d0 248 3ec
        //float MaxAcceleration;
        public const ulong OFFSET_MaxAcceleration = 0x0288; //308
 
        /* */
 
        /* class UPrimitiveComponent : public USceneComponent */
 
        public const ulong OFFSET_MeshComponent             = 0x0478;
        public const ulong OFFSET_LastRenderTimeOnScreen    = 0x0778;
        public const ulong OFFSET_BoneArray                 = 0x0AD0;
        public const ulong OFFSET_ComponentToWorld          = 0x0330;
 
        /* */
 
        /* class USceneComponent : public UActorComponent */
 
        public const ulong OFFSET_RootComponent         = 0x0240; //480 490
        public const ulong OFFSET_RelativeLocation      = OFFSET_ComponentToWorld + 0x10;
        public const ulong OFFSET_ComponentVelocity     = 0x020C;
        public const ulong OFFSET_UnknownRotation       = 0x02A4;
 
        /* */
 
        /* class ATslWeapon_Trajectory : public ATslWeapon_Gun */
 
        //class UWeaponTrajectoryData*
        public const ulong OFFSET_WeaponTrajectoryData  = 0x0F48;
 
        //struct FWeaponTrajectoryConfig
        public const ulong OFFSET_TrajectoryConfig      = 0x00B8;
        public const ulong OFFSET_InitialSpeed          = OFFSET_TrajectoryConfig + 0x0000;
        public const ulong OFFSET_VDragCoefficient      = OFFSET_TrajectoryConfig + 0x002C;
 
        /* */
 
        /* class UWeaponProcessorComponent : public UActorComponent */
 
        //TArray<class ATslWeapon*> EquippedWeapons;
        public const ulong OFFSET_EquippedWeapons = 0x02B8; //290
 
        //struct FWeaponArmInfo WeaponArmInfo;
        public const ulong OFFSET_WeaponArmInfo = 0x02D8; //4d0 2dd
 
        //struct FWeaponArmInfo WeaponArmInfo;
        public const ulong OFFSET_RightWeaponIndex = 0x0001;
 
        public const ulong OFFSET_CurrentWeaponIndex = OFFSET_WeaponArmInfo + OFFSET_RightWeaponIndex;
 
        /* */
 
        /* class ATslCharacter : public AMutableCharacter */
 
        //class UWeaponProcessorComponent* WeaponProcessor;
        public const ulong OFFSET_WeaponProcessor   = 0x0FC8; //514 4a0 3f8
 
        public const ulong OFFSET_CharacterName     = 0x0FE0;
        public const ulong OFFSET_LastTeamNum       = 0x1508;
        public const ulong OFFSET_Health            = 0x0FB8;
        public const ulong OFFSET_GroggyHealth      = 0x1A5C;
        public const ulong OFFSET_SpectatedCount    = 0x0E60;
 
        /* */
 
        /* class ATslPlayerState : public APlayerState */
 
        //428 ptr correct but no kill num good
        //400 ptr correct
 
        public const ulong OFFSET_PlayerState       = 0x0420;
        public const ulong OFFSET_PlayerStatistics  = 0x0860;
 
        /* */
 
        /* class UTslAnimInstance : public UAnimInstance */
 
        public const ulong OFFSET_UAnimInstance         = 0x0C78;
        public const ulong OFFSET_ControlRotation_CP    = 0x06A8;
        public const ulong OFFSET_RecoilADSRotation_CP  = 0x0B48;
 
        /* */
 
        /* class ATslGameState : public AGameState */
 
        public const ulong OFFSET_GameState                 = 0x08B0;
        public const ulong OFFSET_NumAlivePlayers           = 0x0504;
        public const ulong OFFSET_PoisonGasWarningRadius    = 0x0498;
        public const ulong OFFSET_PoisonGasWarningPosition  = 0x04E8;
        public const ulong OFFSET_RedZoneRadius             = 0x046C; //554
        public const ulong OFFSET_RedZonePosition           = 0x04F8;
        public const ulong OFFSET_BlackZoneRadius           = 0x09FC; //524 3f8 404 400 400
        public const ulong OFFSET_BlackZonePosition         = 0x09F0;
        public const ulong OFFSET_SafetyZoneRadius          = 0x06C0;
        public const ulong OFFSET_SafetyZonePosition        = 0x067C;
 
        /* */
 
        /* Unused offsets
         * public const ulong OFFSET_WEAPON_GUN_DATA = 0x0D90;
         * public const ulong OFFSET_SCOPE_CAMERA = 0x0980;
         * public const ulong OFFSET_SCOPE_CAMERA_BREATH = 0x0000;
         * public const ulong OFFSET_CURRENT_AMMO_DATA = 0x08F0;
         */
    }
```