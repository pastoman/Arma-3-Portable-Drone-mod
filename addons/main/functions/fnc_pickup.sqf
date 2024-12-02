#include "script_component.hpp"

params ["_dron", "_unit"];

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
	_unit playMove "Acts_TreatingWounded_loop";
};

private _uspech = {
	// adding drone to inventory
	(_this select 0) params ["_dron", "_unit"];
	[_unit, "DRNP_AR2P"] call ace_common_fnc_addToInventory;
	// getting drone fuel status
	private _fuelstatus = round ((fuel _dron) * 100);
	// removing drone
	deleteVehicle _dron;
	// adding battery to inventory with drone fuel status
	[_unit, "DRNP_AR2_battery", "", _fuelstatus] call ace_common_fnc_addToInventory;
};

[5, [_dron, _unit], _uspech, {Hint "Unable to pick up drone"}, "Retrieving drone"] call ace_common_fnc_progressBar;
