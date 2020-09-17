#pragma once

#include "FA2PP.h"
#include "CINI.h"

#include "Helpers/CompileTime.h"

class GlobalVars
{
public:
    static constexpr reference<char*, 0x72A738, 260> const ExePath{}; // Where FA2.exe locates
    static constexpr reference<char*, 0x72A530, 260> const MapPath{}; // Where current map locates 
    static constexpr reference<char*, 0x72A634, 260> const FilePath{}; // Where mix files locates
    
    class INIFiles
    {
    public:
        static constexpr reference<INIClass, 0x7EDDDC> const Rules{}; // rulesmd.ini / rules.ini
        static constexpr reference<INIClass, 0x7EDCAC> const Art{}; // artmd.ini / art.ini
        static constexpr reference<INIClass, 0x7ED964> const Turtorial{}; // turtorial.ini
        static constexpr reference<INIClass, 0x7EDA7C> const Sound{}; // soundmd.ini / sound.ini
        static constexpr reference<INIClass, 0x7ED84C> const Eva{}; // evamd.ini / eva.ini
        static constexpr reference<INIClass, 0x7ED734> const Theme{}; // thememd.ini / theme.ini
        static constexpr reference<INIClass, 0x7EDB94> const Ai{}; // aimd.ini / ai.ini
        static constexpr reference<INIClass, 0x7ED3EC> const Temperat{}; // temperatmd.ini / temperat.ini
        static constexpr reference<INIClass, 0x7ED2D4> const Snow{}; // snowmd.ini / snow.ini
        static constexpr reference<INIClass, 0x7ED1BC> const Urban{}; // urbanmd.ini / urban.ini
        static constexpr reference<INIClass, 0x7ED0A4> const UrbanN{}; // urbannmd.ini
        static constexpr reference<INIClass, 0x7ECF8C> const Lunar{}; // lunarmd.ini
        static constexpr reference<INIClass, 0x7ECE74> const Desert{}; // desertmd.ini
        static constexpr reference<INIClass, 0x7ED61C> const FAData{}; // FAData.ini
        static constexpr reference<INIClass, 0x7ED504> const FALanguage{}; // FALanguage.ini

        // This one needs a function to parse it
    private:
        struct FinalAlertHandlerCDialog : FA2CDialog
        {
            INIClass* GetInstance() { JMP_THIS(0x49C260); }
        };
        static constexpr reference<FinalAlertHandlerCDialog, 0x72CBF8> const FinalAlertHandle{}; 
    public:
        static INIClass* FinalAlert() {// FinalAlert.ini 
            return INIFiles::FinalAlertHandle.get().GetInstance();
        }

    };


};