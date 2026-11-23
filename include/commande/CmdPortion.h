
#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdPortion : public Commande
    {
    public:
        explicit CmdPortion(unsigned int portions);
        ~CmdPortion();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void redo(Machine::Systeme *sys) override;
        virtual void apercu(std::vector<std::string> &lignes) const override;
        virtual std::shared_ptr<Commande> cloner() const override;

    private:
        unsigned int anciennesPortions_ = 1;
        unsigned int nouvellesPortions_;
    };

} // namespace CMD
