#pragma once

#include "../FA2PP.h"


class Miscs {
public:
    class LoadParams {
    public:
        void __cdecl LoadToCombobox(ppmfc::CComboBox* pComboBox, int nParamCode) {
            JMP_STD(0x43CE50);
        }

        void __cdecl BuildingTypes(ppmfc::CComboBox* pComboBox, bool bDisplayAsName) {
            JMP_STD(0x43ED50);
        }

        void __cdecl InfantryTypes(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x43F2C0);
        }

        void __cdecl VehicleTypes(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x63F760);
        }

        void __cdecl AircraftTypes(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x43FC00);
        }

        void __cdecl TechnoTypes(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x4400A0);
        }

        void __cdecl LocalVariables(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x441140);
        }

        void __cdecl GlobalVariables(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x441530);
        }

        void __cdecl TutorialTexts(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x441910);
        }

        void __cdecl Triggers(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x441A40);
        }

        void __cdecl YesNo(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x441E00);
        }

        void __cdecl Sounds(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x441F20);
        }

        void __cdecl Themes(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x442240);
        }

        void __cdecl Speeches(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x442740);
        }

        void __cdecl SuperWeaponTypes(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x442A60);
        }

        void __cdecl Animations(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x442E50);
        }

        void __cdecl Particles(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x443240);
        }

        void __cdecl Movies(ppmfc::CComboBox* pComboBox, bool arg4, bool a3) {
            JMP_STD(0x443630);
        }

        void __cdecl Houses(ppmfc::CComboBox* pComboBox, bool b1, bool b2, bool b3) {
            JMP_STD(0x4448F0);
        }

        void __cdecl TeamTypes(ppmfc::CComboBox* pComboBox, bool bLeaveNone) {
            JMP_STD(0x445B30);
        }

        void __cdecl Waypoints(ppmfc::CComboBox* pComboBox) {
            JMP_STD(0x446070);
        }
    };
};