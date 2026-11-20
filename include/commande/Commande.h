
#pragma once
#include <iostream>
#include "../systeme/Systeme.h"
#include "../console/Console.h"

namespace CMD
{

    class Commande
    {
    public:
        virtual ~Commande() = 0;
        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) = 0;
        virtual void undo(Machine::Systeme *sys) = 0;

        const Console::Instruction &sauvgarde();
        bool estReversible() const;

    protected:
        Commande(bool estReversible);

        Console::Instruction instruction_;
        bool estReversible_;
    };

} // namespace Commande