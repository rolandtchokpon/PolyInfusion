#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdReserve : public Commande
    {
    public:
        CmdReserve();
        ~CmdReserve();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande