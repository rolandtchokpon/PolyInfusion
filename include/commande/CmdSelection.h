
#pragma once
#include <string>
#include "Commande.h"

namespace CMD
{
    class CmdSelection : public Commande
    {
    public:
        explicit CmdSelection(const std::string &the);
        ~CmdSelection();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void redo(Machine::Systeme *sys) override;
        virtual void apercu(std::vector<std::string> &lignes) const override;
        virtual std::shared_ptr<Commande> cloner() const override;

    private:
        std::string ancienThe_;
        std::string nouveauThe_;
    };

} // namespace CMD
