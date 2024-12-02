#include "script_component.hpp"

params ["_dron", "_unit"];

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
	_unit playMove "Acts_TreatingWounded_loop";
};

private _uspech = {
	// adding drone to inventory
	(_this select 0) params ["_dron", "_unit"];
	[_unit, "DRNP_AL6P"] call ace_common_fnc_addToInventory;
	// getting drone fuel status
	private _fuelstatus = round ((fuel _dron) * 100);
	// removing drone
	deleteVehicle _dron;
	// adding battery to inventory with drone fuel status
	[_unit, "DRNP_AR2_battery", "", _fuelstatus] call ace_common_fnc_addToInventory;
	// adding items from drone to inventory
	private _magazinesCargo = magazinesAmmoCargo vehicle _dron;
	private _itemCargo = getItemCargo _dron;
	private _magazinesNumber = count _magazinesCargo;
	private _itemNumber = count (_itemCargo select 0);
	for "_i" from 0 to (_magazinesNumber - 1) step 1 do { 
		[_unit, (_magazinesCargo select _i) select 0, "", (_magazinesCargo select _i) select 1] call ace_common_fnc_addToInventory;
 	};
	for "_i" from 0 to (_itemNumber - 1) step 1 do {   
		for "_j" from 0 to ((_itemCargo select 1) select _i) - 1 step 1 do { 
			[_unit, (_itemCargo select 0) select _i, ""] call ace_common_fnc_addToInventory;
  		}; 
 	};
};

[5, [_dron, _unit], _uspech, {Hint "Unable to pick up drone"}, "Retrieving drone"] call ace_common_fnc_progressBar;
