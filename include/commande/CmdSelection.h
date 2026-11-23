
#pragma once
#include <string>
#include "Commande.h"

namespace CMD
{
    class CmdSelection : public Commande
    {
    public:
        CmdSelection();
        ~CmdSelection();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void redo(Machine::Systeme *sys) override;

    private:
        std::string ancienThe_;
        std::string nouveauThe_;
    };

} // namespace CMD
