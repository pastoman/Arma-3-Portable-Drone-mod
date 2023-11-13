
#include "script_component.hpp"
params ["_dron", "_unit"];

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
    _unit playMove "Acts_TreatingWounded_loop";
};
	
private _uspech = {
	(_this select 0) params ["_dron"];
	private _fuelstatus = str (round ((fuel _dron) * 100));
	_Status = "Battery status: " + _fuelstatus + "%";
	Hint _Status;
	};
	
[5, [_dron], _uspech, {Hint "Unable to check drone battery"}, "Checking battery"] call ace_common_fnc_progressBar;
	