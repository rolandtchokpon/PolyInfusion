#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdPortion : public Commande
    {
    public:
        CmdPortion();
        ~CmdPortion();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;

    private:
        int portionsAvant_ = -1;
    };

} // namespace Commande