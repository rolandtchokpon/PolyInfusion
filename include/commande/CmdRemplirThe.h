#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdRemplirThe : public Commande
    {
    public:
        CmdRemplirThe();
        ~CmdRemplirThe();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande