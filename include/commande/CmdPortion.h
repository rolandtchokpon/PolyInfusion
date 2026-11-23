
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
        virtual void redo(Machine::Systeme *sys) override;

    private:
        unsigned int anciennesPortions_ = 1;
        unsigned int nouvellesPortions_ = 1;
    };

} // namespace CMD
