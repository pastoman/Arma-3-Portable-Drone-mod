#include "script_component.hpp"

class CfgPatches {
	class main {
		author = "Pastoman1"; 
		units[] = {
			"DRNP_AR2",
		};
		weapons[] = {
			"DRNP_AR2P",
		};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"a3_drones_f",
			"ace_apl",
			"ace_interaction",
			"ace_spottingscope"
		};
	};
};

class CfgMods {
	class DRNP {
		logo = "\z\DRNP\addons\main\Data\UI\DRNP_logo.paa"; //Logo displayed in bottom left of main menu
		logoOver = "\z\DRNP\addons\main\Data\UI\DRNP_logo.paa"; //Logo displayed in the mod menu when mod icon is clicked
		logoSmall = "\z\DRNP\addons\main\Data\UI\DRNP_logo.paa"; //Logo displayed next to all units and vehicles in the editor
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
class DefaultVehicleSystemsDisplayManagerLeft {
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight {
	class components;
};

class Extended_Init_EventHandlers {
	class DRNP_AR2 {
		class DRNP_AR2P {
			init = "_this call ace_dragging_fnc_initObject";
		};
	};
};

class CBA_Extended_EventHandlers_base;
class CfgMagazines {	
	class CA_Magazine;
	class DRNP_AR2_battery: CA_Magazine {
		picture = "\z\DRNP\addons\main\UI\Icon_Batt.paa";
		author = "Pastoman1";
		scope = 2;
		displayName = "Portable drone battery";
		ammo = "Ar2_battery";
		count = 100;
	};
};

#include "CfgVehicles.hpp"

class CfgWeapons {
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;
	class DRNP_AR2P: ACE_ItemCore {
		author = "Pastoman1";
		_generalMacro = "DRNP_AR2P";
		scope = 2;
		displayName = "AR-2 (Portable)";
		descriptionShort = "UAV";
		picture = "\z\DRNP\addons\main\UI\icon_dron.paa";
		magazines[] = {	
			"DRNP_AR2_battery"
		};
		model = "\A3\Weapons_F\Items\Toolkit";
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 30;
		};
	};
	class DRNP_AL6P: ACE_ItemCore {
		author = "Pastoman1";
		_generalMacro = "DRNP_AL6P";
		scope = 2;
		displayName = "AL-6 (Portable)";
		descriptionShort = "UAV";
		picture = "\z\DRNP\addons\main\UI\Icon_AL6.paa";
		magazines[] = {
			"DRNP_AR2_battery"
		};
		model = "\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d";
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 45;
		};
	};
	class DRNP_RD: ACE_ItemCore {
		author = "Pastoman1";
		_generalMacro = "DRNP_RD";
		scope = 2;
		displayName = "Remote Designator (Portable)";
		descriptionShort = "RD";
		picture = "\z\DRNP\addons\main\UI\Icon_rd.paa";
		magazines[] = {
			"DRNP_AR2_battery"
		};
		model = "\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d";
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 30;
		};
	};

	class DRNP_Drone_mines: ACE_ItemCore {
		author = "Pastoman1";
		_generalMacro = "DRNP_Drone_mines";
		scope = 2;
		displayName = "Drone EOD charges";
		descriptionShort = "EOD charges";
		picture = "\z\DRNP\addons\main\UI\Icon_Charge.paa";
		model = "\A3\Weapons_F\Items\Toolkit";
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 60;
		};
	};
};
