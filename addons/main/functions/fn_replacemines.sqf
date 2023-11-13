
#include "script_component.hpp"
params ["_dron", "_unit"];

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
    _unit playMove "Acts_TreatingWounded_loop";
};
	
private _uspech = {
	(_this select 0) params ["_dron", "_unit"];
	_dron setAmmoOnPylon ["pylons1", 4];
	_unit removeItem "DRNP_Drone_mines";
	};
[5, [_dron, _unit], _uspech, {Hint "Unable to replace charges"}, "Replacing charges"] call ace_common_fnc_progressBar;
	