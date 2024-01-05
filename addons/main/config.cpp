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

#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
