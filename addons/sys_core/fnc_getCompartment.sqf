#include "script_component.hpp"
/*
 * Author: ACRE2Team
 * Retrieves the compartment where the specified unit finds itself (driver, turret,...).
 * Relevant for signal attenuating purposes.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Compartment where the unit finds itself <STRING>. (default: "" if the unit is not inside a vehicle, "Compartment1" otherwise)
 *
 * Example:
 * [player] call acre_sys_core_fnc_getCompartment
 *
 * Public: No
 */

params ["_unit"];
private _vehicle = vehicle _unit;
private _compartment = "";
private _defaultCompartment = "";

if (_vehicle != _unit) then {
    private _defaultCompartment = "Compartment1";
    private _cfg = configOf _vehicle;
    private _roleType = [_unit] call CBA_fnc_vehicleRole;
    if (_roleType == "driver") then {
        _compartment = getText (_cfg >> "driverCompartments");
        if (_compartment == "") then {
            _compartment = _defaultCompartment;
        };
    } else {
        if (_roleType in ["gunner", "commander", "turret"]) then {
            private _turretPath = _vehicle unitTurret _unit;
            private _turret = [_vehicle, _turretPath] call CBA_fnc_getTurret;
            _compartment = getText (_turret >> "gunnerCompartments");
            if (_compartment == "") then {
                _compartment = getText (_cfg >> "driverCompartments");
                if (_compartment == "") then {
                    _compartment = _defaultCompartment;
                };
            };
        } else {
            if (_roleType == "cargo") then {
                private _cargoCompartments = getArray (_cfg >> "cargoCompartments");
                if (_cargoCompartments isNotEqualTo []) then {
                    private _index = _vehicle getCargoIndex _unit;
                    if (_index > -1) then {
                        private _cargoCompartmentsMaxCount = (count _cargoCompartments) - 1;
                        if (_index > _cargoCompartmentsMaxCount) then {
                            _index = _cargoCompartmentsMaxCount;
                        };

                        _compartment = _cargoCompartments select _index;
                    } else {
                        _compartment = _defaultCompartment;
                    };
                } else {
                    _compartment = _defaultCompartment;
                };
            };
        };
    };
};
if !(_compartment isEqualType "") then {
    _compartment = _defaultCompartment;
};
_compartment;
