#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

[] call FUNC(preset_information);

ADDON = true;

if (hasInterface) then {
    GVAR(currentRadioId) = -1;

    DGVAR(backgroundImages) = [];
};

ADDON = true;
