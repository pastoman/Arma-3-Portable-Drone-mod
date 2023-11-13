

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



params ["_unit", "_dronItem"];
if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
    _unit playMove "Acts_TreatingWounded_loop";
};

private _uspech = {
	// removing drone from inventory
	(_this select 0) params ["_unit", "_dronItem"];
	_unit removeItem _dronItem;

	
    // prevent collision damage
    [QEGVAR(common,fixCollision), _unit] call CBA_fnc_localEvent;

	// finding position to place drone
    private _direction = getDir _unit;
    private _position = (getPosASL _unit) vectorAdd [0.8 * sin(_direction), 0.8 * cos(_direction), 0];
    private _vectorUp = [0, 0, 1];
    private _intersections = lineIntersectsSurfaces [_position vectorAdd [0, 0, 1.5], _position vectorDiff [0, 0, 1.5], _unit, objNull, true, 1, "GEOM", "FIRE"];
    if (_intersections isEqualTo []) then {
        TRACE_1("No intersections",_intersections);
    } else {
        (_intersections select 0) params ["_touchingPoint", "_surfaceNormal"];
        _position = _touchingPoint vectorAdd [0, 0, 0.05];
        _vectorUp = _surfaceNormal;
    };
	
	// placing drone
	(_this select 0) params ["_unit", "_dronItem"];
	private _condition = side _unit;
	private _dron;
	switch (_condition) do {
	case WEST: {
		_dron = "DRNP_AL6" createVehicle [0, 0, 0];
		createVehicleCrew _dron;
    _dron setDir _direction;
    _dron setPosASL _position;
    _dron setVectorUp _vectorUp;
    [QEGVAR(common,fixPosition), _dron, _dron] call CBA_fnc_targetEvent;
    [QEGVAR(common,fixFloating), _dron, _dron] call CBA_fnc_targetEvent;
	
	// setting drone fuel
	(_this select 0) params ["_unit", "_dronItem"];
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
	(_this select 0) params ["_unit", "_dronItem"];
	_dron setFuel _batterystatus;
	
	// managing player inventory
	(_this select 0) params ["_unit", "_dronItem"];
	_unit removeMagazines "DRNP_AR2_battery";
	_zostatok = [];
	
	if (_pp > 0) then {
	for "_i" from 1 to _pp step 1 do {
	_zostatok = _totalammo select _i;
	(_this select 0) params ["_unit", "_dronItem"];
	_unit addMagazine ["DRNP_AR2_battery", _zostatok];
	};
	};
	
	// finishing placement
	(_this select 0) params ["_unit", "_dronItem"];
    _unit reveal _dron;
	clearItemCargo _dron;
		};
	case EAST: {
		_dron = "DRNP_AL6_O" createVehicle [0, 0, 0];
		createVehicleCrew _dron;
    _dron setDir _direction;
    _dron setPosASL _position;
    _dron setVectorUp _vectorUp;
    [QEGVAR(common,fixPosition), _dron, _dron] call CBA_fnc_targetEvent;
    [QEGVAR(common,fixFloating), _dron, _dron] call CBA_fnc_targetEvent;
	
	// setting drone fuel
	(_this select 0) params ["_unit", "_dronItem"];
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
	(_this select 0) params ["_unit", "_dronItem"];
	_dron setFuel _batterystatus;
	
	// managing player inventory
	(_this select 0) params ["_unit", "_dronItem"];
	_unit removeMagazines "DRNP_AR2_battery";
	_zostatok = [];
	
	if (_pp > 0) then {
	for "_i" from 1 to _pp step 1 do {
	_zostatok = _totalammo select _i;
	(_this select 0) params ["_unit", "_dronItem"];
	_unit addMagazine ["DRNP_AR2_battery", _zostatok];
	};
	};
	
	// finishing placement
	(_this select 0) params ["_unit", "_dronItem"];
    _unit reveal _dron;
	clearItemCargo _dron;
		};
	default {
		_dron = "DRNP_AL6_I" createVehicle [0, 0, 0];
		createVehicleCrew _dron;
    _dron setDir _direction;
    _dron setPosASL _position;
    _dron setVectorUp _vectorUp;
    [QEGVAR(common,fixPosition), _dron, _dron] call CBA_fnc_targetEvent;
    [QEGVAR(common,fixFloating), _dron, _dron] call CBA_fnc_targetEvent;
	
	// setting drone fuel
	(_this select 0) params ["_unit", "_dronItem"];
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
	(_this select 0) params ["_unit", "_dronItem"];
	_dron setFuel _batterystatus;
	
	// managing player inventory
	(_this select 0) params ["_unit", "_dronItem"];
	_unit removeMagazines "DRNP_AR2_battery";
	_zostatok = [];
	
	if (_pp > 0) then {
	for "_i" from 1 to _pp step 1 do {
	_zostatok = _totalammo select _i;
	(_this select 0) params ["_unit", "_dronItem"];
	_unit addMagazine ["DRNP_AR2_battery", _zostatok];
	};
	};
	
	// finishing placement
	(_this select 0) params ["_unit", "_dronItem"];
	clearItemCargo _dron;
    _unit reveal _dron;
		};
	};
	};

[5, [_unit, _dronItem], _uspech, {Hint "Unable to place drone"}, "Placing drone"] call ace_common_fnc_progressBar;