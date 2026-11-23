#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdQuit : public Commande
    {
    public:
        CmdQuit();
        ~CmdQuit();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande