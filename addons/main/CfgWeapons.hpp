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
