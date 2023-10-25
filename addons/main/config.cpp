class cfgPatches

{

  class DRNP_main

  {

    author = "Pastoman1"; 

    units[]={
		"DRNP_AR2",
	};

    weapons[]={
		"DRNP_AR2P",
	};

    requiredVersion=0.1;

    requiredAddons[]=

    {
		"a3_drones_f",
		"ace_apl",
		"ace_interaction",
		"ace_spottingscope"
    };

  };

};

class CfgMods

{

  class DRNP

  {

logo = "\z\DRNP\addons\DRNP_main\Data\UI\DRNP_logo.paa";          //Logo displayed in bottom left of main menu

logoOver = "\z\DRNP\addons\DRNP_main\Data\UI\DRNP_logo.paa"; //Logo displayed in the mod menu when mod icon is clicked

logoSmall = "\z\DRNP\addons\DRNP_main\Data\UI\DRNP_logo.paa";     //Logo displayed next to all units and vehicles in the editor

dlcColor[] = {0,0,0,1}; 

hideName = 0; 

hidePicture = 1; 

tooltipOwned = "DRNP"; 

name = "Portable drone"; 

overview = "Drone that fits in backpack";

action = ""; //Link to take people to from "Website" button

  };

};
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};

class Extended_Init_EventHandlers
{
	class DRNP_AR2
	{
		class DRNP_AR2P
		{
			init="_this call ace_dragging_fnc_initObject";
		};
	};
};
class CfgFunctions
{
	class DRNP
	{
		class DRNP_functions
		{
			file="\z\DRNP\addons\DRNP_main\functions";
			class place
			{
			};
			class pickup
			{
			};
			class pickup_RD
			{
			};
			class replacebat
			{
			};
			class canreplacebat
			{
			};
			class canreplacemines
			{
			};
			class checkbat
			{
			};
			class place_al6
			{
			};
			class place_al6_med
			{
			};
			class place_al6_mine
			{
			};
			class place_RD
			{
			};
			class pickup_al6
			{
			};
			class replacemines
			{
			};
		};
	};
};
class CBA_Extended_EventHandlers_base;
class CfgMagazines
{	
	class CA_Magazine;
	class DRNP_AR2_battery: CA_Magazine
	{
		picture="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
		author="Pastoman1";
		scope=2;
		displayName="Portable drone battery";
		ammo="Ar2_battery";
		count=100;
	};
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class ACE_SelfActions
		{
			class ACE_Equipment
			{
				class ace_dron_place_AR2
				{
					displayName="Place AR-2 drone";
					condition="[_player,'DRNP_AR2P'] call ace_common_fnc_hasItem";
					statement="[_player,'DRNP_AR2P'] call DRNP_fnc_place";
					showDisabled=0;
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_dron.paa";
				};
				class ace_dron_place_AL6
				{
					displayName="Place AL-6 drone";
					condition="[_player,'DRNP_AL6P'] call ace_common_fnc_hasItem";
					statement="[_player,'DRNP_AL6P'] call DRNP_fnc_place_al6";
					showDisabled=0;
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class ace_dron_place_AL6_med
				{
					displayName="Place AL-6 Medical drone";
					condition="[_player,'DRNP_AL6P'] call ace_common_fnc_hasItem";
					statement="[_player,'DRNP_AL6P'] call DRNP_fnc_place_al6_med";
					showDisabled=0;
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class ace_dron_place_AL6_mine
				{
					displayName="Place AL-6 EOD drone";
					condition="[_player,'DRNP_AL6P'] call ace_common_fnc_hasItem";
					statement="[_player,'DRNP_AL6P'] call DRNP_fnc_place_al6_mine";
					showDisabled=0;
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class ace_dron_place_RD
				{
					displayName="Place remote designator";
					condition="[_player,'DRNP_RD'] call ace_common_fnc_hasItem";
					statement="[_player,'DRNP_RD'] call DRNP_fnc_place_RD";
					showDisabled=0;
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_rd.paa";
				};
			};
		};
	};
	
	class Air;
	class Helicopter: Air
	{
		class Turrets;
		class HitPoints;
		class ACE_Actions;
	};
	class Helicopter_Base_F: Helicopter
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class HitPoints: HitPoints
		{
			class HitHRotor;
			class HitHull;
			class HitWinch;
		};
		class AnimationSources;
		class EventHandlers;
		class ViewOptics;
		class ViewPilot;
		class Components;
		class ACE_Actions
		{
			class ACE_MainActions;
		};
	};
	class UAV_01_base_F: Helicopter_Base_F
	{
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
			};
		};
		fuelCapacity=200;
	};

	class UAV_06_base_F: Helicopter_Base_F
	{
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
			};
		};
		author="Pastoman1";
		mapSize=2.3199999;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[]=
				{
					"veh_air_UAV_s"
				};
				speechPlural[]=
				{
					"veh_air_UAV_p"
				};
			};
		};
		textSingular="$STR_A3_nameSound_veh_air_UAV_s";
		textPlural="$STR_A3_nameSound_veh_air_UAV_p";
		nameSound="veh_air_UAV_s";
		_generalMacro="UAV_06_base_F";
		scope=0;
		model="\A3\Air_F_Orange\UAV_06\UAV_06_F.p3d";
		icon="\A3\Air_F_Orange\UAV_06\Data\UI\Map_UAV_06_CA.paa";
		picture="\A3\Air_F_Orange\UAV_06\Data\UI\UAV_06_CA.paa";
		hiddenSelections[]=
		{
			"Camo",
			"Medical"
		};
		editorSubcategory="EdSubcat_Drones";
		isUav=1;
		vehicleClass="Autonomous";
		class TextureSources
		{
			class Opfor
			{
				displayName="$STR_A3_TEXTURESOURCES_OPFOR0";
				author="$STR_A3_Bohemia_Interactive";
				textures[]=
				{
					"\A3\Air_F_Orange\UAV_06\Data\O_UAV_06_CO.paa"
				};
				factions[]=
				{
					"OPF_F"
				};
			};
			class Blufor
			{
				displayName="$STR_A3_TEXTURESOURCES_BLU0";
				author="$STR_A3_Bohemia_Interactive";
				textures[]=
				{
					"\A3\Air_F_Orange\UAV_06\Data\B_UAV_06_CO.paa"
				};
				factions[]=
				{
					"BLU_F"
				};
			};
			class Indfor
			{
				displayName="$STR_A3_TEXTURESOURCES_INDEP0";
				author="$STR_A3_Bohemia_Interactive";
				textures[]=
				{
					"\A3\Air_F_Orange\UAV_06\Data\I_UAV_06_CO.paa"
				};
				factions[]=
				{
					"IND_F"
				};
			};
			class Civ
			{
				displayName="$STR_A3_TEXTURESOURCES_CIV0";
				author="$STR_A3_Bohemia_Interactive";
				textures[]=
				{
					"\A3\Air_F_Orange\UAV_06\Data\C_UAV_06_CO.paa"
				};
				factions[]=
				{
					"CIV_F"
				};
			};
			class IDAP
			{
				displayName="$STR_A3_CfgFactionClasses_CIV_IDAP_F0";
				author="$STR_A3_Bohemia_Interactive";
				textures[]=
				{
					"\A3\Air_F_Orange\UAV_06\Data\C_IDAP_UAV_06_CO.paa"
				};
				factions[]=
				{
					"CIV_IDAP_F"
				};
			};
			class Swifd
			{
				displayName="$STR_A3_TextureSources_Swifd0";
				author="$STR_A3_Bohemia_Interactive";
				textures[]=
				{
					"\A3\Air_F_Orange\UAV_06\Data\UAV_06_swifd_CO.paa"
				};
				factions[]=
				{
					"CIV_F"
				};
			};
		};
		class AnimationSources
		{
			class lights_em_hide
			{
				displayName="$STR_A3_CfgVehicles_UAV_06_base_F_AnimationSources_lights_em_hide0";
				source="user";
				initPhase=0;
				animPeriod=9.9999997e-005;
				onPhaseChanged="(_this select 0) animateSource ['lights_em_hide',(_this select 1),true];";
			};
			class LED_lights_hide
			{
				displayName="$STR_A3_CfgVehicles_UAV_06_base_F_AnimationSources_LED_lights_hide0";
				source="user";
				mass=-7;
				initPhase=1;
				animPeriod=0;
				onPhaseChanged="(_this select 0) animateSource ['LED_lights_hide',(_this select 1),true];";
			};
			class Utility_drone
			{
				source="user";
				animPeriod=1e-006;
				initPhase=1;
			};
			class Antimine_drone
			{
				source="user";
				animPeriod=1e-006;
			};
			class Inventory_door
			{
				source="door";
				animPeriod=1.1;
				displayName="$STR_A3_CfgVehicles_UAV_06_base_F_AnimationSources_Inventory_door0";
				onPhaseChanged="(_this select 0) animateDoor ['Inventory_door',_this select 1,is3den]";
			};
			class leaflet_door
			{
				source="user";
				animPeriod=0.25;
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"A3\Air_F_Orange\UAV_06\Data\UAV_06_super.rvmat",
				"A3\Drones_F\Air_F_Gamma\UAV_02\Data\UAV_02_damage.rvmat",
				"A3\Drones_F\Air_F_Gamma\UAV_02\Data\UAV_02_destruct.rvmat"
			};
		};
		class Library
		{
			libTextDesc="$STR_A3_CfgVehicles_UAV_06_base_F_Library0";
		};
		class PilotCamera
		{
			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="WFOV";
					initAngleX=0;
					minAngleX=0;
					maxAngleX=0;
					initAngleY=0;
					minAngleY=0;
					maxAngleY=0;
					initFov=1;
					minFov=1;
					maxFov=1;
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					thermalMode[]={};
					gunnerOpticsModel="\a3\Weapons_F_Orange\Reticle\UAV_06_pilotCamera_F.p3d";
					opticsPPEffects[]=
					{
						"OpticsCHAbera2",
						"OpticsBlur2"
					};
				};
				showMiniMapInOptics=1;
				showUAVViewInOptics=0;
				showSlingLoadManagerInOptics=0;
			};
			minTurn=-60;
			maxTurn=60;
			initTurn=0;
			minElev=-45;
			maxElev=89;
			initElev=0;
			maxXRotSpeed=1;
			maxYRotSpeed=1;
			maxMouseXRotSpeed=0.5;
			maxMouseYRotSpeed=0.5;
			pilotOpticsShowCursor=1;
			controllable=1;
		};
		class MFD
		{
		};
		class Turrets
		{
		};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=0.1;
			};
			class HitHRotor: HitHRotor
			{
				armor=0.30000001;
			};
			class HitWinch: HitWinch
			{
				class DestructionEffects
				{
				};
			};
		};
		class ViewPilot: ViewPilot
		{
			minFov=0.25;
			maxFov=1.25;
			initFov=0.75;
			initAngleX=0;
			minAngleX=-65;
			maxAngleX=85;
			initAngleY=0;
			minAngleY=-150;
			maxAngleY=150;
		};
		class ViewOptics: ViewOptics
		{
			initAngleX=0;
			minAngleX=0;
			maxAngleX=0;
			initAngleY=0;
			minAngleY=0;
			maxAngleY=0;
			minFov=1;
			maxFov=1;
			initFov=1;
			visionMode[]={};
			thermalMode[]={};
		};
		class Exhausts
		{
			class Exhaust_1
			{
				position="Exhaust_1_pos";
				direction="Exhaust_1_dir";
				effect="ExhaustsEffectDrone";
			};
		};
		weapons[]={};
		magazines[]={};
		destrType="DestructDefault";
		driverCompartments="Compartment3";
		cargoCompartments[]=
		{
			"Compartment2"
		};
		driverOpticsModel="a3\Weapons_F_Orange\Reticle\UAV_06_driver_F.p3d";
		driverForceOptics=1;
		formationX=10;
		formationZ=10;
		memoryPointTaskMarker="TaskMarker_1_pos";
		memoryPointDriverOptics="pip_pilot_pos";
		getInRadius=0;
		armor=0.5;
		armorStructural=4;
		damageEffect="UAVDestructionEffects";
		damageTexDelay=0.5;
		dustEffect="UAVDust";
		waterEffect="UAVWater";
		washDownDiameter="10.0f";
		washDownStrength="0.25f";
		killFriendlyExpCoef=0.1;
		unitInfoType="RscOptics_UAV_06";
		driverWeaponsInfoType="RscOptics_UAV_06_TGP";
		extCameraPosition[]={0,0.050000001,-2.55};
		extCameraParams[]={0.93000001,10,30,0.25,1,10,30,0,1};
		uavCameraDriverPos="pip_pilot_pos";
		uavCameraDriverDir="pip_pilot_dir";
		uavCameraGunnerPos="";
		uavCameraGunnerDir="";
		disableInventory=0;
		accuracy=1.5;
		camouflage=0.5;
		audible=0.1;
		startDuration=3;
		maxSpeed=100;
		precision=15;
		steerAheadSimul=0.5;
		steerAheadPlan=0.69999999;
		predictTurnPlan=2;
		predictTurnSimul=1.5;
		brakeDistance=200;
		liftForceCoef=1.6;
		cyclicAsideForceCoef=2.75;
		cyclicForwardForceCoef=0.58999997;
		bodyFrictionCoef=0.57999998;
		backRotorForceCoef=4.5;
		fuelCapacity=200;
		maxFordingDepth=0.30000001;
		altFullForce=1000;
		altNoForce=2000;
		cost=20000;
		threat[]={0.1,0.1,0.1};
		epeImpulseDamageCoef=1.5;
		fuelExplosionPower=0;
		maxMainRotorDive=0;
		minMainRotorDive=0;
		neutralMainRotorDive=0;
		tailBladeVertical=0;
		gearRetracting=0;
		mainRotorSpeed=-7;
		backRotorSpeed=7;
		LODTurnedIn=-1;
		LODTurnedOut=-1;
		maximumLoad=80;
		class TransportItems
		{
		};
		class Reflectors
		{
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteHeightLimit=5;
				canBeTransported=1;
				parachuteClass="B_Parachute_02_F";
				dimensions[]=
				{
					"BBox_1_1_pos",
					"BBox_1_2_pos"
				};
			};
			class Carrier
			{
				cargoBayDimensions[]=
				{
					"VVT_cargo_1",
					"VVT_cargo_2"
				};
				disableHeightLimit=0;
				maxLoadMass=25000;
				cargoAlignment[]=
				{
					"center",
					"front"
				};
				cargoSpacing[]={0,0,0};
				exits[]=
				{
					"VVT_exit"
				};
				unloadingInterval=2;
				loadingDistance=5;
				loadingAngle=60;
				parachuteClassDefault="B_Parachute_02_F";
				parachuteHeightLimitDefault=5;
			};
		};
		class Components: Components
		{
			class TransportPylonsComponent
			{
				UIPicture="\a3\Air_F_Orange\UAV_06\Data\UI\UAV_06_3DEN_CA.paa";
				class pylons
				{
					class pylons1
					{
						maxweight=15;
						hardpoints[]=
						{
							"UNI_LEAFLETS_PYLON"
						};
						attachment="";
						bay=-1;
						priority=1;
						UIposition[]={0.31999999,0.28};
						turret[]={};
						mirroredMissilePos=0;
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoAirborneMiniMap";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoAirborneMiniMap";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
				};
			};
		};
		radarTargetSize=0.1;
		visualTargetSize=0.1;
		irTarget=0;
		lockDetectionSystem=0;
		incomingMissileDetectionSystem=0;
		irScanRangeMin=0;
		irScanRangeMax=0;
		irScanToEyeFactor=1;
		class UserActions
		{
			class beacons_start
			{
				userActionID=50;
				displayName="$STR_A3_CfgVehicles_beacons_on";
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\beacons_ON_ca.paa' size='2.5' />";
				position="";
				priority=1.5;
				radius=1.8;
				animPeriod=2;
				onlyForplayer=0;
				showWindow=0;
				condition="(cameraOn == this) AND {this animationSourcePhase 'LED_lights_hide' isEqualTo 0} AND  {this animationSourcePhase 'lights_em_hide' < 0.5} AND {Alive(this)} ";
				statement="this animateSource ['lights_em_hide',1];";
			};
			class beacons_stop: beacons_start
			{
				userActionID=51;
				displayName="$STR_A3_CfgVehicles_beacons_off";
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\beacons_OFF_ca.paa' size='2.5' />";
				condition="(cameraOn == this)  AND {this animationSourcePhase 'LED_lights_hide' isEqualTo 0} AND  {this animationSourcePhase 'lights_em_hide' > 0.5} AND {Alive(this)} ";
				statement="this animateSource ['lights_em_hide',0];";
			};
		};
	};
	class B_UAV_06_medical_F: UAV_06_base_F
	{
	};
	class UAV_06_antimine_base_F: UAV_06_base_F
	{
		mineDetectorRange=15;
	};

	class DRNP_AL6_Antimine: UAV_06_antimine_base_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			mineDetectorRange=15;
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"cargo_bumpers_dam_hide",
					0
				},
				
				{
					"bumpers_dam_hide",
					0
				},
				
				{
					"minedetector_dam_hide",
					0
				},
				
				{
					"mine_detector_hide",
					0
				},
				
				{
					"cargo_hide",
					1
				},
				
				{
					"bumpers_hide",
					1
				},
				
				{
					"inventory_door",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller5_rotation",
					0
				},
				
				{
					"propeller5_blur_rotation",
					0
				},
				
				{
					"propeller6_rotation",
					0
				},
				
				{
					"propeller6_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"propeller5_hide",
					0
				},
				
				{
					"propeller5_blur_hide",
					0
				},
				
				{
					"propeller6_hide",
					0
				},
				
				{
					"propeller6_blur_hide",
					0
				},
				
				{
					"lights_em_1",
					901.08002
				},
				
				{
					"lights_em_2",
					901.08002
				},
				
				{
					"lights_em_1_flash",
					901.08002
				},
				
				{
					"lights_em_2_flash",
					901.08002
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.25;
			verticalOffsetWorld=0;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_al6";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_ReplaceCharge
				{
					selection="";
					displayName="Replace EOD charges";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacemines";
					statement="[_target,_player] call DRNP_fnc_replacemines";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Charge.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F_Orange\Data\CfgVehicles\C_IDAP_UAV_06_antimine_F.jpg";
		_generalMacro="DRNP_AL6_Antimine";
		displayName="AL-6 EOD (Portable)";
		scope=2;
		icon="\A3\Air_F_Orange\UAV_06\Data\UI\Map_UAV_06_demining_CA.paa";
		picture="\A3\Air_F_Orange\UAV_06\Data\UI\UAV_06_demining_CA.paa";
		side=1;
		faction="BLU_F";
		forceInGarage=1;
		crew="B_UAV_AI_F";
		typicalCargo[]=
		{
			"B_UAV_AI_F"
		};
		hiddenSelectionsTextures[]=
		{
			"A3\Air_F_Orange\UAV_06\Data\B_UAV_06_CO.paa"
		};
	};

	class DRNP_AL6_Antimine_O: UAV_06_antimine_base_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			mineDetectorRange=15;
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"cargo_bumpers_dam_hide",
					0
				},
				
				{
					"bumpers_dam_hide",
					0
				},
				
				{
					"minedetector_dam_hide",
					0
				},
				
				{
					"mine_detector_hide",
					0
				},
				
				{
					"cargo_hide",
					1
				},
				
				{
					"bumpers_hide",
					1
				},
				
				{
					"inventory_door",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller5_rotation",
					0
				},
				
				{
					"propeller5_blur_rotation",
					0
				},
				
				{
					"propeller6_rotation",
					0
				},
				
				{
					"propeller6_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"propeller5_hide",
					0
				},
				
				{
					"propeller5_blur_hide",
					0
				},
				
				{
					"propeller6_hide",
					0
				},
				
				{
					"propeller6_blur_hide",
					0
				},
				
				{
					"lights_em_1",
					901.08002
				},
				
				{
					"lights_em_2",
					901.08002
				},
				
				{
					"lights_em_1_flash",
					901.08002
				},
				
				{
					"lights_em_2_flash",
					901.08002
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.25;
			verticalOffsetWorld=0;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_al6";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_ReplaceCharge
				{
					selection="";
					displayName="Replace EOD charges";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacemines";
					statement="[_target,_player] call DRNP_fnc_replacemines";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Charge.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F_Orange\Data\CfgVehicles\O_UAV_06_F.jpg";
		_generalMacro="DRNP_AL6_Antimine_O";
		displayName="AL-6 EOD (Portable)";
		scope=2;
		icon="\A3\Air_F_Orange\UAV_06\Data\UI\Map_UAV_06_demining_CA.paa";
		picture="\A3\Air_F_Orange\UAV_06\Data\UI\UAV_06_demining_CA.paa";
		side=0;
		faction="OPF_F";
		forceInGarage=1;
		crew="O_UAV_AI";
		typicalCargo[]=
		{
			"O_UAV_AI"
		};
		hiddenSelectionsTextures[]=
		{
			"A3\Air_F_Orange\UAV_06\Data\O_UAV_06_CO.paa"
		};
	};
	class DRNP_AL6_Antimine_I: UAV_06_antimine_base_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			mineDetectorRange=15;
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"cargo_bumpers_dam_hide",
					0
				},
				
				{
					"bumpers_dam_hide",
					0
				},
				
				{
					"minedetector_dam_hide",
					0
				},
				
				{
					"mine_detector_hide",
					0
				},
				
				{
					"cargo_hide",
					1
				},
				
				{
					"bumpers_hide",
					1
				},
				
				{
					"inventory_door",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller5_rotation",
					0
				},
				
				{
					"propeller5_blur_rotation",
					0
				},
				
				{
					"propeller6_rotation",
					0
				},
				
				{
					"propeller6_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"propeller5_hide",
					0
				},
				
				{
					"propeller5_blur_hide",
					0
				},
				
				{
					"propeller6_hide",
					0
				},
				
				{
					"propeller6_blur_hide",
					0
				},
				
				{
					"lights_em_1",
					901.08002
				},
				
				{
					"lights_em_2",
					901.08002
				},
				
				{
					"lights_em_1_flash",
					901.08002
				},
				
				{
					"lights_em_2_flash",
					901.08002
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.25;
			verticalOffsetWorld=0;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_al6";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_ReplaceCharge
				{
					selection="";
					displayName="Replace EOD charges";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacemines";
					statement="[_target,_player] call DRNP_fnc_replacemines";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Charge.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F_Orange\Data\CfgVehicles\I_UAV_06_F.jpg";
		_generalMacro="DRNP_AL6_Antimine_I";
		displayName="AL-6 EOD (Portable)";
		scope=2;
		icon="\A3\Air_F_Orange\UAV_06\Data\UI\Map_UAV_06_demining_CA.paa";
		picture="\A3\Air_F_Orange\UAV_06\Data\UI\UAV_06_demining_CA.paa";
		side=2;
		faction="IND_F";
		forceInGarage=1;
		crew="I_UAV_AI_F";
		typicalCargo[]=
		{
			"I_UAV_AI_F"
		};
		hiddenSelectionsTextures[]=
		{
			"A3\Air_F_Orange\UAV_06\Data\I_UAV_06_CO.paa"
		};
	};
	class DRNP_AL6_MED: B_UAV_06_medical_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"cargo_bumpers_dam_hide",
					0
				},
				
				{
					"bumpers_dam_hide",
					0
				},
				
				{
					"minedetector_dam_hide",
					0
				},
				
				{
					"mine_detector_hide",
					1
				},
				
				{
					"cargo_hide",
					0
				},
				
				{
					"bumpers_hide",
					0
				},
				
				{
					"inventory_door",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller5_rotation",
					0
				},
				
				{
					"propeller5_blur_rotation",
					0
				},
				
				{
					"propeller6_rotation",
					0
				},
				
				{
					"propeller6_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"propeller5_hide",
					0
				},
				
				{
					"propeller5_blur_hide",
					0
				},
				
				{
					"propeller6_hide",
					0
				},
				
				{
					"propeller6_blur_hide",
					0
				},
				
				{
					"lights_em_1",
					700.84998
				},
				
				{
					"lights_em_2",
					700.84998
				},
				
				{
					"lights_em_1_flash",
					700.84998
				},
				
				{
					"lights_em_2_flash",
					700.84998
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.249;
			verticalOffsetWorld=0;
			init="[this, '', []] call bis_fnc_initVehicle";
		};

		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_al6";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F_Orange\Data\CfgVehicles\B_UAV_06_medical_F.jpg";
		_generalMacro="DRNP_AL6_MED";
		displayName="AL-6 Medical (Portable)";
		scope=2;
		side=1;
		faction="BLU_F";
		forceInGarage=1;
		crew="B_UAV_AI_F";
		typicalCargo[]=
		{
			"B_UAV_AI_F"
		};
		
		hiddenSelectionsTextures[]=
		{
			"A3\Air_F_Orange\UAV_06\Data\B_UAV_06_medical_CO.paa",
			"A3\Air_F_Orange\UAV_06\Data\B_UAV_06_medical_CO.paa"
		};
	};
	class DRNP_AL6_MED_O: B_UAV_06_medical_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"cargo_bumpers_dam_hide",
					0
				},
				
				{
					"bumpers_dam_hide",
					0
				},
				
				{
					"minedetector_dam_hide",
					0
				},
				
				{
					"mine_detector_hide",
					1
				},
				
				{
					"cargo_hide",
					0
				},
				
				{
					"bumpers_hide",
					0
				},
				
				{
					"inventory_door",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller5_rotation",
					0
				},
				
				{
					"propeller5_blur_rotation",
					0
				},
				
				{
					"propeller6_rotation",
					0
				},
				
				{
					"propeller6_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"propeller5_hide",
					0
				},
				
				{
					"propeller5_blur_hide",
					0
				},
				
				{
					"propeller6_hide",
					0
				},
				
				{
					"propeller6_blur_hide",
					0
				},
				
				{
					"lights_em_1",
					700.84998
				},
				
				{
					"lights_em_2",
					700.84998
				},
				
				{
					"lights_em_1_flash",
					700.84998
				},
				
				{
					"lights_em_2_flash",
					700.84998
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.249;
			verticalOffsetWorld=0;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_al6";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F_Orange\Data\CfgVehicles\B_UAV_06_medical_F.jpg";
		_generalMacro="DRNP_AL6_MED_O";
		displayName="AL-6 Medical (Portable)";
		scope=2;
		side=0;
		faction="OPF_F";
		forceInGarage=1;
		crew="O_UAV_AI";
		typicalCargo[]=
		{
			"O_UAV_AI"
		};
		
		hiddenSelectionsTextures[]=
		{
			"A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa",
			"A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa"
		};
	};
	class DRNP_AL6_MED_I: B_UAV_06_medical_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"cargo_bumpers_dam_hide",
					0
				},
				
				{
					"bumpers_dam_hide",
					0
				},
				
				{
					"minedetector_dam_hide",
					0
				},
				
				{
					"mine_detector_hide",
					1
				},
				
				{
					"cargo_hide",
					0
				},
				
				{
					"bumpers_hide",
					0
				},
				
				{
					"inventory_door",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller5_rotation",
					0
				},
				
				{
					"propeller5_blur_rotation",
					0
				},
				
				{
					"propeller6_rotation",
					0
				},
				
				{
					"propeller6_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"propeller5_hide",
					0
				},
				
				{
					"propeller5_blur_hide",
					0
				},
				
				{
					"propeller6_hide",
					0
				},
				
				{
					"propeller6_blur_hide",
					0
				},
				
				{
					"lights_em_1",
					700.84998
				},
				
				{
					"lights_em_2",
					700.84998
				},
				
				{
					"lights_em_1_flash",
					700.84998
				},
				
				{
					"lights_em_2_flash",
					700.84998
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.249;
			verticalOffsetWorld=0;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_al6";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F_Orange\Data\CfgVehicles\B_UAV_06_medical_F.jpg";
		_generalMacro="DRNP_AL6_MED_I";
		displayName="AL-6 Medical (Portable)";
		scope=2;
		side=2;
		faction="IND_F";
		forceInGarage=1;
		crew="I_UAV_AI_F";
		typicalCargo[]=
		{
			"I_UAV_AI_F"
		};
		
		hiddenSelectionsTextures[]=
		{
			"A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa",
			"A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa"
		};
	};
	class DRNP_AL6: UAV_06_base_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"cargo_bumpers_dam_hide",
					0
				},
				
				{
					"bumpers_dam_hide",
					0
				},
				
				{
					"minedetector_dam_hide",
					0
				},
				
				{
					"mine_detector_hide",
					1
				},
				
				{
					"cargo_hide",
					0
				},
				
				{
					"bumpers_hide",
					0
				},
				
				{
					"inventory_door",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller5_rotation",
					0
				},
				
				{
					"propeller5_blur_rotation",
					0
				},
				
				{
					"propeller6_rotation",
					0
				},
				
				{
					"propeller6_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"propeller5_hide",
					0
				},
				
				{
					"propeller5_blur_hide",
					0
				},
				
				{
					"propeller6_hide",
					0
				},
				
				{
					"propeller6_blur_hide",
					0
				},
				
				{
					"lights_em_1",
					698.25
				},
				
				{
					"lights_em_2",
					698.25
				},
				
				{
					"lights_em_1_flash",
					698.25
				},
				
				{
					"lights_em_2_flash",
					698.25
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.249;
			verticalOffsetWorld=0;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_al6";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F_Orange\Data\CfgVehicles\B_UAV_06_F.jpg";
		_generalMacro="DRNP_AL6";
		displayName="AL-6 (Portable)";
		scope=2;
		side=1;
		faction="BLU_F";
		crew="B_UAV_AI_F";
		typicalCargo[]=
		{
			"B_UAV_AI_F"
		};
		hiddenSelectionsTextures[]=
		{
			"A3\Air_F_Orange\UAV_06\Data\B_UAV_06_CO.paa"
		};
	};

	class DRNP_AL6_O: UAV_06_base_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"cargo_bumpers_dam_hide",
					0
				},
				
				{
					"bumpers_dam_hide",
					0
				},
				
				{
					"minedetector_dam_hide",
					0
				},
				
				{
					"mine_detector_hide",
					1
				},
				
				{
					"cargo_hide",
					0
				},
				
				{
					"bumpers_hide",
					0
				},
				
				{
					"inventory_door",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller5_rotation",
					0
				},
				
				{
					"propeller5_blur_rotation",
					0
				},
				
				{
					"propeller6_rotation",
					0
				},
				
				{
					"propeller6_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"propeller5_hide",
					0
				},
				
				{
					"propeller5_blur_hide",
					0
				},
				
				{
					"propeller6_hide",
					0
				},
				
				{
					"propeller6_blur_hide",
					0
				},
				
				{
					"lights_em_1",
					698.25
				},
				
				{
					"lights_em_2",
					698.25
				},
				
				{
					"lights_em_1_flash",
					698.25
				},
				
				{
					"lights_em_2_flash",
					698.25
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.249;
			verticalOffsetWorld=0;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_al6";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F_Orange\Data\CfgVehicles\O_UAV_06_F.jpg";
		_generalMacro="DRNP_AL6_O";
		displayName="AL-6 (Portable)";
		scope=2;
		side=0;
		faction="OPF_F";
		crew="O_UAV_AI";
		typicalCargo[]=
		{
			"O_UAV_AI"
		};
		hiddenSelectionsTextures[]=
		{
			"A3\Air_F_Orange\UAV_06\Data\O_UAV_06_CO.paa"
		};
	};

	class DRNP_AL6_I: UAV_06_base_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"cargo_bumpers_dam_hide",
					0
				},
				
				{
					"bumpers_dam_hide",
					0
				},
				
				{
					"minedetector_dam_hide",
					0
				},
				
				{
					"mine_detector_hide",
					1
				},
				
				{
					"cargo_hide",
					0
				},
				
				{
					"bumpers_hide",
					0
				},
				
				{
					"inventory_door",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller5_rotation",
					0
				},
				
				{
					"propeller5_blur_rotation",
					0
				},
				
				{
					"propeller6_rotation",
					0
				},
				
				{
					"propeller6_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"propeller5_hide",
					0
				},
				
				{
					"propeller5_blur_hide",
					0
				},
				
				{
					"propeller6_hide",
					0
				},
				
				{
					"propeller6_blur_hide",
					0
				},
				
				{
					"lights_em_1",
					698.25
				},
				
				{
					"lights_em_2",
					698.25
				},
				
				{
					"lights_em_1_flash",
					698.25
				},
				
				{
					"lights_em_2_flash",
					698.25
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.249;
			verticalOffsetWorld=0;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_al6";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F_Orange\Data\CfgVehicles\I_UAV_06_F.jpg";
		_generalMacro="DRNP_AL6_I";
		displayName="AL-6 (Portable)";
		scope=2;
		side=2;
		faction="IND_F";
		crew="I_UAV_AI_F";
		typicalCargo[]=
		{
			"I_UAV_AI_F"
		};
		hiddenSelectionsTextures[]=
		{
			"A3\Air_F_Orange\UAV_06\Data\I_UAV_06_CO.paa"
		};
	};
	class DRNP_AR2: UAV_01_base_F
	{
		author="Pastoman1";
		displayName="AR-2 (Portable)";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"mainturret",
					0
				},
				
				{
					"maingun",
					-0.050000001
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.15000001;
			verticalOffsetWorld=-0.001;
			init="''";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_dron.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_UAV_01_F.jpg";
		_generalMacro="DRNP_AR2";
		scope=2;
		scopeCurator=2;
		side=1;
		faction="BLU_F";
		crew="B_UAV_AI";
		typicalCargo[]=
		{
			"B_UAV_AI"
		};
		accuracy=0.5;
		hiddenSelectionsTextures[]=
		{
			"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_CO.paa"
		};
		textureList[]=
		{
			"Blufor",
			1
		};
	};
	
	class DRNP_AR2_O: UAV_01_base_F
	{
		author="Pastoman1";
		displayName="AR-2 (Portable)";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"mainturret",
					0
				},
				
				{
					"maingun",
					-0.050000001
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.15000001;
			verticalOffsetWorld=-0.001;
			init="''";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_dron.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_UAV_01_F.jpg";
		_generalMacro="DRNP_AR2_O";
		scope=2;
		scopeCurator=2;
		side=0;
		faction="OPF_F";
		crew="O_UAV_AI";
		typicalCargo[]=
		{
			"O_UAV_AI"
		};
		accuracy=0.5;
		hiddenSelectionsTextures[]=
		{
			"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_CO.paa"
		};
		textureList[]=
		{
			"Opfor",
			1
		};
	};
	
	class DRNP_AR2_I: UAV_01_base_F
	{
		author="Pastoman1";
		displayName="AR-2 (Portable)";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"rotorimpacthide",
					0
				},
				
				{
					"tailrotorimpacthide",
					0
				},
				
				{
					"propeller1_rotation",
					0
				},
				
				{
					"propeller1_blur_rotation",
					0
				},
				
				{
					"propeller2_rotation",
					0
				},
				
				{
					"propeller2_blur_rotation",
					0
				},
				
				{
					"propeller3_rotation",
					0
				},
				
				{
					"propeller3_blur_rotation",
					0
				},
				
				{
					"propeller4_rotation",
					0
				},
				
				{
					"propeller4_blur_rotation",
					0
				},
				
				{
					"propeller1_hide",
					0
				},
				
				{
					"propeller1_blur_hide",
					0
				},
				
				{
					"propeller2_hide",
					0
				},
				
				{
					"propeller2_blur_hide",
					0
				},
				
				{
					"propeller3_hide",
					0
				},
				
				{
					"propeller3_blur_hide",
					0
				},
				
				{
					"propeller4_hide",
					0
				},
				
				{
					"propeller4_blur_hide",
					0
				},
				
				{
					"mainturret",
					0
				},
				
				{
					"maingun",
					-0.050000001
				}
			};
			hide[]=
			{
				"zasleh",
				"tail rotor blur",
				"main rotor blur",
				"zadni svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.15000001;
			verticalOffsetWorld=-0.001;
			init="''";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup drone";
					distance=5;
					condition="(alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_dron.paa";
				};
				class DRNP_ReplaceBattery
				{
					selection="";
					displayName="Replace battery";
					distance=5;
					condition="[_target,_player] call DRNP_fnc_canreplacebat";
					statement="[_target,_player] call DRNP_fnc_replacebat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_Batt.paa";
				};
				class DRNP_CheckBattery
				{
					selection="";
					displayName="Check battery";
					distance=5;
					condition="(!(isEngineOn _target) && alive _target)";
					statement="[_target,_player] call DRNP_fnc_checkbat";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_CheckBatt.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_UAV_01_F.jpg";
		_generalMacro="DRNP_AR2_I";
		scope=2;
		scopeCurator=2;
		side=2;
		faction="IND_F";
		crew="I_UAV_AI";
		typicalCargo[]=
		{
			"I_Soldier_lite_F"
		};
		accuracy=0.5;
		hiddenSelectionsTextures[]=
		{
			"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_CO.paa"
		};
		textureList[]=
		{
			"Indep",
			1
		};
	};
	
	class Item_Base_F;
	class DRNP_AR2_Item: Item_Base_F
	{
		author="Pastoman1";
		scope=2;
		scopeCurator=2;
		displayName="AR-2 (Portable)";
		vehicleClass="Items";
		editorCategory="EdCat_Equipment";
		editorSubcategory="EdSubcat_InventoryItems";
		editorPreview="\DRNP_main\UI\icon_dron.paa";
		class TransportItems
		{
			class _xx_ace_Dron
			{
				name="DRNP_AR2";
				count=1;
			};
		};
	};
	class DRNP_AL6_Item: Item_Base_F
	{
		author="Pastoman1";
		scope=2;
		scopeCurator=2;
		displayName="AL-6 (Portable)";
		vehicleClass="Items";
		editorCategory="EdCat_Equipment";
		editorSubcategory="EdSubcat_InventoryItems";
		editorPreview="\DRNP_main\UI\icon_AL6.paa";
		class TransportItems
		{
			class _xx_ace_Dron
			{
				name="DRNP_AL6";
				count=1;
			};
		};
	};

	class Land;
	class LandVehicle: Land
	{
		class ViewPilot;
		class NewTurret;
		class ACE_Actions;
	};

	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class viewOptics;
			};
		};
		class EventHandlers;
		class AnimationSources;
		class ACE_Actions
		{
			class ACE_MainActions;
		};
	};

	class Static_Designator_01_base_F: StaticWeapon
	{
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
			};
		};
		author="$STR_A3_Bohemia_Interactive";
		mapSize=0.69999999;
		_generalMacro="Static_Designator_01_base_F";
		features="Randomization: No						<br />Camo selections: 1 - the whole weapon with pod						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Firing from vehicles: Just the designator						<br />Slingload: No						<br />Cargo proxy indexes: None";
		scope=0;
		DLC="Mark";
		displayname="$STR_A3_CfgVehicles_Static_Designator_01_base_F1";
		overviewPicture="\A3\Data_F_Mark\Images\watermarkInfo_page11_ca.paa";
		transportSoldier=0;
		cargoAction[]=
		{
			"Mortar_Gunner"
		};
		getInAction="GetInMortar";
		getOutAction="GetOutLow";
		editorSubcategory="EdSubcat_Turrets";
		picture="\A3\Static_F_Mark\Designator_01\Data\UI\Designator_01_CA.paa";
		icon="\A3\Static_F_Mark\Designator_01\Data\UI\map_Designator_01_CA.paa";
		cost=200000;
		accuracy=0.25;
		threat[]={1,0.30000001,0.1};
		isUav=1;
		getInRadius=0;
		uavCameraGunnerPos="eye";
		uavCameraGunnerDir="look";
		selectionDamage="DamT_1";
		epeImpulseDamageCoef=60;
		extCameraPosition[]={0,0.5,-3};
		hiddenSelections[]=
		{
			"Camo",
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"a3\static_f_mark\designator_01\data\ld01_remote_co.paa",
			"a3\weapons_f_mark\binocular\data\ltlm_snd_co.paa"
		};
		class TextureSources
		{
			class Sand
			{
				displayname="$STR_A3_TEXTURESOURCES_SAND0";
				author="$STR_A3_Bohemia_Interactive";
				factions[]=
				{
					"BLU_F"
				};
				textures[]=
				{
					"a3\static_f_mark\designator_01\data\ld01_remote_co.paa",
					"a3\weapons_f_mark\binocular\data\ltlm_snd_co.paa"
				};
			};
		};
		reportRemoteTargets=1;
		reportOwnPosition=1;
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"A3\Static_F_Mark\Designator_01\Data\LD01_remote.rvmat",
				"A3\Static_F_Mark\Designator_02\Data\remote_destruct.rvmat",
				"A3\Static_F_Mark\Designator_02\Data\remote_destruct.rvmat",
				"A3\Weapons_F_Mark\Binocular\Data\ltlm.rvmat",
				"A3\Static_F_Mark\Designator_02\Data\remote_destruct.rvmat",
				"A3\Static_F_Mark\Designator_02\Data\remote_destruct.rvmat"
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundElevation[]=
				{
					"A3\Sounds_F_Mark\arsenal\sfx\Remote_Cameras\Remote_Camera_NATO",
					1,
					1,
					10
				};
				soundServo[]=
				{
					"A3\Sounds_F_Mark\arsenal\sfx\Remote_Cameras\Remote_Camera_servo_NATO",
					0.56234133,
					1,
					10
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F_Mark\arsenal\sfx\Remote_Cameras\Remote_Camera_servo_vertical_NATO",
					0.56234133,
					1,
					10
				};
				gunnergetInAction="";
				gunnergetOutAction="";
				weapons[]=
				{
					"Laserdesignator_mounted"
				};
				magazines[]=
				{
					"Laserbatteries"
				};
				animationSourceElevation="MainElevation";
				gunBeg="look";
				gunEnd="eye";
				maxHorizontalRotSpeed=2.4000001;
				maxVerticalRotSpeed=2.4000001;
				initElev=0;
				minTurn=-180;
				maxTurn=180;
				initTurn=0;
				cameraDir="look";
				gunnerForceOptics=1;
				memoryPointGunnerOptics="eye";
				gunnerOpticsModel="\A3\Weapons_F_beta\Binocular\lasermarker_optics";
				turretInfoType="RscOptics_LaserDesignator";
				class ViewOptics: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.1242;
					minFov=0.0125;
					maxFov=0.1242;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"TI"
					};
					thermalMode[]={2};
				};
			};
		};
		htMin=1;
		htMax=480;
		afMax=0;
		mfMax=0;
		mFact=1;
		tBody=100;
		class DestructionEffects
		{
			class Smoke
			{
				simulation="particles";
				type="WeaponWreckSmoke";
				position="destructionEffect";
				intensity=1;
				interval=1;
				lifeTime=5;
			};
		};
		model="\A3\Static_F_Mark\Designator_01\Designator_01_F";
		class assembleInfo
		{
			primary=0;
			base="";
			assembleTo[]={""};
			dissasembleTo="";
			displayName="";
		};
		class EventHandlers: EventHandlers
		{
			init="(_this select 0) execVM '\A3\Static_F_Mark\Designator_01\Scripts\init.sqf'";
		};
		class AnimationSources: AnimationSources
		{
			class Init
			{
				source="user";
				animPeriod=0.5;
				initPhase=0;
			};
			class InitPiston
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Designator_hide
			{
				source="user";
				animPeriod=0;
				displayname="Hide designator";
				mass=-10;
			};
		};
	};

	class DRNP_BLUEFOR_Static_Designator_01_F: Static_Designator_01_base_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"mainturret",
					0
				},
				
				{
					"maingun",
					0
				},
				
				{
					"mainelevation_01",
					0
				},
				
				{
					"mainelevation_02",
					0
				},
				
				{
					"mainelevation_03",
					0
				},
				
				{
					"mainelevation_04",
					0
				},
				
				{
					"initturret",
					0
				},
				
				{
					"initgun",
					0
				},
				
				{
					"initelevation_01",
					0
				},
				
				{
					"initelevation_02",
					0
				},
				
				{
					"initelevation_03",
					0
				},
				
				{
					"initelevation_04",
					0
				}
			};
			hide[]=
			{
				"light_back",
				"brzdove svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.509;
			verticalOffsetWorld=0.001;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup remote designator";
					distance=5;
					condition="(alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_RD";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_rd.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Static_Designator_01_F.jpg";
		_generalMacro="B_Static_Designator_01_F";
		scope=2;
		side=1;
		faction="BLU_F";
		crew="B_UAV_AI";
		displayname="Remote Designator (Portable)";
	};

	class DRNP_INDEP_Static_Designator_01_F: Static_Designator_01_base_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"mainturret",
					0
				},
				
				{
					"maingun",
					0
				},
				
				{
					"mainelevation_01",
					0
				},
				
				{
					"mainelevation_02",
					0
				},
				
				{
					"mainelevation_03",
					0
				},
				
				{
					"mainelevation_04",
					0
				},
				
				{
					"initturret",
					0
				},
				
				{
					"initgun",
					0
				},
				
				{
					"initelevation_01",
					0
				},
				
				{
					"initelevation_02",
					0
				},
				
				{
					"initelevation_03",
					0
				},
				
				{
					"initelevation_04",
					0
				}
			};
			hide[]=
			{
				"light_back",
				"brzdove svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.509;
			verticalOffsetWorld=0.001;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup remote designator";
					distance=5;
					condition="(alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_RD";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_rd.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\B_Static_Designator_01_F.jpg";
		_generalMacro="B_Static_Designator_01_F";
		scope=2;
		side=2;
		faction="IND_F";
		crew="I_UAV_AI";
		displayname="Remote Designator (Portable)";
	};

	class Static_Designator_02_base_F: StaticWeapon
	{
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
			};
		};
		author="$STR_A3_Bohemia_Interactive";
		mapSize=0.56999999;
		_generalMacro="Static_Designator_02_base_F";
		features="Randomization: No						<br />Camo selections: 1 - the whole weapon with pod						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Firing from vehicles: Just the designator						<br />Slingload: No						<br />Cargo proxy indexes: None";
		scope=0;
		DLC="Mark";
		displayname="$STR_A3_CfgVehicles_Static_Designator_02_base_F0";
		transportSoldier=0;
		cargoAction[]=
		{
			"Mortar_Gunner"
		};
		getInAction="GetInMortar";
		getOutAction="GetOutLow";
		editorSubcategory="EdSubcat_Turrets";
		picture="\A3\Static_F_Mark\Designator_02\Data\UI\Designator_02_CA.paa";
		icon="\A3\Static_F_Mark\Designator_02\Data\UI\map_Designator_02_CA.paa";
		cost=200000;
		accuracy=0.25;
		threat[]={1,0.30000001,0.1};
		isUav=1;
		getInRadius=0;
		uavCameraGunnerPos="eye";
		uavCameraGunnerDir="look";
		selectionDamage="DamT_1";
		epeImpulseDamageCoef=55;
		extCameraPosition[]={0,0.5,-3};
		reportRemoteTargets=1;
		reportOwnPosition=1;
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"A3\Static_F_Mark\Designator_02\Data\LD02_remote.rvmat",
				"A3\Static_F_Mark\Designator_02\Data\remote_destruct.rvmat",
				"A3\Static_F_Mark\Designator_02\Data\remote_destruct.rvmat",
				"A3\Weapons_F_Mark\Binocular\Data\LD02_body.rvmat",
				"A3\Static_F_Mark\Designator_02\Data\remote_destruct.rvmat",
				"A3\Static_F_Mark\Designator_02\Data\remote_destruct.rvmat"
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundElevation[]=
				{
					"A3\Sounds_F_Mark\arsenal\sfx\Remote_Cameras\Remote_Camera_CSAT",
					1,
					1,
					10
				};
				soundServo[]=
				{
					"A3\Sounds_F_Mark\arsenal\sfx\Remote_Cameras\Remote_Camera_servo_CSAT",
					0.39810717,
					1,
					10
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F_Mark\arsenal\sfx\Remote_Cameras\Remote_Camera_servo_vertical_CSAT",
					0.56234133,
					1,
					10
				};
				gunnergetInAction="";
				gunnergetOutAction="";
				weapons[]=
				{
					"Laserdesignator_mounted"
				};
				magazines[]=
				{
					"Laserbatteries"
				};
				animationSourceElevation="MainElevation";
				gunBeg="look";
				gunEnd="eye";
				maxHorizontalRotSpeed=2.5999999;
				maxVerticalRotSpeed=2.5999999;
				initElev=0;
				minTurn=-180;
				maxTurn=180;
				initTurn=0;
				cameraDir="look";
				gunnerForceOptics=1;
				memoryPointGunnerOptics="eye";
				gunnerOpticsModel="\A3\Weapons_F_Mark\Reticle\optics_laserDesignator_02.p3d";
				turretInfoType="RscOptics_LaserDesignator_02";
				class ViewOptics: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.09375;
					minFov=0.017859999;
					maxFov=0.09375;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"TI"
					};
					thermalMode[]={2};
				};
			};
		};
		htMin=1;
		htMax=480;
		afMax=0;
		mfMax=0;
		mFact=1;
		tBody=100;
		class DestructionEffects
		{
			class Smoke
			{
				simulation="particles";
				type="WeaponWreckSmoke";
				position="destructionEffect";
				intensity=1;
				interval=1;
				lifeTime=5;
			};
		};
		model="\A3\Static_F_Mark\Designator_02\Designator_02_F";
		class assembleInfo
		{
			primary=0;
			base="";
			assembleTo[]={""};
			dissasembleTo="";
			displayName="";
		};
		class EventHandlers: EventHandlers
		{
			init="(_this select 0) execVM ""\A3\Static_F_Mark\Designator_02\Scripts\init.sqf""";
		};
		class AnimationSources: AnimationSources
		{
			class Init
			{
				source="user";
				animPeriod=0.5;
				initPhase=0;
			};
			class InitPiston
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
	};
	class DRNP_OPFOR_Static_Designator_02_F: Static_Designator_02_base_F
	{
		author="Pastoman1";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"mainturret",
					0
				},
				
				{
					"maingun",
					0
				},
				
				{
					"mainelevation_01",
					0
				},
				
				{
					"mainelevation_02",
					0
				},
				
				{
					"mainelevation_03",
					0
				},
				
				{
					"mainelevation_04",
					0
				},
				
				{
					"mainelevation_05",
					0
				},
				
				{
					"initturret",
					0
				},
				
				{
					"initgun",
					0
				},
				
				{
					"initelevation_01",
					0
				},
				
				{
					"initelevation_02",
					0
				},
				
				{
					"initelevation_03",
					0
				},
				
				{
					"initelevation_04",
					0
				},
				
				{
					"initelevation_05",
					0
				}
			};
			hide[]=
			{
				"light_back",
				"brzdove svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=0.47299999;
			verticalOffsetWorld=-0.001;
			init="''";
		};
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="main_turret_axis";
				class ACE_Pickup
				{
					selection="";
					displayName="Pickup remote designator";
					distance=5;
					condition="(alive _target)";
					statement="[_target,_player] call DRNP_fnc_pickup_RD";
					showDisabled=0;
					exceptions[]={};
					icon="\z\DRNP\addons\DRNP_main\UI\Icon_rd.paa";
				};
			};
		};
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
		editorPreview="\A3\EditorPreviews_F\Data\CfgVehicles\O_Static_Designator_02_F.jpg";
		_generalMacro="O_Static_Designator_02_F";
		scope=2;
		side=0;
		faction="OPF_F";
		crew="O_UAV_AI";
		displayname="Remote Designator (Portable)";
	};
};

