
#include "script_component.hpp"
params ["_dron", "_unit"];

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
    _unit playMove "Acts_TreatingWounded_loop";
};
	
private _uspech = {
	(_this select 0) params ["_dron", "_unit"];
	private _fuelstatus = round ((fuel _dron) * 100);
	(_this select 0) params ["_dron", "_unit"];
	_unit addMagazine ["DRNP_AR2_battery", _fuelstatus];
	(_this select 0) params ["_dron", "_unit"];
	private _magazinesAmmo = magazinesAmmo _unit;
	private _sizeofarray = count _magazinesAmmo;
	private _droneammo = 0;
	private _pp = 0;
	private _totalammo = [0];
	
	for "_i" from 0 to _sizeofarray step 1 do {
		if ((_magazinesAmmo select _i) select 0 == "DRNP_AR2_battery") then {
			_droneammo = (_magazinesAmmo select _i) select 1; 
			_totalammo set [_pp, _droneammo];
			_pp = _pp + 1;
		};
	};
	
	_pp = _pp - 1;
	_totalammo sort false;
	private _batterystatus = (_totalammo select 0) / 100;
	(_this select 0) params ["_dron", "_unit"];
	_dron setFuel _batterystatus;
	(_this select 0) params ["_dron", "_unit"];
	_unit removeMagazines "DRNP_AR2_battery";
	_zostatok = [];
	if (_pp > 0) then {
		for "_i" from 1 to _pp step 1 do {
			_zostatok = _totalammo select _i;
			(_this select 0) params ["_dron", "_unit"];
			_unit addMagazine ["DRNP_AR2_battery", _zostatok];
		};
	};
};
	
[5, [_dron, _unit], _uspech, {Hint "Unable to replace drone battery"}, "Replacing battery"] call ace_common_fnc_progressBar;
	