#include "script_component.hpp"
/*
 * Author: ACRE2Team
 * Handles entering a vehicle.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Unit entering a vehicle <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorTarget, player] call acre_sys_intercom_fnc_enterVehicle
 *
 * Public: No
 */

params ["_vehicle", "_unit"];
TRACE_2("enterVehicle",_vehicle,_unit);

(_unit getVariable [QGVAR(vehicleInfantryPhone), [objNull, INTERCOM_DISCONNECTED]]) params ["_vehicleInfantryPhone", "_infantryPhoneNetwork"];
if (!isNull _vehicleInfantryPhone) then {
    // Disconnect infantry phone
    [_vehicleInfantryPhone, _unit, 0, _infantryPhoneNetwork] call FUNC(updateInfantryPhoneStatus);
};

if ((_unit == _vehicle) || {GVAR(intercomPFH) > -1}) then {
    [GVAR(intercomPFH)] call CBA_fnc_removePerFrameHandler;
    TRACE_1("del intercom PFH",GVAR(intercomPFH));
    GVAR(intercomPFH) = -1;

    private _oldVehicle = _unit getVariable [QGVAR(intercomVehicle), objNull];

    // Handle the case of broadcasting or using a seat that uses limited connections
    [_oldVehicle, _unit] call FUNC(seatSwitched);

    // Reset variables
    _unit setVariable [QGVAR(intercomVehicle), objNull];
    _unit setVariable [QGVAR(role), ""];
    ACRE_PLAYER_INTERCOM = [];
    GVAR(intercomUse) = [];
};

if (_unit != _vehicle) then {
    // Save current seat variable
    private _varName = [_vehicle, _unit] call FUNC(getStationVariableName);

    // Save vehicle
    _unit setVariable [QGVAR(intercomVehicle), _vehicle];

    [_vehicle, _unit] call FUNC(seatSwitched);

    // Start PFH
    GVAR(intercomPFH) = [DFUNC(intercomPFH), 1, [_unit, _vehicle]] call CBA_fnc_addPerFrameHandler;
    TRACE_1("add intercom PFH",GVAR(intercomPFH));
};
