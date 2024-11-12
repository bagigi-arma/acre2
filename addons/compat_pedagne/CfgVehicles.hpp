class CfgVehicles {
    // Cars
    class ASZ_VM90_EI;
    class ASZ_VM90spop: ASZ_VM90_EI {
        class AcreRacks {
            class Rack_1 {
                displayName = ECSTRING(sys_rack,dashUpper);
                shortName = ECSTRING(sys_rack,dashUpperShort);
                componentName = "ACRE_VRC110";
                allowedPositions[] = {"driver", "commander"};
                isRadioRemovable = 1;
                intercom[] = {"intercom_1"};
            };
            class Rack_2 {
                displayName = ECSTRING(sys_rack,dashLower);
                shortName = ECSTRING(sys_rack,dashLowerShort);
                componentName = "ACRE_VRC103";
                allowedPositions[] = {"driver", "commander"};
                mountedRadio = "ACRE_PRC117F";
                intercom[] = {"intercom_1"};
            };
        };
    };

    // MRAPs
    class ASZ_Car_Base;
    class ASZ_Cougar_6x6: ASZ_Car_Base {
        class AcreRacks {
            class Rack_1 {
                displayName = ECSTRING(sys_rack,dashUpper);
                shortName = ECSTRING(sys_rack,dashUpperShort);
                componentName = "ACRE_VRC110";
                allowedPositions[] = {"driver", {"turret", {0}}};
                isRadioRemovable = 1;
                intercom[] = {"intercom_1"};
            };
            class Rack_2 {
                displayName = ECSTRING(sys_rack,dashLower);
                shortName = ECSTRING(sys_rack,dashLowerShort);
                componentName = "ACRE_VRC103";
                allowedPositions[] = {"driver", {"turret", {0}}};
                mountedRadio = "ACRE_PRC117F";
                intercom[] = {"intercom_1"};
            };
        };
    };

    class ASZ_VTML_hitrole: ASZ_Car_Base {
        class AcreRacks {
            class Rack_1 {
                displayName = ECSTRING(sys_rack,dashUpper);
                shortName = ECSTRING(sys_rack,dashUpperShort);
                componentName = "ACRE_VRC110";
                allowedPositions[] = {{"turret", {0}}};
                isRadioRemovable = 1;
                intercom[] = {"intercom_1"};
            };
            class Rack_2 {
                displayName = ECSTRING(sys_rack,dashLower);
                shortName = ECSTRING(sys_rack,dashLowerShort);
                componentName = "ACRE_VRC103";
                allowedPositions[] = {{"turret", {0}}};
                mountedRadio = "ACRE_PRC117F";
                intercom[] = {"intercom_1"};
            };
        };
    };

    // AFVs
    class Tank;
    class ASZ_Tank: Tank {
        class AcreRacks {
            class Rack_1 {
                displayName = ECSTRING(sys_rack,dash);
                shortName = ECSTRING(sys_rack,dashShort);
                componentName = "ACRE_VRC103";
                allowedPositions[] = {"driver", "commander", "gunner"};
                mountedRadio = "ACRE_PRC117F";
                intercom[] = {"intercom_1"};
            };
        };
    };

    // Aircraft
    class ASZ_Helicopter;
    class ASZ_AB212_AM: ASZ_Helicopter {
        class AcreRacks {
            class Rack_1 {
                displayName = ECSTRING(sys_rack,dash);
                shortName = ECSTRING(sys_rack,dashShort);
                componentName = "ACRE_VRC103";
                allowedPositions[] = {"driver", {"turret", {0}}};
                mountedRadio = "ACRE_PRC117F";
            };
            class Rack_2: Rack_1 {
                displayName = ECSTRING(sys_rack,dash2);
                shortName = ECSTRING(sys_rack,dashShort);
            };
        };

        class AcreIntercoms {
            class Intercom_1 {
                displayName = ECSTRING(sys_intercom,crewIntercom);
                shortName = ECSTRING(sys_intercom,shortCrewIntercom);
                allowedPositions[] = {"crew"};
                limitedPositions[] = {{"cargo", "all"}, {"ffv", "all"}};
                masterPositions[] = {"driver", {"turret", {0}}};
                numLimitedPositions = 2;
                connectedByDefault = 1;
            };
            class Intercom_2: Intercom_1 {
                displayName = ECSTRING(sys_intercom,passengerIntercom);
                shortName = ECSTRING(sys_intercom,shortPassengerIntercom);
                allowedPositions[] = {"crew", {"cargo", "all"}, {"ffv", "all"}};
                limitedPositions[] = {};
                numLimitedPositions = 0;
                connectedByDefault = 0;
            };
        };
    };

    class ASZ_CH47_EI: ASZ_Helicopter {
        class AcreRacks {
            class Rack_1 {
                displayName = ECSTRING(sys_rack,dash);
                shortName = ECSTRING(sys_rack,dashShort);
                componentName = "ACRE_VRC103";
                allowedPositions[] = {"driver", {"turret", {0}}};
                mountedRadio = "ACRE_PRC117F";
            };
            class Rack_2: Rack_1 {
                displayName = ECSTRING(sys_rack,dash2);
                shortName = ECSTRING(sys_rack,dashShort);
            };
        };

        class AcreIntercoms {
            class Intercom_1 {
                displayName = ECSTRING(sys_intercom,crewIntercom);
                shortName = ECSTRING(sys_intercom,shortCrewIntercom);
                allowedPositions[] = {"crew"};
                limitedPositions[] = {{"cargo", "all"}, {"ffv", "all"}};
                masterPositions[] = {"driver", {"turret", {0}}};
                numLimitedPositions = 2;
                connectedByDefault = 1;
            };
            class Intercom_2: Intercom_1 {
                displayName = ECSTRING(sys_intercom,passengerIntercom);
                shortName = ECSTRING(sys_intercom,shortPassengerIntercom);
                allowedPositions[] = {"crew", {"cargo", "all"}, {"ffv", "all"}};
                limitedPositions[] = {};
                numLimitedPositions = 0;
                connectedByDefault = 0;
            };
        };
    };

    class ASZ_NH90_MM: ASZ_Helicopter {
        class AcreRacks {
            class Rack_1 {
                displayName = ECSTRING(sys_rack,dash);
                shortName = ECSTRING(sys_rack,dashShort);
                componentName = "ACRE_VRC103";
                allowedPositions[] = {"driver", {"turret", {0}}};
                mountedRadio = "ACRE_PRC117F";
            };
            class Rack_2: Rack_1 {
                displayName = ECSTRING(sys_rack,dash2);
                shortName = ECSTRING(sys_rack,dashShort);
            };
        };

        class AcreIntercoms {
            class Intercom_1 {
                displayName = ECSTRING(sys_intercom,crewIntercom);
                shortName = ECSTRING(sys_intercom,shortCrewIntercom);
                allowedPositions[] = {"crew"};
                limitedPositions[] = {{"cargo", "all"}, {"ffv", "all"}};
                masterPositions[] = {"driver", {"turret", {0}}};
                numLimitedPositions = 2;
                connectedByDefault = 1;
            };
            class Intercom_2: Intercom_1 {
                displayName = ECSTRING(sys_intercom,passengerIntercom);
                shortName = ECSTRING(sys_intercom,shortPassengerIntercom);
                allowedPositions[] = {"crew", {"cargo", "all"}, {"ffv", "all"}};
                limitedPositions[] = {};
                numLimitedPositions = 0;
                connectedByDefault = 0;
            };
        };
    };

    class ASZ_EH101_MM: ASZ_Helicopter {
        class AcreIntercoms {
            class Intercom_1 {
                displayName = ECSTRING(sys_intercom,crewIntercom);
                shortName = ECSTRING(sys_intercom,shortCrewIntercom);
                allowedPositions[] = {"crew"};
                limitedPositions[] = {{"cargo", "all"}};
                masterPositions[] = {"driver", "gunner"};
                numLimitedPositions = 2;
                connectedByDefault = 1;
            };
            class Intercom_2: Intercom_1 {
                displayName = ECSTRING(sys_intercom,passengerIntercom);
                shortName = ECSTRING(sys_intercom,shortPassengerIntercom);
                allowedPositions[] = {"crew", {"cargo", "all"}};
                limitedPositions[] = {};
                numLimitedPositions = 0;
                connectedByDefault = 0;
            };
        };
    };

    class Plane;
    class DDL_C27J_AM: Plane {
        class AcreRacks {
            class Rack_1 {
                displayName = ECSTRING(sys_rack,dash);
                shortName = ECSTRING(sys_rack,dashShort);
                componentName = "ACRE_VRC103";
                allowedPositions[] = {"driver", "gunner"};
                mountedRadio = "ACRE_PRC117F";
            };
            class Rack_2: Rack_1 {
                displayName = ECSTRING(sys_rack,dash2);
                shortName = ECSTRING(sys_rack,dashShort);
            };
        };

        class AcreIntercoms {
            class Intercom_1 {
                displayName = ECSTRING(sys_intercom,crewIntercom);
                shortName = ECSTRING(sys_intercom,shortCrewIntercom);
                allowedPositions[] = {"crew"};
                limitedPositions[] = {{"cargo", "all"}};
                masterPositions[] = {"driver", "gunner"};
                numLimitedPositions = 2;
                connectedByDefault = 1;
            };
            class Intercom_2: Intercom_1 {
                displayName = ECSTRING(sys_intercom,passengerIntercom);
                shortName = ECSTRING(sys_intercom,shortPassengerIntercom);
                allowedPositions[] = {"crew", {"cargo", "all"}};
                limitedPositions[] = {};
                numLimitedPositions = 0;
                connectedByDefault = 0;
            };
        };
    };

    class ASZ_C130J: Plane {
        class AcreRacks {
            class Rack_1 {
                displayName = ECSTRING(sys_rack,dash);
                shortName = ECSTRING(sys_rack,dashShort);
                componentName = "ACRE_VRC103";
                allowedPositions[] = {"driver", "gunner"};
                mountedRadio = "ACRE_PRC117F";
            };
            class Rack_2: Rack_1 {
                displayName = ECSTRING(sys_rack,dash2);
                shortName = ECSTRING(sys_rack,dashShort);
            };
        };

        class AcreIntercoms {
            class Intercom_1 {
                displayName = ECSTRING(sys_intercom,crewIntercom);
                shortName = ECSTRING(sys_intercom,shortCrewIntercom);
                allowedPositions[] = {"crew"};
                limitedPositions[] = {{"cargo", "all"}};
                masterPositions[] = {"driver", "gunner"};
                numLimitedPositions = 2;
                connectedByDefault = 1;
            };
            class Intercom_2: Intercom_1 {
                displayName = ECSTRING(sys_intercom,passengerIntercom);
                shortName = ECSTRING(sys_intercom,shortPassengerIntercom);
                allowedPositions[] = {"crew", {"cargo", "all"}};
                limitedPositions[] = {};
                numLimitedPositions = 0;
                connectedByDefault = 0;
            };
        };
    };
};
