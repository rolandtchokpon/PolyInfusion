#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdApercu : public Commande
    {
    public:
        CmdApercu();
        ~CmdApercu();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande