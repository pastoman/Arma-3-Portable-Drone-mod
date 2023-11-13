#include "script_component.hpp"

#define POS_X_BASE(size) safezoneX + 0.5 * safezoneW - 0.5 * (size) / (getResolution select 5)
#define POS_Y_BASE(size) safezoneY + 0.5 * safezoneH - 0.5 * (size) / (getResolution select 5) * 4/3
#define POS_W_BASE(size) (size) / (getResolution select 5)
#define POS_H_BASE(size) (size) / (getResolution select 5) * 4/3

#define SIZEX 1.05

#define POS_X QUOTE(POS_X_BASE(SIZEX))
#define POS_Y QUOTE(POS_Y_BASE(SIZEX))
#define POS_W QUOTE(POS_W_BASE(SIZEX))
#define POS_H QUOTE(POS_H_BASE(SIZEX))


params ["_dron", "_unit"];

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
    _unit playMove "Acts_TreatingWounded_loop";
};

private _uspech = {
	// adding drone to inventory
	(_this select 0) params ["_dron", "_unit"];
	[_unit, "DRNP_Drone_EODP"] call ace_common_fnc_addToInventory;
	// getting drone fuel status
	(_this select 0) params ["_dron", "_unit"];
	private _fuelstatus = round ((fuel _dron) * 100);
	// removing drone
	(_this select 0) params ["_dron", "_unit"];
	deleteVehicle _dron;
	// adding battery to inventory with drone fuel status
	(_this select 0) params ["_dron", "_unit"];
	[_unit, "DRNP_AR2_battery", "", _fuelstatus] call ace_common_fnc_addToInventory;
};

[5, [_dron, _unit], _uspech, {Hint "Unable to pick up drone"}, "Retrieving drone"] call ace_common_fnc_progressBar;

