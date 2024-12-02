#include "script_component.hpp"

params ["_dron", "_unit"];

private _condition1 = alive _dron && !(isEngineOn _dron);
private _condition2 = [_unit, "DRNP_Drone_mines"] call ace_common_fnc_hasItem;

_condition1 && _condition2
