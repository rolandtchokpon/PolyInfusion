#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdNotif : public Commande
    {
    public:
        CmdNotif();
        ~CmdNotif();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande