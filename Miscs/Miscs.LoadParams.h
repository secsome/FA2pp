#pragma once

#include "../FA2PP.h"


namespace Miscs {
    namespace LoadParams {
        void LoadToCombobox(CComboBox* pComboBox, int nParamCode) {
            JMP_STD(0x43CE50);
        }

        void BuildingTypes(CComboBox* pComboBox, bool bDisplayAsName) {
            JMP_STD(0x43ED50);
        }

        void InfantryTypes(CComboBox* pComboBox) {
            JMP_STD(0x43F2C0);
        }

        void VehicleTypes(CComboBox* pComboBox) {
            JMP_STD(0x63F760);
        }

        void AircraftTypes(CComboBox* pComboBox) {
            JMP_STD(0x43FC00);
        }

        void TechnoTypes(CComboBox* pComboBox) {
            JMP_STD(0x4400A0);
        }

        void LocalVariables(CComboBox* pComboBox) {
            JMP_STD(0x441140);
        }

        void GlobalVariables(CComboBox* pComboBox) {
            JMP_STD(0x441530);
        }

        void TutorialTexts(CComboBox* pComboBox) {
            JMP_STD(0x441910);
        }

        void Triggers(CComboBox* pComboBox) {
            JMP_STD(0x441A40);
        }

        void YesNo(CComboBox* pComboBox) {
            JMP_STD(0x441E00);
        }

        void Sounds(CComboBox* pComboBox) {
            JMP_STD(0x441F20);
        }

        void Themes(CComboBox* pComboBox) {
            JMP_STD(0x442240);
        }

        void Speeches(CComboBox* pComboBox) {
            JMP_STD(0x442740);
        }

        void SuperWeaponTypes(CComboBox* pComboBox) {
            JMP_STD(0x442A60);
        }

        void Animations(CComboBox* pComboBox) {
            JMP_STD(0x442E50);
        }

        void Particles(CComboBox* pComboBox) {
            JMP_STD(0x443240);
        }

        void Movies(CComboBox* pComboBox, bool arg4, bool a3) {
            JMP_STD(0x443630);
        }

        void Movies(CComboBox* pComboBox, bool bShowIndex) {
            Movies(pComboBox, ~bShowIndex, bShowIndex);
        }

        void Houses(CComboBox* pComboBox,
            bool b1, bool b2, bool b3) {
            JMP_STD(0x4448F0);
        }

        void TeamTypes(CComboBox* pComboBox, bool bLeaveNone) {
            JMP_STD(0x445B30);
        }

        void Waypoints(CComboBox* pComboBox) {
            JMP_STD(0x446070);
        }
    }
}