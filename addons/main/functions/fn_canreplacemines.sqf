
#include "script_component.hpp"
params ["_dron", "_unit"];
private _condition1 = !(isEngineOn _target) && alive _target;
private _condition2 = [_player, "DRNP_Drone_mines"] call BIS_fnc_hasItem;
private _retval = _condition1 && _condition2;
_retval;
	

	