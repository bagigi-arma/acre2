#include "script_component.hpp"
/*
 * Author: mrschick
 * Function to determine whether a SATCOM antenna has a clear LOS skywards.
 *
 * Arguments:
 * 0: SATCOM Antenna <OBJECT>
 *
 * Return Value:
 * TRUE if the antenna has a clear LOS, FALSE otherwise <BOOL>
 *
 * Example:
 * [placedAntenna] call acre_sys_signal_fnc_checkClearSkyLOS
 *
 * Public: No
 */

params ["_antenna"];

#define RF3080_ELEVATION 34

private _antPosASL = (getPosASL _antenna) vectorAdd [0, 0, 0.5]; // Offset 0.5m higher to better align with antenna

private _antDir = vectorNormalized (vectorDir _antenna); // Direction vector of the Antenna object, with Z being 0 since GSAs are always placed straight
_antDir set [2, (sin RF3080_ELEVATION)]; // Set the vector's Z value to correspond to the antenna's elevation

// Calculate a position 2km away in the antenna's direction
private _skyPosASL = _antPosASL vectorAdd (_antDir vectorMultiply 2000);

#ifdef DEBUG_MODE_FULL
    ANTPOS = ASLToAGL _antPosASL;
    SKYPOS = ASLToAGL _skyPosASL;
    onEachFrame {
        drawLine3D [ANTPOS, SKYPOS, [1, 0, 0, 1], 5];
    };
#endif

(lineIntersectsSurfaces [_antPosASL, _skyPosASL, _antenna]) isEqualTo []
