
#pragma once
#include "CmdReglage.h"

namespace CMD
{
    class CmdPortion : public CmdReglage
    {
    public:
        explicit CmdPortion(unsigned int portions);
        ~CmdPortion();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void redo(Machine::Systeme *sys) override;
        virtual std::string description() const override;
        virtual std::unique_ptr<IterateurReglage> creerIterateur() const override;
        virtual std::shared_ptr<CmdReglage> cloner() const override;

    private:
        unsigned int anciennesPortions_ = 1;
        unsigned int nouvellesPortions_;
    };

} // namespace CMD
