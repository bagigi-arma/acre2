#include "script_component.hpp"
/*
 * Author: mrschick
 * Verifies the SATCOM antenna's alignment and notifies the player running the interaction of it.
 *
 * Arguments:
 * 0: SATCOM Antenna <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [antenna] call acre_sys_gsa_fnc_checkSatcomConnection
 *
 * Public: No
 */

params ["_antenna"];

private _msg = ["No signal to/from Satellite", "Good Satellite Link"] select ([_antenna] call EFUNC(sys_signal,checkClearSkyLOS));

[_msg] call CBA_fnc_notify;
