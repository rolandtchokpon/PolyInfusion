
#pragma once
#include "TypeInstruction.h"
#include <string>

namespace Console
{
    struct Instruction
    {
        TypeInstruction type = TypeInstruction::Vide;
        std::string the;
        std::string routine;
        unsigned int portions;
        double quantite = 0.0;
        bool notificationsActives = false;
        std::string erreur;
    };

} // namespace Console