class CfgWeapons
{
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;
	class DRNP_AR2P: ACE_ItemCore
	{
		author="Pastoman1";
		_generalMacro="DRNP_AR2P";
		scope=2;
		displayName="AR-2 (Portable)";
		descriptionShort="UAV";
		picture="\z\DRNP\addons\DRNP_main\UI\icon_dron.paa";
		magazines[]=
		{	
			"DRNP_AR2_battery"
		};
		model="\A3\Weapons_F\Items\Toolkit";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=30;
		};
	};
	class DRNP_AL6P: ACE_ItemCore
	{
		author="Pastoman1";
		_generalMacro="DRNP_AL6P";
		scope=2;
		displayName="AL-6 (Portable)";
		descriptionShort="UAV";
		picture="\z\DRNP\addons\DRNP_main\UI\Icon_AL6.paa";
		magazines[]=
		{
			"DRNP_AR2_battery"
		};
		model="\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=45;
		};
	};
	class DRNP_RD: ACE_ItemCore
	{
		author="Pastoman1";
		_generalMacro="DRNP_RD";
		scope=2;
		displayName="Remote Designator (Portable)";
		descriptionShort="RD";
		picture="\z\DRNP\addons\DRNP_main\UI\Icon_rd.paa";
		magazines[]=
		{
			"DRNP_AR2_battery"
		};
		model="\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=30;
		};
	};

	class DRNP_Drone_mines: ACE_ItemCore
	{
		author="Pastoman1";
		_generalMacro="DRNP_Drone_mines";
		scope=2;
		displayName="Drone EOD charges";
		descriptionShort="EOD charges";
		picture="\z\DRNP\addons\DRNP_main\UI\Icon_Charge.paa";
		model="\A3\Weapons_F\Items\Toolkit";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=60;
		};
	};
};